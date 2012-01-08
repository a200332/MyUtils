#include "qplugin.h"
#include "mymd5.h"
#include "md5form.h"
QWidget* MyMD5::load(){
    return new MD5Form();
}
QString MyMD5::getName(){
    return "MD5/Gen";
}
Q_EXPORT_PLUGIN2(MD5, MyMD5);
