#include "dbconnect.h"

/**
 * Fill in the database info
 * @param setHostname       Set database hostname
 * @param setDatabaseName   Set database name
 * @param setUserName       Set database username
 * @param setPassword       Set database password
 */
dbConnect::dbConnect()
{

    this->db.setHostName("localhost:3306");
    this->db.setDatabaseName("ruojasol_temporary");
    this->db.setUserName("ruojasol_mysql");
    this->db.setPassword("Tietokanna7");
    if (!db.open()){
        qDebug() << db.lastError();

    }
    qDebug("Connected");

    this->Connected = db.open();

}

/**
 * Check if card number exists on database, and if the
 * given pin matches the card number
 * @param t_Card            Given card number
 * @param t_Pin             Given PIN code
 * @returns true, if found and positive match, false if not.
 */
bool dbConnect::f_CardNumber(int t_Card, int t_Pin){

    return false;
}


dbConnect::~dbConnect(){
    this->db.close();
    this->Connected = false;
}
