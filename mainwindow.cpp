#include "mainwindow.h"
#include "ui_PrincipalForm.h"
#include "GUI/reports.h"
#include "GUI/intake.h"
#include "GUI/discharged.h"
#include "GUI/maintenance.h"
#include "GUI/patient.h"
#include "GUI/escorting.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Principal_QW)
{
    //ui->setupUi(Ui_Form_Principal_QW);
//        QWidget *widget = new QWidget;
//        widget->showMaximized();
//        Ui::Form_Principal_QW ui;
        ui->setupUi(this);

        ui->stackedWidget_Principal->insertWidget(0, new Patient(this));
        ui->stackedWidget_Principal->insertWidget(1, new Intake(this));
        ui->stackedWidget_Principal->insertWidget(2, new Escorting(this));
        ui->stackedWidget_Principal->insertWidget(3, new Discharged(this));
        ui->stackedWidget_Principal->insertWidget(4, new Reports(this));
        ui->stackedWidget_Principal->insertWidget(5, new Maintenance(this));
//        ui.widgetPrincipal->showFullScreen();
//        widget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
