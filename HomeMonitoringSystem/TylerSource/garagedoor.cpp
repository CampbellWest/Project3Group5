#include "../TylerHeader/garagedoor.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QFile"
#include "QString"
#include "QMessageBox"

GarageDoor::GarageDoor(MainWindow *parentWindow) {
    this->mainWindow = parentWindow;

    readFromFile();

    mainWindow->setGarageOnStartUp(this->checkOpen());
}

GarageDoor::~GarageDoor() {}

bool GarageDoor::checkOpen() {
    if(this->isOpen == true)
        return true;
    return false;
}

void GarageDoor::setOpen(bool status) {
    this->isOpen = status;
}

void GarageDoor::Close() {
    this->isOpen = false;
}

void GarageDoor::readFromFile() {
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\GarageDoor.txt");

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

    mainWindow->setGarageOnStartUp(this->checkOpen());

    file.close();
}

void GarageDoor::autoClose(GarageDoor& door) {
    if (door.checkOpen()) {

        door.isOpen = false;
    }
}

void MainWindow::setGarageOnStartUp(bool openStatus) {

    if (!openStatus){

        ui->garageOpenMonitor->setText("GARAGE CLOSED");
        ui->garageOpenMonitor->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
        ui->garageOpenControl->setText("GARAGE CLOSED");
        ui->garageOpenControl->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
    }
    else {

        ui->garageOpenMonitor->setText("GARAGE OPEN");
        ui->garageOpenMonitor->setStyleSheet(
            "background-color: red;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
        ui->garageOpenControl->setText("GARAGE OPEN");
        ui->doorOpenControl->setStyleSheet(
            "background-color: red;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
    }
}

void MainWindow::on_closeGarage_clicked() {
    garage->Close();
    ui->garageOpenMonitor->setText("GARAGE CLOSED");
    ui->garageOpenMonitor->setStyleSheet(
        "background-color: green;"
        "color: white;"
        "border: 2px solid gray;"
        "border-radius: 5px;"
        "font-size: 16px;"
        "text-align: center;"
        "vertical-align: middle;"
        );
    ui->garageOpenControl->setText("GARAGE CLOSED");
    ui->garageOpenControl->setStyleSheet(
        "background-color: green;"
        "color: white;"
        "border: 2px solid gray;"
        "border-radius: 5px;"
        "font-size: 16px;"
        "text-align: center;"
        );
    AuditLogs *logger = new AuditLogs(QString("Garage Is Now Closed"));
    delete logger;
}
