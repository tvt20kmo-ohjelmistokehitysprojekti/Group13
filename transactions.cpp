#include "transactions.h"
#include "ui_transactions.h"

transactions::transactions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::transactions)
{
    ui->setupUi(this);
}

transactions::~transactions()
{
    delete ui;
}
