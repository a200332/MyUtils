#ifndef UTILINTERFACE_H
#define UTILINTERFACE_H

#include <QString>
#include <QWidget>
class UtilInterface{
public:
    virtual ~UtilInterface() {}
    virtual QWidget* load() = 0;
    virtual QString getName() = 0;
};
QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(UtilInterface,
                    "myDemo.UtilHello/1.0");
QT_END_NAMESPACE

#endif // UTILINTERFACE_H
