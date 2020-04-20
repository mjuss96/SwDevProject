#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    pinTimer = new QTimer;
    pinTimer->start(10000);
    connect(pinTimer, SIGNAL(timeout()), this, SLOT(on_pushButton_peruuta_clicked()));
}

Dialog::~Dialog()
{
    delete ui;
    delete pinTimer;
    pinTimer = 0;
}

QString Dialog::returnPinCode()
{
    return pin;
}

void Dialog::on_pushButton_0_clicked()
{
    hash = hash + "*";
    pin = pin + "0";

    if (pin.length() > pinMax)
        pin.truncate(pinMax);
        hash.truncate(pinMax);

    ui->lineEdit->setText(hash);
}

void Dialog::on_pushButton_1_clicked()
{
    hash = hash + "*";
    pin = pin + "1";

    if (pin.length() > pinMax)
        pin.truncate(pinMax);
        hash.truncate(pinMax);

    ui->lineEdit->setText(hash);
}

void Dialog::on_pushButton_2_clicked()
{
    hash = hash + "*";
    pin = pin + "2";

    if (pin.length() > pinMax)
        pin.truncate(pinMax);
        hash.truncate(pinMax);

    ui->lineEdit->setText(hash);
}

void Dialog::on_pushButton_3_clicked()
{
    hash = hash + "*";
    pin = pin + "3";

    if (pin.length() > pinMax)
        pin.truncate(pinMax);
        hash.truncate(pinMax);

    ui->lineEdit->setText(hash);
}

void Dialog::on_pushButton_4_clicked()
{
    hash = hash + "*";
    pin = pin + "4";

    if (pin.length() > pinMax)
        pin.truncate(pinMax);
        hash.truncate(pinMax);

    ui->lineEdit->setText(hash);
}

void Dialog::on_pushButton_5_clicked()
{
    hash = hash + "*";
    pin = pin + "5";

    if (pin.length() > pinMax)
        pin.truncate(pinMax);
        hash.truncate(pinMax);

    ui->lineEdit->setText(hash);
}

void Dialog::on_pushButton_6_clicked()
{
    hash = hash + "*";
    pin = pin + "6";

    if (pin.length() > pinMax)
        pin.truncate(pinMax);
        hash.truncate(pinMax);

    ui->lineEdit->setText(hash);
}

void Dialog::on_pushButton_7_clicked()
{
    hash = hash + "*";
    pin = pin + "7";

    if (pin.length() > pinMax)
        pin.truncate(pinMax);
        hash.truncate(pinMax);

    ui->lineEdit->setText(hash);
}

void Dialog::on_pushButton_8_clicked()
{
    hash = hash + "*";
    pin = pin + "8";

    if (pin.length() > pinMax)
        pin.truncate(pinMax);
        hash.truncate(pinMax);

    ui->lineEdit->setText(hash);
}

void Dialog::on_pushButton_9_clicked()
{
    hash = hash + "*";
    pin = pin + "9";

    if (pin.length() > pinMax)
        pin.truncate(pinMax);
        hash.truncate(pinMax);

    ui->lineEdit->setText(hash);
}

void Dialog::on_pushButton_Poista_clicked()
{
    hash.chop(1);
    pin.chop(1);
    ui->lineEdit->setText(hash);
}

void Dialog::on_pushButton_ok_clicked()
{
    this->close();
}


void Dialog::on_pushButton_peruuta_clicked()
{
    pin = "poistu";
    this->close();
}
