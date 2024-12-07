#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "smokealarmalertform.h"

#include <QDebug>
#include <QFile>
//#include <QStandardPaths>
#include <QMessageBox>
//#include <qthread.h>

MainWindow* MainWindow::mainInstance = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , smokeAlarmPopup(nullptr)
{

    connect(this, &MainWindow::updateLogSignal, this, &MainWindow::refreshLogs);

    ui->setupUi(this);
    mainInstance = this;
    // place to put code when the program starts
    // files reads

    this->thermostat = new Thermostat(this);
    this->coMonitor = new COMonitor();
    this->smokeAlarm = new SmokeAlarm();
    this->doors = new DoorLocks(this);
    this->garage = new GarageDoor(this);
    this->window = new Windows(this);
    this->auditLogs = new AuditLogs();
    refreshLogs();
}

MainWindow::~MainWindow()
{
    // can put code you want at the end of the program
    // file writes
    delete ui;

    delete thermostat;
    delete coMonitor;
    delete smokeAlarm;
    delete auditLogs;
    delete doors;
    delete garage;
    delete window;
}

void MainWindow::refreshLogs() {
    QVector<QString> logs = auditLogs->readLogsFromFile();
    ui->LogList->clear();

    for(int i = 0; i < logs.count(); i++)
        ui->LogList->addItem(logs[i]);

}



