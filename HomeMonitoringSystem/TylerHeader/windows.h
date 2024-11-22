#ifndef WINDOWS_H
#define WINDOWS_H

#endif // WINDOWS_H

#include "locks.h"

class Windows : protected Locks {
public:
    Windows();
    void autoLock(Windows& window);
};
