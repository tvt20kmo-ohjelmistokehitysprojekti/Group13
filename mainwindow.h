#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "signin.h"

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;

    QString customerNumber;
    signin logIn;


};

#endif // MAINWINDOW_H
