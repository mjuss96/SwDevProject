#ifndef CUSTOMMESSAGEBOX_H
#define CUSTOMMESSAGEBOX_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class custommessagebox;
}

class custommessagebox : public QDialog
{
    Q_OBJECT

public:
    explicit custommessagebox(QWidget *parent = 0);
    ~custommessagebox();
    void giveText(QString text);
    void setTimerTime(int sentTime);

private slots:
    void on_pushButton_clicked();

private:
    Ui::custommessagebox *ui;
    QTimer *messageTimer;
    custommessagebox *objectCustomMessageBox;
};

#endif // CUSTOMMESSAGEBOX_H
