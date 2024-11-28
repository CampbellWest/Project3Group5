#ifndef COMONITOR_H
#define COMONITOR_H

class COMonitor {

    float currentCOLevel;
    float safeThreshold = 50.0;

public:

    COMonitor();

    float getCOLevel();
    void alertUnsafe();
};

#endif // COMONITOR_H
