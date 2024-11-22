#ifndef LOCKS_H
#define LOCKS_H

#endif // LOCKS_H

#include "device.h"

//change to declarations

class Locks : protected Device {
protected:
    bool isOpen;
    bool isLocked;

public:
    Locks();
    void Lock(void);
    void Unlock(void);
    void Close(void);
    bool checkLocked(void);
    bool checkOpen(void);
};
