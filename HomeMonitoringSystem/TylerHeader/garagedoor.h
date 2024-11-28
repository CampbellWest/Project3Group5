#ifndef GARAGEDOOR_H
#define GARAGEDOOR_H

//#include "locks.h"
#include <QString>

class MainWindow;

class GarageDoor {
protected:
    MainWindow *mainWindow;

    bool isOpen;

    QString deviceName;
    QString homeLocation;
    bool status;

public:
    GarageDoor(MainWindow*);
    ~GarageDoor();

    bool checkOpen();

    void Close();

    void autoClose(GarageDoor& door);
};

#endif // GARAGEDOOR_H
