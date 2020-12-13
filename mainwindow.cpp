#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lblBalance->setEnabled(false);
    ui->lblMessage->setEnabled(false);
    ui->lblWithdraw20->setEnabled(false);
    ui->lblWithdraw40->setEnabled(false);
    ui->lblWithdraw100->setEnabled(false);
    ui->lblWithdraw50->setEnabled(false);
    ui->lblTransaction->setEnabled(false);

    connect(&logIn, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    logIn.show();
    logIn.setFocus();

}
/**
 * @brief MainWindow::receiveData
 * @param data Received card number
 */
void MainWindow::receiveData(QString data){
    this->show();
    customerNumber = data;
    ui->lblBalance->setEnabled(true);
    ui->lblMessage->setEnabled(true);
    ui->lblWithdraw20->setEnabled(true);
    ui->lblWithdraw40->setEnabled(true);
    ui->lblWithdraw100->setEnabled(true);
    ui->lblWithdraw50->setEnabled(true);
    ui->lblTransaction->setEnabled(true);
    ui->lblMessage->setText(data);
}

bool MainWindow::withdraw(double sum)
{
    QByteArray postData;
    postData.append("cardid="+customerNumber+"&");
    postData.append("summa=" + QString::number(sum,'f', 2));

    QNetworkAccessManager networkManager;
    QUrl url("http://localhost/API/index.php/api/Withdraw/withdraw/");

    QNetworkRequest request;
    request.setUrl(url);

    QNetworkReply* currentReply = networkManager.post(request,postData);


    while (!currentReply->isFinished()){
        qApp->processEvents();
    }

    QByteArray currentResponse = currentReply->readAll();

    if (currentResponse=="1"){
        return true;
    }

    return false;
}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::on_lblWithdraw20_clicked()
{
    if (withdraw(20.0) == true) {
        QMessageBox::information(this, "INFO", "Nosto onnistunut.\nOle hyvä ja ota kortti pois koneesta.");
        QCoreApplication::quit();
    }
    else
    {
        QMessageBox::information(this, "VIRHE", "Tapahtui virhe.\nOle hyvä ja koita uudelleen.");
    }
}

void MainWindow::on_lblWithdraw40_clicked()
{
    if (withdraw(40.0) == true) {
        QMessageBox::information(this, "INFO", "Nosto onnistunut.\nOle hyvä ja ota kortti pois koneesta.");
        QCoreApplication::quit();
    }
    else
    {
        QMessageBox::information(this, "VIRHE", "Tapahtui virhe.\nOle hyvä ja koita uudelleen.");
    }
}

void MainWindow::on_lblWithdraw50_clicked()
{
    if (withdraw(50.0) == true) {
        QMessageBox::information(this, "INFO", "Nosto onnistunut.\nOle hyvä ja ota kortti pois koneesta.");
        QCoreApplication::quit();
    }
    else
    {
        QMessageBox::information(this, "VIRHE", "Tapahtui virhe.\nOle hyvä ja koita uudelleen.");
    }
}

void MainWindow::on_lblWithdraw100_clicked()
{
    if (withdraw(100.0) == true) {
        QMessageBox::information(this, "INFO", "Nosto onnistunut.\nOle hyvä ja ota kortti pois koneesta.");
        QCoreApplication::quit();
    }
    else
    {
        QMessageBox::information(this, "VIRHE", "Tapahtui virhe.\nOle hyvä ja koita uudelleen.");
    }
}

/**
 * @brief MainWindow::on_lblBalance_clicked, gets the current balance
 * of given card number
 *
 */
void MainWindow::on_lblBalance_clicked()
{
    QNetworkAccessManager networkManager;
    QUrl url("http://localhost/API/index.php/api/Balance/Getbalance/?Korttinumero="+customerNumber);
    QNetworkRequest request;
    request.setUrl(url);

    QNetworkReply* currentReply = networkManager.get(request);

    while (!currentReply->isFinished()){
        qApp->processEvents();
    }

    QString currentResponse = currentReply->readAll();

    if (currentResponse != NULL){
        QMessageBox::information(this, "Saldo", "Saldo: ");

    }




}
