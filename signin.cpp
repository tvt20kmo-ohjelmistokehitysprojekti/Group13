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
    // Check if connected to databse
    if (db->Connected == false){
        ui->lblText->setText("Tietokantaan ei saada yhteyttä!");

    }

    // Lets check if card number is on the database
    // and verify PIN also
    else{

    }
}
