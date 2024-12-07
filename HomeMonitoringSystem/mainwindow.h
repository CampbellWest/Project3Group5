#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>

#include "smokealarmalertform.h"

#include "CampbellHeader/Thermostat.h"
#include "CampbellHeader/COMonitor.h"
#include "CampbellHeader/SmokeAlarm.h"
#include "TylerHeader/doorlocks.h"
#include "TylerHeader/garagedoor.h"
#include "TylerHeader/windows.h"
#include "CampbellHeader/AuditLogs.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setThermostatOnStartUp(int, bool);

    void setDoorOnStartUp(bool, bool);
    void setGarageOnStartUp(bool);
    void setWindowOnStartUp(bool);

    static MainWindow* instance() {
        return mainInstance;
    }

signals:
    void updateLogSignal();

public slots:
    void refreshLogs();

private slots:

    // Thermostat
    void on_ThermostatPush_clicked();
    void on_ToggleFan_clicked();


    // CO Monitor
    // Smoke Alarm
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    //Door Locks
    void on_lockDoor_clicked();
    void on_unlockDoor_clicked();
    void on_closeDoor_clicked();


    //Garage Door
    void on_closeGarage_clicked();
    //Windows
    void on_lockWindow_clicked();
    void on_unlockWindow_clicked();

    void on_ClearLogs_clicked();

private:
    Ui::MainWindow *ui;

    static MainWindow *mainInstance;

    // Campbell's Classes
    Thermostat *thermostat;
    COMonitor *coMonitor;
    SmokeAlarm *smokeAlarm;
    AuditLogs *auditLogs;

    SmokeAlarmAlertForm *smokeAlarmPopup;

    // Tyler's Classes
    DoorLocks *doors;
    GarageDoor *garage;
    Windows *window;
    QTimer* timer;

    // can add variables to use else where
    // example for the path you have to use for files
    //QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
};

#endif // MAINWINDOW_H
