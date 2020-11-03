#ifndef SIGNIN_H
#define SIGNIN_H
#include "dbconnect.h"
#include <QWidget>

namespace Ui {
class signin;
}

class signin : public QWidget
{
    Q_OBJECT

public:
    explicit signin(QWidget *parent = nullptr);
    ~signin();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::signin *ui;
    dbConnect *db = new dbConnect;
};

#endif // SIGNIN_H
