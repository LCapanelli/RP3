#include "escorting.h"
#include "ui_escorting.h"

Escorting::Escorting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Escorting)
{
    ui->setupUi(this);
}

Escorting::~Escorting()
{
    delete ui;
}
