#ifndef GARAGEDOOR_H
#define GARAGEDOOR_H

#endif // GARAGEDOOR_H

#include "locks.h"

class GarageDoor : protected Locks {
public:
    GarageDoor();
    void autoClose(GarageDoor& door);
};
