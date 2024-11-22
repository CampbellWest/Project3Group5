


#include "windows.h"

class Windows : protected Locks {
public:
    Windows() {
        this->deviceName = "Window";
        this->homeLocation = "";
        this->status = true;
    }
    void autoLock(Windows& window) {
        if (!window.checkLocked()) {

            window.isLocked = true;
        }
    }
};
