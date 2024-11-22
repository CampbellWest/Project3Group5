#ifndef DEVICE_H
#define DEVICE_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <future>

#define MINUTEDELAY	5

class DeviceData;

class Device
{
    Q_OBJECT
    QML_ELEMENT
public:
    Device();
    Device(const Device &);
    Device &operator=(const Device &);
    ~Device();

private:
    QSharedDataPointer<DeviceData> data;
};

#endif // DEVICE_H


class Device {
protected:
    string deviceName;
    string homeLocation;
    bool status;

public:
    Device();

    Device(string name, string location, bool status);
    void readFile(string filePath);
    void passDatatoHMI(void);
};
