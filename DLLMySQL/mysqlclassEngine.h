#ifndef MYSQLCLASS_H
#define MYSQLCLASS_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QDateTime>
class MySQLClassEngine
{
public:
    MySQLClassEngine();
    ~MySQLClassEngine();
    int verifyAccount(QString userRFID, QString userPIN);
    bool checkCardLocked(QString userRFID);
    QStringList getAccountHistory(int accID,int historyIndex);
    QStringList getAccountInformation(int accID);
    QString getAccountBalance(int accID);
    double getCurrencyMultiplier(QString currency);
    int getAccountID();
    bool widthrawMoney(QString currency, double value, int accID);
private:
    QSqlDatabase db;
    int accountID;
};

#endif // MYSQLCLASS_H
