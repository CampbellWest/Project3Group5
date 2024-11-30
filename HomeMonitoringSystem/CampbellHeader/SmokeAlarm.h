#ifndef SMOKEALARM_H
#define SMOKEALARM_H

class SmokeAlarm {
    bool alarmStatus;

public:

    SmokeAlarm();

    void toggleAlarm();
    bool checkForSmoke();
};

#endif // SMOKEALARM_H
