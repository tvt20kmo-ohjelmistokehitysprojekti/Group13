#include "login.h"
#include "ui_login.h"
#include "bankwindow.h"

#include <QNetworkReply>

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    //delete ui;
}

/**
 * @brief signin::parseResult parse json reply
 * @param reply Network reply from restapi
 * @param user User card number
 * @param pin Pin code
 * @return false as default, true if sign in is succesful
 */
bool login::parseResult(QString user, QString pin){

    qDebug() << "User: " + user + ", pin: " + pin;
    QNetworkAccessManager networkManager;
    QUrl url("http://localhost/API/index.php/api/Login/check_login/?Korttinumero="+user+"&PIN="+pin);
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(url);

    QNetworkReply *currentReply = networkManager.get(request);

    while (!currentReply->isFinished()){
        qApp->processEvents();
    }

    QByteArray currentResponse = currentReply->readAll();
    qDebug() << "Response: " +currentResponse;


    if (currentResponse=="true"){
        bankwindow *bWindow = new bankwindow;
        bWindow->show();
        bWindow->customerNo=user;
        this->close();
    }

    return false;
}


void login::on_btnLogin_clicked()
{
    QString t_user = ui->txtCard->text();
    QString t_pin = ui->txtPin->text();

    if (parseResult(t_user, t_pin)==true){
        ui->lblText->setText("OK");
    }
    else {
        ui->lblText->setText("Väärä kortti tai PIN");
    }

}
