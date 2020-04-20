#include "mysqlclassengine.h"

MySQLClassEngine::MySQLClassEngine()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("mysli.oamk.fi");
    db.setDatabaseName("opisk_t7juma01");
    db.setUserName("t7juma01");
    db.setPassword("");
    db.open();
}

MySQLClassEngine::~MySQLClassEngine()
{
    db.close();
}

int MySQLClassEngine::verifyAccount(QString userRFID, QString userPIN)
{
    int verification;
    QString pinCode;
    int account;
    int failedLogins;
    QSqlQuery query;
    query.prepare("SELECT failedLogins FROM BS_card WHERE cardRFID=?");
    query.addBindValue(userRFID);
    query.exec();
    query.seek(0);
    failedLogins= query.value(0).toInt();

    if(failedLogins>2)
    {
        verification=-1;
    }
    else{
        query.prepare("SELECT cardPIN, accountID FROM BS_card WHERE cardRFID=?");
        query.addBindValue(userRFID);
        query.exec();
        query.seek(0);
        pinCode= query.value(0).toString();
        account= query.value(1).toInt();

        if(pinCode==userPIN && pinCode!=""){
            verification=1;
            accountID=account;

            query.prepare("UPDATE BS_card SET failedLogins=0 WHERE cardRFID=?");
            query.addBindValue(userRFID);
            query.exec();

        }
        else{
            verification=0;
			
            if(failedLogins==2){
                verification=-1;
            }
			
            query.prepare("UPDATE BS_card SET failedLogins=? WHERE cardRFID=?");
            query.addBindValue(failedLogins+1);
            query.addBindValue(userRFID);
            query.exec();
        }
    }
    return verification;
}

bool MySQLClassEngine::checkCardLocked(QString userRFID)
{
    int failedLogins;
    QSqlQuery query;

    query.prepare("SELECT failedLogins FROM BS_card WHERE cardRFID=?");
    query.addBindValue(userRFID);
    query.exec();
    query.seek(0);
    failedLogins= query.value(0).toInt();

    if(failedLogins>2)
    {
        return true;
    }

    return false;
}

QStringList MySQLClassEngine::getAccountHistory(int accID, int historyIndex)
{
    QStringList history;
    QSqlQuery query;
    QDateTime pvm;
    query.prepare("SELECT pvm, transactionInfo FROM BS_accountHistory WHERE accountID=? ORDER BY historyID DESC");
    query.addBindValue(accID);
    query.exec();

    query.seek(historyIndex);
    pvm = query.value(0).toDateTime();
    QString pvmString = pvm.toString("yyyy-MM-dd hh:mm:ss");
    history << pvmString << query.value(1).toString();

    return history;

}

QStringList MySQLClassEngine::getAccountInformation(int accID)
{
    QStringList information;
    QSqlQuery query;
    query.prepare("SELECT BS_user.firstName, BS_user.lastName, BS_user.address FROM BS_user INNER JOIN BS_account ON BS_user.userID=BS_account.ownerID WHERE BS_account.ownerID=?");
    query.addBindValue(accID);
    query.exec();
    query.seek(0);
    information << query.value(0).toString() << query.value(1).toString() << query.value(2).toString();

    return information;
}

QString MySQLClassEngine::getAccountBalance(int accID)
{
    QString BalanceString;
    QSqlQuery query;
    query.prepare("SELECT balance FROM BS_account WHERE accountID=?");
    query.addBindValue(accID);
    query.exec();
    query.seek(0);
    BalanceString = query.value(0).toString();

    return BalanceString;
}

double MySQLClassEngine::getCurrencyMultiplier(QString currency)
{
    double multiplier;
    QSqlQuery query;
    int currencyNumber;

    if(currency=="USD")currencyNumber=1;
    if(currency=="SEK")currencyNumber=2;
    if(currency=="NOK")currencyNumber=3;
    if(currency=="RUB")currencyNumber=4;
    if(currency=="GBP")currencyNumber=5;

    switch (currencyNumber)
    {
    case 1:
        query.prepare("SELECT USD FROM exchangeRate");
        query.addBindValue(currency);
        query.exec();
        query.seek(0);
        multiplier = query.value(0).toDouble();
      break;
    case 2:
        query.prepare("SELECT SEK FROM exchangeRate");
        query.addBindValue(currency);
        query.exec();
        query.seek(0);
        multiplier = query.value(0).toDouble();
      break;
    case 3:
        query.prepare("SELECT NOK FROM exchangeRate");
        query.addBindValue(currency);
        query.exec();
        query.seek(0);
        multiplier = query.value(0).toDouble();
      break;
    case 4:
        query.prepare("SELECT RUB FROM exchangeRate");
        query.addBindValue(currency);
        query.exec();
        query.seek(0);
        multiplier = query.value(0).toDouble();
        break;
    case 5:
        query.prepare("SELECT GBP FROM exchangeRate");
        query.addBindValue(currency);
        query.exec();
        query.seek(0);
        multiplier = query.value(0).toDouble();
        break;
    }

    qDebug()<<"getCurrency multiplier= "<< multiplier;
    return multiplier;
}

int MySQLClassEngine::getAccountID()
{
    return accountID;
}

bool MySQLClassEngine::widthrawMoney(QString currency, double value, int accID)
{
    QSqlQuery query;
    double balance;
    query.prepare("SELECT balance FROM BS_account WHERE accountID=?");
    query.addBindValue(accID);
    query.exec();
    query.seek(0);
    balance = query.value(0).toDouble();

    if(balance<value||value<0)
    {
        return false;
    }
    else{
        double newBalance = balance-value;
        QString::number(newBalance, 'f', 2);
        query.prepare("UPDATE BS_account SET balance=? WHERE accountID=?");
        query.addBindValue(newBalance);
        query.addBindValue(accID);
        query.exec();


        QString transactionInfo;
        QString valueString;
        valueString = QString::number(value,'f',2);
        transactionInfo= "NOSTO " + currency + ", " + valueString + " €";

        query.prepare("INSERT INTO BS_accountHistory (accountID,transactionInfo) VALUES(?,?)");
        query.addBindValue(accID);
        query.addBindValue(transactionInfo);
        query.exec();

        return true;
    }
}
