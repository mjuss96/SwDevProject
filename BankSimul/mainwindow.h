#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QMessageBox>

#include <dllpincode.h>
#include <dllserialport.h>
#include <dllmysql.h>
#include "custommessagebox.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *ajastin;

private slots:
    //void on_pushButton_clicked();

    void on_pushButtonWithdraw_clicked();

    void on_pushButtonOff_clicked();

    void on_pushButtonBack_clicked();

    void on_pushButtonBalance_clicked();

    void on_pushButtonBack_2_clicked();

    void on_pushButtonEUR_clicked();

    void on_pushButtonSEK_clicked();

    void on_pushButtonNOK_clicked();

    void on_pushButtonRUB_clicked();

    void on_pushButtonGBP_clicked();

    void on_pushButtonUSD_clicked();

    void on_pushButtonBack_3_clicked();

    void on_pushButtonBack_4_clicked();

    void on_pushButtonBack_5_clicked();

    void on_pushButtonBack_6_clicked();

    void on_pushButtonBack_7_clicked();

    void on_pushButtonBack_8_clicked();

    void on_pushButtonBack_9_clicked();

    void on_pushButton_clicked();

    void on_pushButtonHistory_clicked();

    void checkCard();

    void on_button_history_next_clicked();

    void on_button_history_back_clicked();

    void logIn();

    void stopTime();

    void on_pushButtonNOK_200_clicked();

    void on_pushButtonNOK_400_clicked();

    void on_pushButtonNOK_600_clicked();

    void on_pushButtonNOK_1000_clicked();

    void on_pushButtonNOK_2000_clicked();

    void on_pushButtonNOK_5000_clicked();

    void withdrawMoney(QString currency, int buttonValue);

    void on_pushButtonSEK_200_clicked();

    void on_pushButtonSEK_400_clicked();

    void on_pushButtonSEK_600_clicked();

    void on_pushButtonSEK_1000_clicked();

    void on_pushButtonSEK_2000_clicked();

    void on_pushButtonSEK_5000_clicked();

    void on_pushButtonRUB_1000_clicked();

    void on_pushButtonRUB_3000_clicked();

    void on_pushButtonRUB_5000_clicked();

    void on_pushButtonRUB_10000_clicked();

    void on_pushButtonRUB_20000_clicked();

    void on_pushButtonRUB_35000_clicked();

    void on_pushButtonGBP_20_clicked();

    void on_pushButtonGBP_50_clicked();

    void on_pushButtonGBP_70_clicked();

    void on_pushButtonGBP_100_clicked();

    void on_pushButtonGBP_200_clicked();

    void on_pushButtonGBP_500_clicked();

    void on_pushButtonUSD_20_clicked();

    void on_pushButtonUSD_40_clicked();

    void on_pushButtonUSD_60_clicked();

    void on_pushButtonUSD_80_clicked();

    void on_pushButtonUSD_100_clicked();

    void on_pushButtonUSD_200_clicked();

    void on_pushButtonEUR_20_clicked();

    void on_pushButtonEUR_40_clicked();

    void on_pushButtonEUR_60_clicked();

    void on_pushButtonEUR_100_clicked();

    void on_pushButtonEUR_200_clicked();

    void on_pushButtonEUR_500_clicked();

    void ilmoitusEuro(QString currency, float buttonValue);

    void disableAllButtons(bool toBeEnabled);

private:
    Ui::MainWindow *ui;
    DLLPinCode *objectDLLPinCode;
    DLLSerialPort *objectDLLSerialPort;
    DLLMySQL *objectDLLMySQL;
    QTimer *cardTimer;
    QString receivedRFID;
    QString receivedPIN;
    int historyIndex = 0;
    int login;
    QString sendText;

};

#endif // MAINWINDOW_H
