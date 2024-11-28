#include "../CampbellHeader/COMonitor.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

COMonitor::COMonitor() {
    this->currentCOLevel = 0.0;
}

float COMonitor::getCOLevel() {
    return this->currentCOLevel;
}

void COMonitor::alertUnsafe() {
    // pop up on the interface an alert
}

void MainWindow::on_pushButton_2_clicked()
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
