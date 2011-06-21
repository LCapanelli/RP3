#include "intake.h"
#include "ui_intake.h"

Intake::Intake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Intake)
{
    ui->setupUi(this);
}

Intake::~Intake()
{
    delete ui;
}
