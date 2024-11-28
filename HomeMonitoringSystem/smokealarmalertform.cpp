#include "smokealarmalertform.h"
#include "ui_smokealarmalertform.h"

SmokeAlarmAlertForm::SmokeAlarmAlertForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SmokeAlarmAlertForm)
{
    ui->setupUi(this);
}

SmokeAlarmAlertForm::~SmokeAlarmAlertForm()
{
    delete ui;
}

void SmokeAlarmAlertForm::updateLabelText(QString text) {
    ui->AlarmLabel->setText(text);
}

void SmokeAlarmAlertForm::on_pushButton_clicked()
{
    this->close();
}
