

#include "doorlocks.h"

class DoorLocks : protected Locks {
public:
    DoorLocks() {
        this->deviceName = "Door";
        this->homeLocation = "";
        this->status = true;
    }
    void autoClose(DoorLocks& door) {
        if (door.checkOpen()) {

            door.isOpen = false;
        }
    }
    void autoLock(DoorLocks& door) {
        if (!door.checkLocked()) {

            door.isLocked = true;
        }
    }
};
