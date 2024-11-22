#include "device.h"

class DeviceData : public QSharedData
{
public:

};

Device::Device() : data(new DeviceData)
{

}

Device::Device(const Device &rhs)
    : data{rhs.data}
{

}

Device &Device::operator=(const Device &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Device::~Device()
{

}


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
