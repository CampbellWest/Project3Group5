


#include "garagedoor.h"

class GarageDoor : protected Locks {
public:
    GarageDoor() {
        this->deviceName = "Garage Door";
        this->homeLocation = "Garage";
        this->status = true;
    }
    void autoClose(GarageDoor& door) {
        if (door.checkOpen()) {

            door.isOpen = false;
        }
    }
};
