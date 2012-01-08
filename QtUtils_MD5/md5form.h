#ifndef MD5FORM_H
#define MD5FORM_H

#include <QWidget>

namespace Ui {
    class MD5Form;
}

class MD5Form : public QWidget
{
    Q_OBJECT

public:
    explicit MD5Form(QWidget *parent = 0);
    ~MD5Form();

private slots:
    void on_textCalc_clicked();

    void on_fileCalc_clicked();

    void on_toolButton_clicked();

private:
    Ui::MD5Form *ui;
};

#endif // MD5FORM_H
