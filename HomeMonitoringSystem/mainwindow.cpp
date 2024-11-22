#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <qthread.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // place to put code when the program starts
    // files reads
}

MainWindow::~MainWindow()
{
    // can put code you want at the end of the program
    // file writes

    delete ui;
}

void MainWindow::on_ThermostatPush_clicked()
{
    QString temp = ui->ThermoStatInput->text();

    int tempInt = temp.toInt();

    ui->ThermostatNumber->display(tempInt);
}

void MainWindow::on_ToggleFan_clicked()
{
    if (!FanOn){
        FanOn = true;
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
        FanOn = false;
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

