#ifndef THERMOSTAT_H
#define THERMOSTAT_H

//#include "mainwindow.h"
//#include "ui_mainwindow.h"

class MainWindow;

class Thermostat {

    int currentTemp;
    int targetTemp;
    bool fanStatus;

    MainWindow *mainWindow;

public:

    Thermostat(MainWindow*);
    ~Thermostat();

    int getTemp();
    void setTemp(int);
    bool getFanStatus();
    void setFanStatus(int);
    void toggleFan();

    void readFromFile();
    void writeToFile();
};

#endif // THERMOSTAT_H
