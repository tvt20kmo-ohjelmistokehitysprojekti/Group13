#ifndef BANKWINDOW_H
#define BANKWINDOW_H
#include <QWidget>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

namespace Ui {
class bankwindow;
}

class bankwindow : public QWidget
{
    Q_OBJECT

public:
    explicit bankwindow(QWidget *parent = nullptr);
    ~bankwindow();
    QString customerNo;

private slots:
    void on_lblWithdraw20_clicked();

    void on_lblWithdraw40_clicked();

    void on_lblWithdraw50_clicked();

    void on_lblWithdraw100_clicked();

private:
    Ui::bankwindow *ui;



};

#endif // BANKWINDOW_H
