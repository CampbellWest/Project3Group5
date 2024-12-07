#include "../CampbellHeader/SmokeAlarm.h"
#include "CampbellHeader/AuditLogs.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>

SmokeAlarm::SmokeAlarm(){
    this->alarmStatus = false;
}

void SmokeAlarm::toggleAlarm() {
    if (this->alarmStatus) {
        // turn alarm off
    } else {
        // turn alarm on
    }
}

bool checkForSmoke() {
    // make a randomizer that will sometimes return yes for smoke then display alert
}

void MainWindow::on_pushButton_clicked()
{
    if (!smokeAlarmPopup) {
        smokeAlarmPopup = new SmokeAlarmAlertForm(this);
    }

    int randomNum = QRandomGenerator::global()->bounded(0, 5);

    if (randomNum == 4) {
        ui->SmokeAlarmNumber->display(10);
        smokeAlarmPopup->setParent(this); // Set the main window as the parent
        smokeAlarmPopup->resize(500, 300);
        smokeAlarmPopup->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
        smokeAlarmPopup->move(this->geometry().center() - smokeAlarmPopup->rect().center());
        smokeAlarmPopup->updateLabelText("DANGER");
        smokeAlarmPopup->show();

        AuditLogs *logger = new AuditLogs("Fire Alarm was set off");
        delete logger;
    } else {
        ui->SmokeAlarmNumber->display(0);
    }
}
