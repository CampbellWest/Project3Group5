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
    void setName();

    QString getLocation();
    void setLocation();

    bool getStatus();
    void setStatus();

    void readfromFile(QString filePath);
    void passDatatoHMI(void);
};

#endif //DEVICE_H
