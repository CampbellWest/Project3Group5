#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "smokealarmalertform.h"

#include <QFile>
//#include <QStandardPaths>
#include <QMessageBox>
//#include <qthread.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , smokeAlarmPopup(nullptr)
{
    ui->setupUi(this);
    // place to put code when the program starts
    // files reads

    this->thermostat = new Thermostat(this);
    this->coMonitor = new COMonitor();
    this->smokeAlarm = new SmokeAlarm();

}

MainWindow::~MainWindow()
{
    // can put code you want at the end of the program
    // file writes
    delete ui;

    delete thermostat;
    delete coMonitor;
    delete smokeAlarm;
}






