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

    ui->ThermostatNumber->display(0);

}

MainWindow::~MainWindow()
{
    // can put code you want at the end of the program
    // file writes

    delete ui;
}

