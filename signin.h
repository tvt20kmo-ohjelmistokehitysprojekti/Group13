#ifndef SIGNIN_H
#define SIGNIN_H
#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValueIterator>
#include <iostream>
#include <string>
#include <QDebug>

namespace Ui {
class signin;
}

class signin : public QWidget
{
    Q_OBJECT
signals:
    void sendData(QString);

public:
    explicit signin(QWidget *parent = nullptr);
    ~signin();
    bool parseResult(QString user, QString pin);

private slots:
    void on_btnLogin_clicked();

private:
    Ui::signin *ui;

};

#endif // SIGNIN_H
