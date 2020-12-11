#include "mainwindow.h"
#include "ui_mainwindow.h"

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

MainWindow::~MainWindow()
{
    delete ui;


}
