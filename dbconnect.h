#ifndef DBCONNECT_H
#define DBCONNECT_H
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>


class dbConnect
{
public:
    dbConnect();
    ~dbConnect();
    bool Connected = false;
    bool f_CardNumber(int t_Card, int t_Pin);

private:

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");



};

#endif // DBCONNECT_H
