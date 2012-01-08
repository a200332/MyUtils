#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHash>
namespace Ui {
    class Widget;
}
class QMenu;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void loadPlugins();

    void init();
    void pluginChange(bool);
private slots:


    void on_tabWidget_customContextMenuRequested(const QPoint &pos);
private:
    void createMenu();
    Ui::Widget *ui;
    QStringList pools;
    QMenu* contextMenu;
    QHash<QString,QString> availabel;
    QHash<QString,QString> enabled;
    QHash<QString,QString> failed;
};

#endif // WIDGET_H
