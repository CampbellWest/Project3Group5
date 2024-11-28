#ifndef DOORLOCKS_H
#define DOORLOCKS_H

#include <QString>

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
    bool checkLocked();

    void Lock();
    void Unlock();

    void Close();

    void autoClose(DoorLocks& door);
    void autoLock(DoorLocks& door);

};

#endif // DOORLOCKS_H
