#ifndef DOORLOCKS_H
#define DOORLOCKS_H

#endif // DOORLOCKS_H

#include "locks.h"

class DoorLocks : protected Locks {
public:
    DoorLocks();
    void autoClose(DoorLocks& door);
    void autoLock(DoorLocks& door);
};
