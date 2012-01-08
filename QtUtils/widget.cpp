#include <QDebug>
#include <QDir>
#include <QPoint>
#include <QMenu>
#include <QAction>
#include <QPluginLoader>
#include "widget.h"
#include "UtilInterface.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    contextMenu = NULL;
    this->init();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::init(){
    contextMenu = NULL;
    loadPlugins();






}
void Widget::pluginChange(bool check){
    QAction* ori = qobject_cast<QAction*>(QObject::sender());
    QString name = ori->text();

    if(check){
        QString filepath = ori->data().toString();
        QPluginLoader pluginLoader(filepath);
        QObject* instance = pluginLoader.instance();
        if(instance){
            UtilInterface* plugin=qobject_cast<UtilInterface*>(instance);
            if(plugin){
                ui->tabWidget->addTab(plugin->load(),name);
                enabled.insert(name,filepath);
            }
        }

    }else{
        int cc =  ui->tabWidget->count();
        for(int i=0;i<cc;i++){
            if(ui->tabWidget->tabText(i)==name){
                QWidget* tt=ui->tabWidget->widget(i);
                enabled.remove(name);
                delete tt;
                ui->tabWidget->removeTab(i);
                break;
            }
        }
    }
}
void Widget::loadPlugins(){
    availabel.clear();
    QDir pluginsDir(qApp->applicationDirPath());
#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif
    pluginsDir.cd("plugins");
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        qDebug()<<pluginsDir.absoluteFilePath(fileName);
        if (plugin) {
           UtilInterface* instance = qobject_cast<UtilInterface *>(plugin);
            if (instance){
                availabel.insert(instance->getName(),pluginsDir.absoluteFilePath(fileName));

                //ui->tabWidget->addTab(instance->load(),instance->getName());
                delete instance;

            }

        }
    }
    createMenu();


}
void Widget::createMenu(){
    if(contextMenu)
        delete contextMenu;
    contextMenu =  new QMenu(this);
    contextMenu->addAction(tr("refresh"),this,SLOT(init()));
    QMenu* sub = contextMenu->addMenu(tr("Default"));
    QAction* act;

    foreach(QString item,availabel.keys()){
        act =  new QAction(item,sub);
        act->setData(availabel.value(item));
        act->setCheckable(true);
        if(enabled.find(item)!=enabled.end())
            act->setChecked(true);
        connect(act,SIGNAL(triggered(bool)),SLOT(pluginChange(bool)));
        sub->addAction(act);

    }
}
void Widget::on_tabWidget_customContextMenuRequested(const QPoint &pos)
{
    qDebug()<<"context menu";
    contextMenu->move(this->mapToGlobal(pos));
    contextMenu->show();
}


