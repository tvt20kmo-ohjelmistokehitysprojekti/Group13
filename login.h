#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    bool parseResult(QString user, QString pin);

private slots:
    void on_btnLogin_clicked();

private:
    Ui::login *ui;

};

#endif // LOGIN_H
