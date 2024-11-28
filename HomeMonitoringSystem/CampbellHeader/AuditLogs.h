#ifndef AUDITLOGS_H
#define AUDITLOGS_H

#include <QVector>
#include <QString>

class AuditLogs {
    QVector <QString> logHistory;
    QString filePath;

public:

    QString createEntry(/* Take in a 'device' and make entry based off of that */);
    void addEntry();
    QVector <QString> readLogsFromFile();
};


#endif // AUDITLOGS_H
