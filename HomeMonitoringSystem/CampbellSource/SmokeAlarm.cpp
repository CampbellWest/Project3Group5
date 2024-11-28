#include "../CampbellHeader/SmokeAlarm.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    smokeAlarmPopup->setParent(this); // Set the main window as the parent
    smokeAlarmPopup->resize(500, 300);
    smokeAlarmPopup->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    smokeAlarmPopup->move(this->geometry().center() - smokeAlarmPopup->rect().center());

    smokeAlarmPopup->updateLabelText("DANGER");

    smokeAlarmPopup->show();
}
