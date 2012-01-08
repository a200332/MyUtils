#ifndef MYMD5_H
#define MYMD5_H

#include <QObject>
#include "UtilInterface.h"
class MyMD5 : public QObject,UtilInterface
{
    Q_OBJECT
    Q_INTERFACES(UtilInterface)
public:
    QWidget* load();
    QString getName();

signals:

public slots:

};

#endif // MYMD5_H
