#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <future>

#define MINUTEDELAY	5

using namespace std;

int main(void) {
    class Device {
    protected:
        string deviceName;
        string homeLocation;
        bool status;

    public:
        Device() {
            this->deviceName = "";
            this->homeLocation = "";
            this->status = NULL;
        }

        Device(string name, string location, bool status) {
            this->deviceName = name;
            this->homeLocation = location;
            this->status = status;
        }
        void readFile(string filePath) {

        }
        void passDatatoHMI(void) {

        }
    };

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

}
