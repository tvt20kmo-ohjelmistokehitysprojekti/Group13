#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "signin.h"

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void receiveData(QString data);

    void on_lblWithdraw20_clicked();

    void on_lblWithdraw40_clicked();

    void on_lblWithdraw50_clicked();

    void on_lblWithdraw100_clicked();

private:
    bool withdraw(double sum);
    Ui::MainWindow *ui;

    QString customerNumber;
    signin logIn;


};

#endif // MAINWINDOW_H
