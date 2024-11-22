#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>

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

private slots:


    void on_ThermostatPush_clicked();

    void on_ToggleFan_clicked();

private:
    Ui::MainWindow *ui;
    // can add variables to use else where
    // example for the path you have to use for files
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    bool FanOn = false;
};

#endif // MAINWINDOW_H
