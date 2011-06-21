#include "reports.h"
#include "ui_reports.h"

Reports::Reports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reports)
{
    ui->setupUi(this);
}

Reports::~Reports()
{
    delete ui;
}
