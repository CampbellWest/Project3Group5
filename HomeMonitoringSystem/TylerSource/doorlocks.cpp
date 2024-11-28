#include "../TylerHeader/doorlocks.h"
#include "mainwindow.h"

#include "QString"
#include <QTimer>
#include <QObject>

DoorLocks::DoorLocks(MainWindow* parentWindow) {
    this->mainWindow = parentWindow;

    readFromFile();

    mainWindow->setDoorLocksOnStartUp(this->getOpen(), this->getLocked());
}

bool DoorLocks::checkOpen() {
    if(this->isOpen == true)
        return true;
    return false;
}

bool DoorLocks::checkLocked() {
    if(this->isLocked == true)
        return true;
    return false;
}

void DoorLocks::Lock() {
    this->isLocked = true;
}

void DoorLocks::Unlock() {
    this->isLocked = false;
}

void DoorLocks::Close() {
    this->isOpen = false;
}


void DoorLocks::autoClose(DoorLocks& door) {
    if (door.checkOpen()) {

        door.isOpen = false;
    }
}

void DoorLocks::autoLock(DoorLocks& door) {
    if (!door.checkLocked()) {

        door.isLocked = true;
}
