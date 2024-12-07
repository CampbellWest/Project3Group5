#include "../TylerHeader/doorlocks.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QString"
#include "QTimer"
#include <QObject>
#include "QFile"
#include "QMessageBox"

DoorLocks::DoorLocks(MainWindow* parentWindow) {
    this->mainWindow = parentWindow;

    readFromFile();

    mainWindow->setDoorOnStartUp(this->checkOpen(), this->checkLocked());
}

DoorLocks::~DoorLocks() {}

bool DoorLocks::checkOpen() {
    if(this->isOpen == true)
        return true;
    return false;
}

void DoorLocks::setOpen(bool status) {
    this->isOpen = status;
}

bool DoorLocks::checkLocked() {
    if(this->isLocked == true)
        return true;
    return false;
}

void DoorLocks::setLocked(bool status) {
    this->isLocked = status;
}

void DoorLocks::Lock() {
    this->isLocked = true;
}

void DoorLocks::Unlock() {
    this->isLocked = false;
}

void DoorLocks::Close() {
    this->isOpen = false;
}

void DoorLocks::readFromFile() {
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\DoorLocks.txt");

    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    if (file.size() == 0){
        qDebug() << "file empty";
        mainWindow->setDoorOnStartUp(0, 1);
        return;
    }

    QTextStream in(&file);

    QString input = in.readLine();

    input = input.simplified();

    QStringList inputs = input.split(" ");

    setOpen(inputs[0].toInt());
    setLocked(inputs[1].toInt());

    mainWindow->setDoorOnStartUp(this->checkOpen(), this->checkLocked());

    file.close();
}

void DoorLocks::autoClose() {
    QTimer* timer = new QTimer();
    timer->setInterval(10);
    timer->start();
    this->isOpen = false;
}

void DoorLocks::autoLock() {
    QDeadlineTimer deadline(5000);
    while(!deadline.hasExpired()) {

    }
    this->isLocked = false;
}

void MainWindow::setDoorOnStartUp(bool lockStatus, bool openStatus) {

    if (!openStatus){

        ui->doorOpenMonitor->setText("DOOR CLOSED");
        ui->doorOpenMonitor->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
        ui->doorOpenControl->setText("DOOR CLOSED");
        ui->doorOpenControl->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
    }
    else {

        ui->doorOpenMonitor->setText("DOOR OPEN");
        ui->doorOpenMonitor->setStyleSheet(
            "background-color: red;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
        ui->doorOpenControl->setText("DOOR OPEN");
        ui->doorOpenControl->setStyleSheet(
            "background-color: red;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
    }

    if(lockStatus) {

        ui->doorLockedMonitor->setText("DOOR LOCKED") ;
        ui->doorLockedMonitor->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
        ui->doorLockedControl->setText("DOOR LOCKED");
        ui->doorLockedControl->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
    }
    else {
        ui->doorLockedMonitor->setText("DOOR UNLOCKED");
        ui->doorLockedMonitor->setStyleSheet(
            "background-color: red;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
        ui->doorLockedControl->setText("DOOR UNLOCKED");
        ui->doorLockedControl->setStyleSheet(
            "background-color: red;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            "vertical-align: middle;"
            );
    }
}

void MainWindow::on_lockDoor_clicked() {
    doors->Lock();
        ui->doorLockedMonitor->setText("DOOR LOCKED") ;
        ui->doorLockedMonitor->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            "vertical-align: middle;"
            );
        ui->doorLockedControl->setText("DOOR LOCKED");
        ui->doorLockedControl->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            "vertical-align: middle;"
            );
    AuditLogs *logger = new AuditLogs(QString("Door Is Now Locked"));
    delete logger;
}

void MainWindow::on_unlockDoor_clicked() {
    doors->Unlock();
    ui->doorLockedMonitor->setText("DOOR UNLOCKED");
    ui->doorLockedMonitor->setStyleSheet(
        "background-color: red;"
        "color: white;"
        "border: 2px solid gray;"
        "border-radius: 5px;"
        "font-size: 16px;"
        "text-align: center;"
        "vertical-align: middle;"
        );
    ui->doorLockedControl->setText("DOOR UNLOCKED");
    ui->doorLockedControl->setStyleSheet(
        "background-color: red;"
        "color: white;"
        "border: 2px solid gray;"
        "border-radius: 5px;"
        "font-size: 16px;"
        "text-align: center;"
        "vertical-align: middle;"
        );
    AuditLogs *logger = new AuditLogs(QString("Door Is Now Unlocked"));
    delete logger;
}

void MainWindow::on_closeDoor_clicked() {
    doors->Close();
    ui->doorOpenMonitor->setText("DOOR CLOSED");
    ui->doorOpenMonitor->setStyleSheet(
        "background-color: green;"
        "color: white;"
        "border: 2px solid gray;"
        "border-radius: 5px;"
        "font-size: 16px;"
        "text-align: center;"
        "vertical-align: middle;"
        );
    ui->doorOpenControl->setText("DOOR CLOSED");
    ui->doorOpenControl->setStyleSheet(
        "background-color: green;"
        "color: white;"
        "border: 2px solid gray;"
        "border-radius: 5px;"
        "font-size: 16px;"
        "text-align: center;"
        );
    AuditLogs *logger = new AuditLogs(QString("Door Is Now Closed"));
    delete logger;
}
