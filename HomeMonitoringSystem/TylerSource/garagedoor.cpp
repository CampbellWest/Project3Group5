#include "../TylerHeader/garagedoor.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QFile"
#include "QString"

GarageDoor::GarageDoor(MainWindow *parentWindow) {
    this->mainWindow = parentWindow;

    readFromFile();

    mainWindow->setGarageDoorOnStartUp(this->getOpen());
}

bool GarageDoor::checkOpen() {
    if(this->isOpen == true)
        return true;
    return false;
}

void GarageDoor::Close() {
    this->isOpen = false;
}

void GarageDoor::autoClose(GarageDoor& door) {
    if (door.checkOpen()) {

        door.isOpen = false;
    }
}
