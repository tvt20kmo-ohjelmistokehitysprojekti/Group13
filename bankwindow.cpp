#include "bankwindow.h"
#include "ui_bankwindow.h"

#include <QNetworkReply>


bankwindow::bankwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bankwindow)
{
    ui->setupUi(this);

}

bankwindow::~bankwindow()
{
    delete ui;
}

void bankwindow::on_lblWithdraw20_clicked()
{
    int t_amount = 20;
    QString balance;

    QNetworkAccessManager networkManager;
    QUrl url("http://localhost/API/index.php/api/Login/check_login/?Korttinumero=");
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(url);

    // get account balance
    QNetworkReply *currentReply = networkManager.get(request);

    while (!currentReply->isFinished()){
        qApp->processEvents();
    }

    QByteArray currentResponse = currentReply->readAll();
    qDebug() << "Response: " +currentResponse;

    int t_balance = currentResponse.toInt();

    if (t_balance >= t_amount){
        int newBalance = t_balance-t_amount;
        ui->lblMessage->setText("Nostettu 20€");

        // withdraw amount
        QNetworkAccessManager networkManager;
        QUrl url("http://localhost/API/index.php/api/Login/check_login/?Korttinumero=");
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setUrl(url);

        QJsonObject json;
        json.insert("Saldo", newBalance);

        QNetworkReply *reply = networkManager.post(request, QJsonDocument(json).toJson());

        while (!reply->isFinished()){
            qApp->processEvents();
        }

        QByteArray currentResponse = currentReply->readAll();
        qDebug() << "Response: " +currentResponse;
    }
    else{
        ui->lblMessage->setText("Saldo ei riitä!");
    }

}

void bankwindow::on_lblWithdraw40_clicked()
{
    int t_amount = 40;
    QString balance;

    QNetworkAccessManager networkManager;
    QUrl url("http://localhost/API/index.php/api/Login/check_login/?Korttinumero=");
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(url);

    // get account balance
    QNetworkReply *currentReply = networkManager.get(request);

    while (!currentReply->isFinished()){
        qApp->processEvents();
    }

    QByteArray currentResponse = currentReply->readAll();
    qDebug() << "Response: " +currentResponse;

    int t_balance = currentResponse.toInt();

    if (t_balance >= t_amount){
        int newBalance = t_balance-t_amount;
        ui->lblMessage->setText("Nostettu 40€");

        // withdraw amount
        QNetworkAccessManager networkManager;
        QUrl url("http://localhost/API/index.php/api/Login/check_login/?Korttinumero=");
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setUrl(url);

        QJsonObject json;
        json.insert("Saldo", newBalance);

        QNetworkReply *reply = networkManager.post(request, QJsonDocument(json).toJson());

        while (!reply->isFinished()){
            qApp->processEvents();
        }

        QByteArray currentResponse = currentReply->readAll();
        qDebug() << "Response: " +currentResponse;
    }
    else{
        ui->lblMessage->setText("Saldo ei riitä!");
    }

}

void bankwindow::on_lblWithdraw50_clicked()
{
    int t_amount = 50;
    QString balance;

    QNetworkAccessManager networkManager;
    QUrl url("http://localhost/API/index.php/api/Login/check_login/?Korttinumero=");
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(url);

    // get account balance
    QNetworkReply *currentReply = networkManager.get(request);

    while (!currentReply->isFinished()){
        qApp->processEvents();
    }

    QByteArray currentResponse = currentReply->readAll();
    qDebug() << "Response: " +currentResponse;

    int t_balance = currentResponse.toInt();

    if (t_balance >= t_amount){
        int newBalance = t_balance-t_amount;
        ui->lblMessage->setText("Nostettu 50€");

        // withdraw amount
        QNetworkAccessManager networkManager;
        QUrl url("http://localhost/API/index.php/api/Login/check_login/?Korttinumero=");
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setUrl(url);

        QJsonObject json;
        json.insert("Saldo", newBalance);

        QNetworkReply *reply = networkManager.post(request, QJsonDocument(json).toJson());

        while (!reply->isFinished()){
            qApp->processEvents();
        }

        QByteArray currentResponse = currentReply->readAll();
        qDebug() << "Response: " +currentResponse;
    }
    else{
        ui->lblMessage->setText("Saldo ei riitä!");
    }

}

void bankwindow::on_lblWithdraw100_clicked()
{
    int t_amount = 50;
    QString balance;

    QNetworkAccessManager networkManager;
    QUrl url("http://localhost/API/index.php/api/Login/check_login/?Korttinumero=");
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(url);

    // get account balance
    QNetworkReply *currentReply = networkManager.get(request);

    while (!currentReply->isFinished()){
        qApp->processEvents();
    }

    QByteArray currentResponse = currentReply->readAll();
    qDebug() << "Response: " +currentResponse;

    int t_balance = currentResponse.toInt();

    if (t_balance >= t_amount){
        int newBalance = t_balance-t_amount;
        ui->lblMessage->setText("Nostettu 50€");

        // withdraw amount
        QNetworkAccessManager networkManager;
        QUrl url("http://localhost/API/index.php/api/Login/check_login/?Korttinumero=");
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setUrl(url);

        QJsonObject json;
        json.insert("Saldo", newBalance);

        QNetworkReply *reply = networkManager.post(request, QJsonDocument(json).toJson());

        while (!reply->isFinished()){
            qApp->processEvents();
        }

        QByteArray currentResponse = currentReply->readAll();
        qDebug() << "Response: " +currentResponse;
    }
    else{
        ui->lblMessage->setText("Saldo ei riitä!");
    }

}
