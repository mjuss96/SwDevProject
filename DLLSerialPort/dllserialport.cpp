#include "dllserialport.h"

#include <QDebug>
#include <QTextCodec>

DLLSerialPort::DLLSerialPort()
{
    objectengine = new dllserialportengine;
}


QString DLLSerialPort::ReturnValue()
{
    return objectengine->getCardID();
}

void DLLSerialPort::resetValues()
{
    objectengine->resetCard();
}
