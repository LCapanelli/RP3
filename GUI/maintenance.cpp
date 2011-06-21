#include "maintenance.h"
#include "ui_maintenance.h"

Maintenance::Maintenance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Maintenance)
{
    ui->setupUi(this);
}

Maintenance::~Maintenance()
{
    delete ui;
}
