#include <QCryptographicHash>
#include <QFile>
#include <QFileDialog>
#include "md5form.h"
#include "ui_md5form.h"

MD5Form::MD5Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MD5Form)
{
    ui->setupUi(this);
}

MD5Form::~MD5Form()
{
    delete ui;
}

void MD5Form::on_textCalc_clicked()
{
    QCryptographicHash md5(QCryptographicHash::Md5);
    md5.addData(ui->textSrc->text().toLocal8Bit());
    ui->textResult->setText(md5.result().toHex());
}

void MD5Form::on_fileCalc_clicked()
{
    QString fn = ui->fileSrc->text();
    bool check = true;
    check = !fn.isEmpty();
    QFile file(fn);
    QCryptographicHash md5(QCryptographicHash::Md5);
    if(check&& file.open(QIODevice::ReadOnly)){
        md5.addData(file.readAll());
        ui->fileResult->setText(md5.result().toHex());
    }
    file.close();
}

void MD5Form::on_toolButton_clicked()
{
    QString fn = QFileDialog::getOpenFileName();
    if(!fn.isEmpty())
        ui->fileSrc->setText(fn);
}
