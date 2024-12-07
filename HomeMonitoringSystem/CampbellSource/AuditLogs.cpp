#include "../CampbellHeader/AuditLogs.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QString>
#include <QDebug>

AuditLogs::AuditLogs(QString log){
    this->path = (QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\AuditLogs.txt");
    if (log != "EMPTY") {
        addEntry(log);
    }
}

void AuditLogs::addEntry(QString log) {

    QFile file(this->path);
    QString oldLogs;

    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    oldLogs = in.readAll();
    file.close();

    QDateTime currentDateTime = QDateTime::currentDateTime();

    QString timestamp = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");

    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream out(&file);
    QString space = " ";
    out << (log + " - " + timestamp +'\n');
    out << oldLogs;
    file.close();

    emit MainWindow::instance()->updateLogSignal();
}

QVector<QString> AuditLogs::readLogsFromFile() {

    QFile file(this->path);
    QVector<QString> logs;

    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    for (int i = 0; i < 22; i++) {
        if (in.atEnd()) {
            break;
        }
        logs.append(in.readLine());
    }

    file.close();

    return logs;
}
