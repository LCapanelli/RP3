#include "discharged.h"
#include "ui_discharged.h"

Discharged::Discharged(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Discharged)
{
    ui->setupUi(this);
}

Discharged::~Discharged()
{
    delete ui;
}
