#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "ui_PrincipalForm.h"
#include "GUI/reports.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Principal_QW)
{
    //ui->setupUi(Ui_Form_Principal_QW);
//        QWidget *widget = new QWidget;
//        widget->showMaximized();
//        Ui::Form_Principal_QW ui;
        ui->setupUi(this);


        ui->stackedWidget_2->insertWidget(4, new Reports(this));
//        ui.widgetPrincipal->showFullScreen();
//        widget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
