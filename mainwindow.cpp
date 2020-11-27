#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btbWithdraw->setEnabled(false);
    ui->btnDeposit->setEnabled(false);
    ui->btnTransaction->setEnabled(false);

    connect(&logIn, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    logIn.show();

}

MainWindow::~MainWindow()
{
    delete ui;

}

/**
 * @brief MainWindow::receiveData
 * @param data Received card number
 */
void MainWindow::receiveData(QString data){
    ui->lblCustomer->setText("Kortti: " + data);
    customerNumber = data;
    ui->btbWithdraw->setEnabled(true);
    ui->btnDeposit->setEnabled(true);
    ui->btnTransaction->setEnabled(true);


}
