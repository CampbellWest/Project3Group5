#include "locks.h"

class LocksData : public QSharedData
{
public:
};

Locks::Locks()
    : data(new LocksData)
{}

Locks::Locks(const Locks &rhs)
    : data{rhs.data}
{}

Locks &Locks::operator=(const Locks &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Locks::~Locks() {}


class Locks : protected Device {
protected:
    bool isOpen;
    bool isLocked;

public:
    Locks() {
        this->isOpen = false;
        this->isLocked = false;
    }
    void Lock(void) {
        this->isLocked = true;
    }
    void Unlock(void) {
        this->isLocked = false;
    }
    void Close(void) {
        this->isOpen = false;
    }
    bool checkLocked(void) {
        if (this->isLocked == true)
            return true;
        return false;
    }
    bool checkOpen(void) {
        if (this->isOpen == true)
            return true;
        return false;
    }
};
