#include "dllmysql.h"

/*

DLLMySQL::DLLMySQL()
{

}



DLLMySQL::~DLLMySQL()
{

}

*/

int DLLMySQL::verification(QString userRFID, QString userPIN)
{
    objectMySQLClassEngine = new MySQLClassEngine;
    int verificationResult;
    verificationResult = objectMySQLClassEngine->verifyAccount(userRFID,userPIN);
    if (verificationResult==1)
    {
        accountID = objectMySQLClassEngine->getAccountID();
    }

    delete objectMySQLClassEngine;
    objectMySQLClassEngine = 0;

    return verificationResult;
}

bool DLLMySQL::cardLocked(QString userRFID)
{
    objectMySQLClassEngine = new MySQLClassEngine;
    bool locked;

    locked= objectMySQLClassEngine->checkCardLocked(userRFID);

    delete objectMySQLClassEngine;
    objectMySQLClassEngine = 0;

    return locked;
}

QStringList DLLMySQL::accountHistory(int historyIndex)
{
    objectMySQLClassEngine = new MySQLClassEngine;

    QStringList AccountHistory;

    AccountHistory= objectMySQLClassEngine->getAccountHistory(accountID,historyIndex);


    delete objectMySQLClassEngine;
    objectMySQLClassEngine = 0;

    return AccountHistory;
}

QStringList DLLMySQL::userInformation()
{
    objectMySQLClassEngine = new MySQLClassEngine;

    QStringList AccountInformation;

    AccountInformation = objectMySQLClassEngine->getAccountInformation(accountID);
    qDebug() << "userInformation, accountID="<<accountID;
    delete objectMySQLClassEngine;
    objectMySQLClassEngine = 0;

    return AccountInformation;
}

QString DLLMySQL::accountBalance()
{
    objectMySQLClassEngine = new MySQLClassEngine;

    QString AccountBalance;

    AccountBalance = objectMySQLClassEngine->getAccountBalance(accountID);

    delete objectMySQLClassEngine;
    objectMySQLClassEngine = 0;

    return AccountBalance;
}

double DLLMySQL::getExchangeRate(QString currency, int value)
{
    objectMySQLClassEngine = new MySQLClassEngine;

    double returnValue;
    double multiplier;
    multiplier = objectMySQLClassEngine->getCurrencyMultiplier(currency);
    returnValue = value*multiplier;
    qDebug()<< "exchangerate returnValue =" << value <<"*"<< multiplier << "=" << returnValue;
    delete objectMySQLClassEngine;
    objectMySQLClassEngine = 0;

    return returnValue;
}

bool DLLMySQL::withdrawMoney(QString currency, double amount)
{
    objectMySQLClassEngine = new MySQLClassEngine;
    bool returnValue;
    returnValue = objectMySQLClassEngine->widthrawMoney(currency,amount,accountID);

    delete objectMySQLClassEngine;
    objectMySQLClassEngine = 0;

    return returnValue;
}

void DLLMySQL::logOut()
{
    accountID=0;
}


