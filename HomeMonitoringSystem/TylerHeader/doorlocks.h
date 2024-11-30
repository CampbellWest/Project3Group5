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
    void setOpen(bool);

    bool checkLocked();
    void setLocked(bool);

    void Lock();
    void Unlock();

    void Close();

    void autoClose(DoorLocks& door);
    void autoLock(DoorLocks& door);

    void readFromFile();

};

#endif // DOORLOCKS_H
