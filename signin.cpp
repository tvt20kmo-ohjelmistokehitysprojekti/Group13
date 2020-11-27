#include "signin.h"
#include "ui_signin.h"

signin::signin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
}

signin::~signin()
{
    delete ui;
}



void signin::on_btnLogin_clicked()
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

/**
 * @brief signin::parseResult parse json reply
 * @param reply Network reply from restapi
 * @param user User card number
 * @param pin Pin code
 * @return false as default, true if sign in is succesful
 */
bool signin::parseResult(QString user, QString pin){
    qDebug() << "User: " + user + ", pin: " + pin;
    QNetworkAccessManager networkManager;
    QUrl url("http://localhost/API/index.php/api/Login/check_login/?card_id="+user+"&card_pin="+pin);
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
        return true;
    }

    return false;

}
