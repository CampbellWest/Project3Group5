#ifndef AUDITLOGS_H
#define AUDITLOGS_H

#include <QVector>
#include <QString>
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>

class MainWindow;

class AuditLogs {
    //QVector <QString> logHistory;
    //QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\AuditLogs.txt");
    QString path;

    MainWindow *mainWindow;

public:

    AuditLogs(QString log = "EMPTY");

    void addEntry(QString);
    QVector <QString> readLogsFromFile();
    void clearLogs();
};

#endif // AUDITLOGS_H
