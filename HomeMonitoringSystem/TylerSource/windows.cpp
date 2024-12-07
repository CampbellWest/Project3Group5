#include "../TylerHeader/windows.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QString"
#include "QFile"
#include "QMessageBox"
//#include "QComboBox"

Windows::Windows(MainWindow *parentWindow) {
    this->mainWindow = parentWindow;

    readFromFile();

    mainWindow->setWindowOnStartUp(this->checkLocked());
}

Windows::~Windows() {}

bool Windows::checkLocked() {
    if(this->isLocked == true)
        return true;
    return false;
}

void Windows::setLocked(bool status) {
    this->isLocked = status;
}

void Windows::Lock() {
    this->isLocked = true;
}

void Windows::Unlock() {
    this->isLocked = false;
}

void Windows::readFromFile() {
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\Windows.txt");

    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    if (file.size() == 0){
        //qDebug() << "file empty";
        mainWindow->setDoorOnStartUp(0, 1);
        return;
    }

    QTextStream in(&file);

    QString input = in.readLine();

    input = input.simplified();

    QStringList inputs = input.split(" ");

    setLocked(inputs[0].toInt());

    mainWindow->setWindowOnStartUp(this->checkLocked());

    file.close();
}

void Windows::autoLock(Windows& window) {
    if (!window.checkLocked()) {

        window.isLocked = true;
    }
}

void MainWindow::setWindowOnStartUp(bool lockStatus) {
    ui->windowDropDown->addItems({"Bedroom", "Kitchen"});
    ui->showWindow->addItems({"Bedroom", "Kitchen"});

    if(lockStatus) {

        ui->windowLockedMonitor->setText("WINDOW LOCKED") ;
        ui->windowLockedMonitor->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
        ui->windowLockedControl->setText("WINDOW LOCKED");
        ui->windowLockedControl->setStyleSheet(
            "background-color: green;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
    }
    else {

        ui->windowLockedMonitor->setText("WINDOW UNLOCKED");
        ui->windowLockedMonitor->setStyleSheet(
            "background-color: red;"
            "color: white;"
            "border: 2px solid gray;"
            "border-radius: 5px;"
            "font-size: 16px;"
            "text-align: center;"
            );
        ui->windowLockedControl->setText("WINDOW UNLOCKED");
        ui->windowLockedControl->setStyleSheet(
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

void MainWindow::on_lockWindow_clicked() {
    window->Lock();
    ui->windowLockedMonitor->setText("WINDOW LOCKED") ;
    ui->windowLockedMonitor->setStyleSheet(
        "background-color: green;"
        "color: white;"
        "border: 2px solid gray;"
        "border-radius: 5px;"
        "font-size: 16px;"
        "text-align: center;"
        );
    ui->windowLockedControl->setText("WINDOW LOCKED");
    ui->windowLockedControl->setStyleSheet(
        "background-color: green;"
        "color: white;"
        "border: 2px solid gray;"
        "border-radius: 5px;"
        "font-size: 16px;"
        "text-align: center;"
        );
    AuditLogs *logger = new AuditLogs(QString("Window Is Now Locked"));
    delete logger;
}
void MainWindow::on_unlockWindow_clicked() {
    window->Unlock();
    ui->windowLockedMonitor->setText("WINDOW UNLOCKED");
    ui->windowLockedMonitor->setStyleSheet(
        "background-color: red;"
        "color: white;"
        "border: 2px solid gray;"
        "border-radius: 5px;"
        "font-size: 16px;"
        "text-align: center;"
        );
    ui->windowLockedControl->setText("WINDOW UNLOCKED");
    ui->windowLockedControl->setStyleSheet(
        "background-color: red;"
        "color: white;"
        "border: 2px solid gray;"
        "border-radius: 5px;"
        "font-size: 16px;"
        "text-align: center;"
        "vertical-align: middle;"
        );
    AuditLogs *logger = new AuditLogs(QString("Window Is Now Unlocked"));
    delete logger;
}
