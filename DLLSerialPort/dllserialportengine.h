#ifndef DLLSERIALPORTENGINE_H
#define DLLSERIALPORTENGINE_H
#include <QSerialPort>
#include <QObject>
#include <QDebug>
#include <QIODevice>
class dllserialportengine : public QObject
{
    Q_OBJECT
public:
    dllserialportengine();
    //void ValueToReturn();
    QString getCardID();
    void resetCard();


private:
    QSerialPort *serial;
    QString cardID;
public slots:

private slots:
    void serialReceived();

};

#endif // DLLSERIALPORTENGINE_H
