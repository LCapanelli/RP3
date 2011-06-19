#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_PrincipalForm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Form_Principal_QW)
{
    //ui->setupUi(Ui_Form_Principal_QW);
        QWidget *widget = new QWidget;
        widget->showMaximized();
        Ui::Form_Principal_QW ui;
        ui.setupUi(widget);
        ui.widgetPrincipal->showFullScreen();
        widget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
