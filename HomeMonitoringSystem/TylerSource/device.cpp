#include "../TylerHeader/device.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <Qstring>
#include <QObject>
#include <QTextStream>
#include "QFile"
#include "QMessageBox"

Device::Device(MainWindow *parentWindow) {
    this->mainWindow = parentWindow;

    readFromFile();

}

Device::~Device() {

}
QString Device::getName() {
    return this->deviceName;
}

void Device::setName(QString name) {
    this->deviceName = name;
}

QString Device::getLocation() {
    return this->homeLocation;
}

void Device::setLocation(QString location) {
    this->homeLocation = location;
}

bool Device::getStatus() {
    return this->status;
}

void Device::setStatus(bool status) {
    this->status = status;
}
