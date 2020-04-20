#ifndef DLLMYSQL_H
#define DLLMYSQL_H

#include "dllmysql_global.h"
#include "mysqlclassengine.h"

class DLLMYSQLSHARED_EXPORT DLLMySQL
{

public:
   // DLLMySQL();
   // ~DLLMySQL();
    int verification(QString userRFID, QString userPIN);
    bool cardLocked(QString userRFID);
    QStringList accountHistory(int historyIndex);
    QStringList userInformation();
    QString accountBalance();
    double getExchangeRate(QString currency, int value);
    bool withdrawMoney(QString currency, double amount);
    void logOut();

protected:
    int accountID;
private:
    MySQLClassEngine *objectMySQLClassEngine;
};

#endif // DLLMYSQL_H
