#ifndef DEVICE_H
#define DEVICE_H

#include <QString>

#define MINUTEDELAY	5

class MainWindow;

class Device {
protected:
    QString deviceName;
    QString homeLocation;
    bool status;

    MainWindow *mainWindow;

public:
    Device(MainWindow*);
    ~Device();

    QString getName();
    void setName(QString);

    QString getLocation();
    void setLocation(QString);

    bool getStatus();
    void setStatus(bool);

    void readFromFile();
    void passDatatoHMI();
};

#endif //DEVICE_H
