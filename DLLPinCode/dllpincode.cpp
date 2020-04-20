#include "dllpincode.h"

QString DLLPINCODESHARED_EXPORT DLLPinCode::rajapintafunktioDLLPinCode()
{

    Dialog *objectDialog = new Dialog();

    objectDialog->setWindowFlags(Qt::CustomizeWindowHint);

    objectDialog->showFullScreen();

    objectDialog->exec();

    valueToReturn = objectDialog->returnPinCode();

    delete objectDialog;
    objectDialog = 0;

    return valueToReturn;

}
