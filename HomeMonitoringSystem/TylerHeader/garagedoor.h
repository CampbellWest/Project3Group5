#ifndef GARAGEDOOR_H
#define GARAGEDOOR_H

#include <QString>
#include "CampbellHeader/AuditLogs.h"

class MainWindow;

class GarageDoor {

    MainWindow *mainWindow;

    bool isOpen;

    QString deviceName;
    QString homeLocation;
    bool status;

public:
    GarageDoor(MainWindow*);
    ~GarageDoor();

    bool checkOpen();
    void setOpen(bool status);

    void Close();

    void readFromFile();

    void autoClose(GarageDoor& door);
};

#endif // GARAGEDOOR_H
