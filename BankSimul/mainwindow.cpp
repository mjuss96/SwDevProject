#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(10);
    objectDLLPinCode = new DLLPinCode;
    objectDLLSerialPort = new DLLSerialPort;
    objectDLLMySQL = new DLLMySQL;
    cardTimer = new QTimer;
    connect(cardTimer, SIGNAL(timeout()), this, SLOT(checkCard()));
    cardTimer->start(1000);
    ajastin = new QTimer(this);
    connect(ajastin, SIGNAL(timeout()), this, SLOT(stopTime()));
}

MainWindow::~MainWindow()
{
    delete ui;

    delete objectDLLPinCode;
    objectDLLPinCode = 0;

    delete objectDLLSerialPort;
    objectDLLSerialPort = 0;

    delete objectDLLMySQL;
    objectDLLMySQL = 0;
}

void MainWindow::on_pushButtonWithdraw_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QStringList userInformation;
    userInformation = objectDLLMySQL->userInformation();
    ui->nosto_saldo->setText("SALDO:  "+objectDLLMySQL->accountBalance()+" €");
    ui->nosto_omistanajanEtunimi->setText(userInformation.at(0));
    ui->nosto_omiistajanSukunimi->setText(userInformation.at(1));
    ui->nosto_omistajanOsoite->setText(userInformation.at(2));

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonOff_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

    objectDLLSerialPort->resetValues();
    cardTimer->start(1000);
    ajastin->stop();
}

void MainWindow::on_pushButtonBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ajastin->setInterval(30000);
    ajastin->start();
}

void MainWindow::on_pushButtonBalance_clicked()
{
    //näytä saldo
    ui->stackedWidget->setCurrentIndex(2);
    QStringList userInformation;
    userInformation = objectDLLMySQL->userInformation();
    ui->label_balance_saldo->setText(objectDLLMySQL->accountBalance()+" €");
    ui->labelCB_Name->setText(userInformation.at(0));
    ui->labelCB_Lastname->setText(userInformation.at(1));
    ui->labelCB_address->setText(userInformation.at(2));
    QStringList accountHistory;
    accountHistory=objectDLLMySQL->accountHistory(0);
    ui->labelCB_date_1->setText(accountHistory.at(0));
    ui->labelCB_info_1->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(1);
    ui->labelCB_date_2->setText(accountHistory.at(0));
    ui->labelCB_info_2->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(2);
    ui->labelCB_date_3->setText(accountHistory.at(0));
    ui->labelCB_info_3->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(3);
    ui->labelCB_date_4->setText(accountHistory.at(0));
    ui->labelCB_info_4->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(4);
    ui->labelCB_date_5->setText(accountHistory.at(0));
    ui->labelCB_info_5->setText(accountHistory.at(1));
    ajastin->setInterval(10000);
    ajastin->start();

}

void MainWindow::on_pushButtonBack_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ajastin->setInterval(30000);
    ajastin->start();
}

void MainWindow::on_pushButtonEUR_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonSEK_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    float value;
    QString s_value;

    // nappi 200
    value = objectDLLMySQL->getExchangeRate("SEK",200);
    s_value = QString::number(value, 'f', 2);
    ui->label_200_SEK->setText(s_value +"€");

    // nappi 400
    value = objectDLLMySQL->getExchangeRate("SEK",400);
    s_value = QString::number(value, 'f', 2);
    ui->label_400_SEK->setText(s_value +"€");

    // nappi 600
    value = objectDLLMySQL->getExchangeRate("SEK",600);
    s_value = QString::number(value, 'f', 2);
    ui->label_600_SEK->setText(s_value +"€");

    // nappi 1000
    value = objectDLLMySQL->getExchangeRate("SEK",1000);
    s_value = QString::number(value, 'f', 2);
    ui->label_1000_SEK->setText(s_value +"€");

    // nappi 2000
    value = objectDLLMySQL->getExchangeRate("SEK",2000);
    s_value = QString::number(value, 'f', 2);
    ui->label_2000_SEK->setText(s_value +"€");

    // nappi 5000
    value = objectDLLMySQL->getExchangeRate("SEK",5000);
    s_value = QString::number(value, 'f', 2);
    ui->label_5000_SEK->setText(s_value +"€");

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonNOK_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    float value;
    QString s_value;

    // nappi 200
    value = objectDLLMySQL->getExchangeRate("NOK",200);
    s_value = QString::number(value, 'f', 2);
    ui->label_200_NOK->setText(s_value +"€");

    // nappi 400
    value = objectDLLMySQL->getExchangeRate("NOK",400);
    s_value = QString::number(value, 'f', 2);
    ui->label_400_NOK->setText(s_value +"€");

    // nappi 600
    value = objectDLLMySQL->getExchangeRate("NOK",600);
    s_value = QString::number(value, 'f', 2);
    ui->label_600_NOK->setText(s_value +"€");

    // nappi 1000
    value = objectDLLMySQL->getExchangeRate("NOK",1000);
    s_value = QString::number(value, 'f', 2);
    ui->label_1000_NOK->setText(s_value +"€");

    // nappi 2000
    value = objectDLLMySQL->getExchangeRate("NOK",2000);
    s_value = QString::number(value, 'f', 2);
    ui->label_2000_NOK->setText(s_value +"€");

    // nappi 5000
    value = objectDLLMySQL->getExchangeRate("NOK",5000);
    s_value = QString::number(value, 'f', 2);
    ui->label_5000_NOK->setText(s_value +"€");



    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonRUB_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    float value;
    QString s_value;

    // nappi 1000
    value = objectDLLMySQL->getExchangeRate("RUB",1000);
    s_value = QString::number(value, 'f', 2);
    ui->label_1000_RUB->setText(s_value +"€");

    // nappi 3000
    value = objectDLLMySQL->getExchangeRate("RUB",3000);
    s_value = QString::number(value, 'f', 2);
    ui->label_3000_RUB->setText(s_value +"€");

    // nappi 5000
    value = objectDLLMySQL->getExchangeRate("RUB",5000);
    s_value = QString::number(value, 'f', 2);
    ui->label_5000_RUB->setText(s_value +"€");

    // nappi 10000
    value = objectDLLMySQL->getExchangeRate("RUB",10000);
    s_value = QString::number(value, 'f', 2);
    ui->label_10000_RUB->setText(s_value +"€");

    // nappi 20000
    value = objectDLLMySQL->getExchangeRate("RUB",20000);
    s_value = QString::number(value, 'f', 2);
    ui->label_20000_RUB->setText(s_value +"€");

    // nappi 35000
    value = objectDLLMySQL->getExchangeRate("RUB",35000);
    s_value = QString::number(value, 'f', 2);
    ui->label_35000_RUB->setText(s_value +"€");


    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonGBP_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

    float value;
    QString s_value;

    // nappi 200
    value = objectDLLMySQL->getExchangeRate("GBP",20);
    s_value = QString::number(value, 'f', 2);
    ui->label_20_GBP->setText(s_value +"€");

    // nappi 400
    value = objectDLLMySQL->getExchangeRate("GBP",50);
    s_value = QString::number(value, 'f', 2);
    ui->label_50_GBP->setText(s_value +"€");

    // nappi 600
    value = objectDLLMySQL->getExchangeRate("GBP",70);
    s_value = QString::number(value, 'f', 2);
    ui->label_70_GBP->setText(s_value +"€");

    // nappi 1000
    value = objectDLLMySQL->getExchangeRate("GBP",100);
    s_value = QString::number(value, 'f', 2);
    ui->label_100_GBP->setText(s_value +"€");

    // nappi 2000
    value = objectDLLMySQL->getExchangeRate("GBP",200);
    s_value = QString::number(value, 'f', 2);
    ui->label_200_GBP->setText(s_value +"€");

    // nappi 5000
    value = objectDLLMySQL->getExchangeRate("GBP",500);
    s_value = QString::number(value, 'f', 2);
    ui->label_500_GBP->setText(s_value +"€");

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonUSD_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

    float value;
    QString s_value;

    // nappi 200
    value = objectDLLMySQL->getExchangeRate("USD",20);
    s_value = QString::number(value, 'f', 2);
    ui->label_20_USD->setText(s_value +"€");

    // nappi 400
    value = objectDLLMySQL->getExchangeRate("USD",40);
    s_value = QString::number(value, 'f', 2);
    ui->label_40_USD->setText(s_value +"€");

    // nappi 600
    value = objectDLLMySQL->getExchangeRate("USD",60);
    s_value = QString::number(value, 'f', 2);
    ui->label_60_USD->setText(s_value +"€");

    // nappi 1000
    value = objectDLLMySQL->getExchangeRate("USD",80);
    s_value = QString::number(value, 'f', 2);
    ui->label_80_USD->setText(s_value +"€");

    // nappi 2000
    value = objectDLLMySQL->getExchangeRate("USD",100);
    s_value = QString::number(value, 'f', 2);
    ui->label_100_USD->setText(s_value +"€");

    // nappi 5000
    value = objectDLLMySQL->getExchangeRate("USD",200);
    s_value = QString::number(value, 'f', 2);
    ui->label_200_USD->setText(s_value +"€");

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonBack_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ajastin->setInterval(30000);
    ajastin->start();
}

void MainWindow::on_pushButtonBack_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonBack_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonBack_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonBack_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonBack_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonBack_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ajastin->setInterval(30000);
    ajastin->start();
}

void MainWindow::logIn()
{
    cardTimer->stop();
    receivedPIN = objectDLLPinCode->rajapintafunktioDLLPinCode();
    if (receivedPIN == "poistu"){
        objectDLLSerialPort->resetValues();
        cardTimer->start(1000);
        ajastin->stop();
    }
    else{
        login = objectDLLMySQL->verification(receivedRFID, receivedPIN);
        if (login==1){
            ui->stackedWidget->setCurrentIndex(0);
            ajastin->start(30000);
        }else if(login==-1)
        {
            qDebug()<<"kortti lukossa";

            custommessagebox *objectCustomMessageBox = new custommessagebox();
            objectCustomMessageBox->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
            sendText = "Lukittu kortti";
            objectCustomMessageBox->giveText(sendText);
            objectCustomMessageBox->setTimerTime(3000);
            disableAllButtons(false);
            objectCustomMessageBox->show();
            objectCustomMessageBox->exec();
            disableAllButtons(true);
            delete objectCustomMessageBox;
            objectCustomMessageBox = 0;

            objectDLLSerialPort->resetValues();
            cardTimer->start(1000);
            ajastin->stop();

        }else
        {
            //väärä pin koodi

            qDebug()<<"vaara pinkoodi";

            custommessagebox *objectCustomMessageBox = new custommessagebox();
            objectCustomMessageBox->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
            sendText = "Väärä salasana. Kokeile uudestaan.";
            objectCustomMessageBox->giveText(sendText);
            objectCustomMessageBox->setTimerTime(3000);
            disableAllButtons(false);
            objectCustomMessageBox->show();
            objectCustomMessageBox->exec();
            disableAllButtons(true);
            delete objectCustomMessageBox;
            objectCustomMessageBox = 0;

            receivedPIN = "";
            logIn();
        }
    }
}

void MainWindow::on_pushButtonHistory_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    QStringList userInformation;
    userInformation = objectDLLMySQL->userInformation();
    qDebug()<<userInformation;
    ui->label_omistajanEtunimi->setText(userInformation.at(0));
    ui->label_omistajanSukunimi->setText(userInformation.at(1));
    ui->label_omistajan_osoite->setText(userInformation.at(2));
    ui->label_history_saldo->setText(objectDLLMySQL->accountBalance()+" €");




    QStringList accountHistory;


    accountHistory=objectDLLMySQL->accountHistory(0);
    ui->label_1_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_1_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(1);
    ui->label_2_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_2_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(2);
    ui->label_3_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_3_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(3);
    ui->label_4_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_4_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(4);
    ui->label_5_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_5_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(5);
    ui->label_6_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_6_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(6);
    ui->label_7_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_7_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(7);
    ui->label_8_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_8_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(8);
    ui->label_9_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_9_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(9);
    ui->label_10_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_10_tilitapahtuma->setText(accountHistory.at(1));

    QString test = accountHistory.at(0);
    if(test=="")
    {
        qDebug() << "ei enempää tilitapahtumia";
        ui->button_history_next->setEnabled(false);
    }
    ajastin->setInterval(10000);
    ajastin->start();


}

void MainWindow::checkCard()
{
    qDebug()<<receivedRFID;
    receivedRFID = objectDLLSerialPort->ReturnValue();

    if (receivedRFID != ""){
        cardTimer->stop();
        if (objectDLLMySQL->cardLocked(receivedRFID)==true){
            custommessagebox *objectCustomMessageBox = new custommessagebox();
            objectCustomMessageBox->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
            sendText = "Lukittu kortti";
            objectCustomMessageBox->giveText(sendText);
            objectCustomMessageBox->setTimerTime(3000);
            disableAllButtons(false);
            objectCustomMessageBox->show();
            objectCustomMessageBox->exec();
            disableAllButtons(true);
            delete objectCustomMessageBox;
            objectCustomMessageBox = 0;

            objectDLLSerialPort->resetValues();
            cardTimer->start(1000);
            ajastin->stop();
        }
        else{
        this->logIn();
        qDebug()<<receivedRFID;
        }
    }
    else
    cardTimer->setInterval(1000);
    qDebug()<<receivedRFID;

}

void MainWindow::on_button_history_next_clicked()
{
    historyIndex = historyIndex + 10;
    ui->button_history_back->setEnabled(true);
    QStringList accountHistory;


    accountHistory=objectDLLMySQL->accountHistory(historyIndex);
    ui->label_1_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_1_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 1);
    ui->label_2_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_2_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 2);
    ui->label_3_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_3_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 3);
    ui->label_4_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_4_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 4);
    ui->label_5_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_5_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 5);
    ui->label_6_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_6_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 6);
    ui->label_7_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_7_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 7);
    ui->label_8_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_8_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 8);
    ui->label_9_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_9_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 9);
    ui->label_10_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_10_tilitapahtuma->setText(accountHistory.at(1));

    QString test = accountHistory.at(0);
    if(test=="")
    {
        qDebug() << "ei enempää tilitapahtumia";
        ui->button_history_next->setEnabled(false);
    }
    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_button_history_back_clicked()
{
    historyIndex = historyIndex -10;
    if(historyIndex < 0) historyIndex= 0;
    if(historyIndex ==0) ui->button_history_back->setEnabled(false);
    ui->button_history_next->setEnabled(true);
    QStringList accountHistory;


    accountHistory=objectDLLMySQL->accountHistory(historyIndex);
    ui->label_1_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_1_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 1);
    ui->label_2_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_2_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 2);
    ui->label_3_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_3_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 3);
    ui->label_4_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_4_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 4);
    ui->label_5_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_5_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 5);
    ui->label_6_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_6_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 6);
    ui->label_7_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_7_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 7);
    ui->label_8_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_8_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 8);
    ui->label_9_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_9_tilitapahtuma->setText(accountHistory.at(1));
    accountHistory=objectDLLMySQL->accountHistory(historyIndex + 9);
    ui->label_10_tilitapahtumaPVM->setText(accountHistory.at(0));
    ui->label_10_tilitapahtuma->setText(accountHistory.at(1));
    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::stopTime()
{
    if (ui->stackedWidget->currentIndex() == 0 || ui->stackedWidget->currentIndex() == 10)
    {
        ui->stackedWidget->setCurrentIndex(10);
        objectDLLSerialPort->resetValues();
        cardTimer->start(1000);
        ajastin->stop();
    }else{
        ui->stackedWidget->setCurrentIndex(0);
        ajastin->setInterval(30000);
    }
}

void MainWindow::on_pushButtonNOK_200_clicked()
{
    withdrawMoney("NOK",200);

    ajastin->setInterval(10000);
    ajastin->start();

}

void MainWindow::on_pushButtonNOK_400_clicked()
{
    withdrawMoney("NOK",400);

    ajastin->setInterval(10000);
    ajastin->start();

}

void MainWindow::on_pushButtonNOK_600_clicked()
{
    withdrawMoney("NOK",600);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonNOK_1000_clicked()
{
    withdrawMoney("NOK",1000);

    ajastin->setInterval(10000);
    ajastin->start();

}

void MainWindow::on_pushButtonNOK_2000_clicked()
{
    withdrawMoney("NOK",2000);

    ajastin->setInterval(10000);
    ajastin->start();

}

void MainWindow::on_pushButtonNOK_5000_clicked()
{
   withdrawMoney("NOK",5000);

   ajastin->setInterval(10000);
   ajastin->start();

}

void MainWindow::withdrawMoney(QString currency, int buttonValue)
{


    bool ilmoitus;
    float value;
    value = objectDLLMySQL->getExchangeRate(currency,buttonValue);
    ilmoitus = objectDLLMySQL->withdrawMoney(currency,value);

    //messagebox
    if(ilmoitus)
    {
        //rahannosto onnistui
        custommessagebox *objectCustomMessageBox = new custommessagebox();
        objectCustomMessageBox->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
        QString strValue = QString::number(buttonValue);
        QString strValue2 = QString::number(value);
        sendText = "Rahannosto onnistui. Nostit " + strValue + " " + currency + " (" + strValue2 + " €)";
        objectCustomMessageBox->giveText(sendText);
        objectCustomMessageBox->setTimerTime(3000);
        disableAllButtons(false);
        objectCustomMessageBox->show();
        ajastin->stop();
        objectCustomMessageBox->exec();
        disableAllButtons(true);
        ajastin->start(7000);
        delete objectCustomMessageBox;
        objectCustomMessageBox = 0;
    }else{
        custommessagebox *objectCustomMessageBox = new custommessagebox();
        objectCustomMessageBox->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
        sendText = "Rahannosto epäonnistui.";
        objectCustomMessageBox->giveText(sendText);
        objectCustomMessageBox->setTimerTime(10000);
        disableAllButtons(false);
        objectCustomMessageBox->show();
        ajastin->stop();
        objectCustomMessageBox->exec();
        disableAllButtons(true);
        ajastin->start(500);
        delete objectCustomMessageBox;
        objectCustomMessageBox = 0;
    }
}

void MainWindow::on_pushButtonSEK_200_clicked()
{
    withdrawMoney("SEK",200);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonSEK_400_clicked()
{
    withdrawMoney("SEK",400);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonSEK_600_clicked()
{
    withdrawMoney("SEK",600);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonSEK_1000_clicked()
{
    withdrawMoney("SEK",1000);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonSEK_2000_clicked()
{
    withdrawMoney("SEK",2000);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonSEK_5000_clicked()
{
    withdrawMoney("SEK",5000);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonRUB_1000_clicked()
{
    withdrawMoney("RUB",1000);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonRUB_3000_clicked()
{
    withdrawMoney("RUB",3000);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonRUB_5000_clicked()
{
    withdrawMoney("RUB",5000);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonRUB_10000_clicked()
{
    withdrawMoney("RUB",10000);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonRUB_20000_clicked()
{
    withdrawMoney("RUB",20000);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonRUB_35000_clicked()
{
    withdrawMoney("RUB",35000);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonGBP_20_clicked()
{
    withdrawMoney("GBP",20);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonGBP_50_clicked()
{
    withdrawMoney("GBP",50);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonGBP_70_clicked()
{
    withdrawMoney("GBP",70);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonGBP_100_clicked()
{
    withdrawMoney("GBP",100);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonGBP_200_clicked()
{
    withdrawMoney("GBP",200);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonGBP_500_clicked()
{
    withdrawMoney("GBP",500);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonUSD_20_clicked()
{
    withdrawMoney("USD",20);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonUSD_40_clicked()
{
    withdrawMoney("USD",40);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonUSD_60_clicked()
{
    withdrawMoney("USD",60);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonUSD_80_clicked()
{
    withdrawMoney("USD",80);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonUSD_100_clicked()
{
    withdrawMoney("USD",100);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonUSD_200_clicked()
{
    withdrawMoney("USD",200);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonEUR_20_clicked()
{
    ilmoitusEuro("EUR",20);
    //objectDLLMySQL->withdrawMoney("EUR",20);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonEUR_40_clicked()
{
    ilmoitusEuro("EUR",40);
    //objectDLLMySQL->withdrawMoney("EUR",40);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonEUR_60_clicked()
{
    ilmoitusEuro("EUR",60);
    //objectDLLMySQL->withdrawMoney("EUR",60);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonEUR_100_clicked()
{
    ilmoitusEuro("EUR",100);
    //objectDLLMySQL->withdrawMoney("EUR",100);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonEUR_200_clicked()
{
    ilmoitusEuro("EUR",200);
    //objectDLLMySQL->withdrawMoney("EUR",200);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::on_pushButtonEUR_500_clicked()
{
    ilmoitusEuro("EUR",500);
    //objectDLLMySQL->withdrawMoney("EUR",500);

    ajastin->setInterval(10000);
    ajastin->start();
}

void MainWindow::ilmoitusEuro(QString currency, float buttonValue)
{
    bool ilmoitus;
    ilmoitus = objectDLLMySQL->withdrawMoney(currency,buttonValue);

    //messagebox
    if(ilmoitus)
    {
        //rahannosto onnistui
        custommessagebox *objectCustomMessageBox = new custommessagebox();
        objectCustomMessageBox->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
        QString strValue = QString::number(buttonValue);
        sendText = "Rahannosto onnistui. Nostit " + strValue + " " + currency;
        objectCustomMessageBox->giveText(sendText);
        objectCustomMessageBox->setTimerTime(3000);
        disableAllButtons(false);
        objectCustomMessageBox->show();
        objectCustomMessageBox->exec();
        disableAllButtons(true);
        delete objectCustomMessageBox;
        objectCustomMessageBox = 0;
    }else{
        //rahannosto epaonnistui
        custommessagebox *objectCustomMessageBox = new custommessagebox();
        objectCustomMessageBox->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
        sendText = "Rahannosto epäonnistui.";
        objectCustomMessageBox->giveText(sendText);
        objectCustomMessageBox->setTimerTime(10000);
        disableAllButtons(false);
        objectCustomMessageBox->show();
        objectCustomMessageBox->exec();
        disableAllButtons(true);
        delete objectCustomMessageBox;
        objectCustomMessageBox = 0;
    }
}

void MainWindow::disableAllButtons(bool toBeEnabled){
    QList<QPushButton *> buttonsList = this->findChildren<QPushButton *>();
    for (int i = 0; i < buttonsList.count(); i++){
        buttonsList.at(i)->setEnabled(toBeEnabled);
    }
}
