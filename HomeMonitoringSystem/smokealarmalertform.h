#ifndef SMOKEALARMALERTFORM_H
#define SMOKEALARMALERTFORM_H

#include <QWidget>

namespace Ui {
class SmokeAlarmAlertForm;
}

class SmokeAlarmAlertForm : public QWidget
{
    Q_OBJECT

public:
    explicit SmokeAlarmAlertForm(QWidget *parent = nullptr);
    ~SmokeAlarmAlertForm();

    void hidePopup();
    void updateLabelText(QString);

private slots:
    void on_pushButton_clicked();


private:
    Ui::SmokeAlarmAlertForm *ui;

};

#endif // SMOKEALARMALERTFORM_H
