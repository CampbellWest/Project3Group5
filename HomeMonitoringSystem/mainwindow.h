#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>

#include "smokealarmalertform.h"

#include "CampbellHeader/Thermostat.h"
#include "CampbellHeader/COMonitor.h"
#include "CampbellHeader/SmokeAlarm.h"

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

private slots:

    // Thermostat
    void on_ThermostatPush_clicked();
    void on_ToggleFan_clicked();


    // CO Monitor

    // Smoke Alarm
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    // Campbell's Classes
    Thermostat *thermostat;
    COMonitor *coMonitor;
    SmokeAlarm *smokeAlarm;

    SmokeAlarmAlertForm *smokeAlarmPopup;

    // can add variables to use else where
    // example for the path you have to use for files
    //QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
};

#endif // MAINWINDOW_H
