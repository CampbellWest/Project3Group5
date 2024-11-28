#include "../TylerHeader/windows.h"

#include "QString"
#include "QFile"

bool Windows::checkLocked() {
    if(this->isLocked == true)
        return true;
    return false;
}

void Windows::Lock() {
    this->isLocked = true;
}

void Windows::Unlock() {
    this->isLocked = false;
}

void Windows::autoLock(Windows& window) {
    if (!window.checkLocked()) {

        window.isLocked = true;
    }
}
