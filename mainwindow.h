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

private:
    Ui::MainWindow *ui;

    int customerNumber;
    signin *logIn = new signin;


};

#endif // MAINWINDOW_H
