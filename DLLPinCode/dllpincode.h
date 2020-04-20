#ifndef DLLPINCODE_H
#define DLLPINCODE_H

#include "dllpincode_global.h"
#include "pincodeengine.h"
#include "dialog.h"

class DLLPinCode
{

public:
    QString rajapintafunktioDLLPinCode();

private:
    QString valueToReturn;
    Dialog *objectDialog;
};

#endif // DLLPINCODE_H
