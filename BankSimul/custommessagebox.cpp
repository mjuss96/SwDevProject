#include "custommessagebox.h"
#include "ui_custommessagebox.h"

custommessagebox::custommessagebox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::custommessagebox)
{
    ui->setupUi(this);
    messageTimer = new QTimer;
    connect(messageTimer, SIGNAL(timeout()), this, SLOT(on_pushButton_clicked()));
}

custommessagebox::~custommessagebox()
{
    delete ui;
    delete messageTimer;
    messageTimer = 0;
}

void custommessagebox::giveText(QString text)
{
    if(text == "Rahannosto epäonnistui." || text == "Lukittu kortti" || text == "Väärä salasana. Kokeile uudestaan."){
        ui->label->setStyleSheet("QLabel { color : red; }");
        ui->label->setText(text);
    }else{
        ui->label->setStyleSheet("QLabel { color : green; }");
        ui->label->setText(text);
    }
}

void custommessagebox::setTimerTime(int sentTime)
{
        messageTimer->start(sentTime);
}

void custommessagebox::on_pushButton_clicked()
{
    this->close();
}
