#include "dllserialportengine.h"
#include "dllserialport.h"

dllserialportengine::dllserialportengine()
{

    serial = new QSerialPort;
    serial->setPortName("com3");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::HardwareControl);
    serial->open(QSerialPort::ReadOnly);
    QObject::connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));

}

void dllserialportengine::serialReceived()
{
    cardID = serial->readAll();
    cardID = cardID.simplified().mid(1, 10);
    // qDebug()<<cardID;
}

QString dllserialportengine::getCardID()
{
    return cardID;
}

void dllserialportengine::resetCard()
{
    cardID = "";
}
