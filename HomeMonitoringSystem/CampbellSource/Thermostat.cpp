#include "../CampbellHeader/Thermostat.h"
#include "CampbellHeader/AuditLogs.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QFile"
#include "QMessageBox"

Thermostat::Thermostat(MainWindow *parentWindow){
    this->mainWindow = parentWindow;

    readFromFile();
}

Thermostat::~Thermostat() {
    writeToFile();
}

int Thermostat::getTemp() {
    return this->currentTemp;
}

void Thermostat::setTemp(int temp) {
    this->currentTemp = temp;
}

void Thermostat::setFanStatus(int fanStatus) {
    this->fanStatus = fanStatus;
}

void Thermostat::toggleFan() {
    if (getFanStatus()) {
        this->fanStatus = false;
    } else {
        this->fanStatus = true;
    }

    AuditLogs *logger = new AuditLogs(QString("Fan toggle to ") + (getFanStatus() ? "On" : "Off"));
    delete logger;
}

bool Thermostat::getFanStatus() {
    return this->fanStatus;
}

void Thermostat::readFromFile() {
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\Thermostat.txt");

    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    if (file.size() == 0){
        qDebug() << "file empty";
        setTemp(20);
        setFanStatus(1);
        mainWindow->setThermostatOnStartUp(getTemp(), getFanStatus());
        return;
    }

    QTextStream in(&file);

    QString input = in.readLine();

    input = input.simplified();

    QStringList inputs = input.split(" ");

    setTemp(inputs[0].toInt());
    setFanStatus(inputs[1].toInt());

    mainWindow->setThermostatOnStartUp(getTemp(), getFanStatus());

    file.close();
}

void Thermostat::writeToFile() {
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\Thermostat.txt");

    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);

    QString output = QString::number(getTemp()) + " " + (getFanStatus() ? "1" : "0");

    out << output;

    file.close();
}

void MainWindow::setThermostatOnStartUp(int temp, bool fanStatus) {
    ui->ThermostatNumber->display(temp);
    if (fanStatus){

        ui->FanMonitor->setText("FAN OFF");
        ui->FanMonitor->setStyleSheet(
            "background-color: red;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
        ui->FanLabel->setStyleSheet(
            "background-color: red;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
    } else {

        ui->FanMonitor->setText("FAN ON");
        ui->FanMonitor->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
        ui->FanLabel->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
    }
}

void MainWindow::on_ThermostatPush_clicked() {
    QString temp = ui->ThermoStatInput->text();

    int tempInt = temp.toInt();

    if(tempInt >= 5 && tempInt <= 30) {
        ui->ThermostatNumber->display(tempInt);
        ui->ThermoStatInput->clear();

        thermostat->setTemp(tempInt);

        AuditLogs *logger = new AuditLogs(QString("Thermostat set to ") + QString::number(thermostat->getTemp()));
        delete logger;
    }
}

void MainWindow::on_ToggleFan_clicked() {
    thermostat->toggleFan();
    if (thermostat->getFanStatus()){

        ui->FanMonitor->setText("FAN OFF");
        ui->FanMonitor->setStyleSheet(
            "background-color: red;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
        ui->FanLabel->setStyleSheet(
                "background-color: red;"
                "color: white;"
                "border: 2px solid gray;"
                "border-radius: 5px;"
                "font-size: 16px;"
                "text-align: center;"
            );
    } else {

        ui->FanMonitor->setText("FAN ON");
        ui->FanMonitor->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
        ui->FanLabel->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
    }
}

