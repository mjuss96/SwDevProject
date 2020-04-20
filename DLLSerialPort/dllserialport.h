#ifndef DLLSERIALPORT_H
#define DLLSERIALPORT_H
#include "dllserialport.h"
#include "dllserialport_global.h"
#include "dllserialportengine.h"
#include <QObject>

class DLLSERIALPORTSHARED_EXPORT DLLSerialPort
{

public:
    DLLSerialPort();
    QString ReturnValue();
    void serialReceived();
    void resetValues();
protected:

private:
    dllserialportengine *objectengine;
    //QString ReturnCardID;


};

#endif // DLLSERIALPORT_H
