#ifndef DOORLOCKS_H
#define DOORLOCKS_H

#include <QString>
#include "CampbellHeader/AuditLogs.h"

class MainWindow;

class DoorLocks  {

    MainWindow *mainWindow;

    bool isOpen;
    bool isLocked;

    QString deviceName;
    QString homeLocation;
    bool status;

public:
    DoorLocks(MainWindow*);
    ~DoorLocks();

    bool checkOpen();
    void setOpen(bool);

    bool checkLocked();
    void setLocked(bool);

    void Lock();
    void Unlock();

    void Close();

    void autoClose();
    void autoLock();

    void readFromFile();

};

#endif // DOORLOCKS_H
