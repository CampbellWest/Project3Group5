#ifndef WINDOWS_H
#define WINDOWS_H

#include <QString>
#include "CampbellHeader/AuditLogs.h"

class MainWindow;

class Windows {

    MainWindow *mainWindow;

    bool isLocked;

    QString deviceName;
    QString homeLocation;
    bool status;

public:
    Windows(MainWindow*);
    ~Windows();

    bool checkLocked();
    void setLocked(bool);

    void Lock();
    void Unlock();

    void readFromFile();

    void autoLock(Windows& window);
};

#endif // WINDOWS_H
