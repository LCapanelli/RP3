#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_PrincipalForm.h"
#include "diagnostico.h"

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
//SLOT de testes, testamos caso ficaria melhor aqui ou na diagnostico.cpp
//void MainWindow::on_pb_SalvarDiag_clicked()
//{
//    if(!ui->le_nomeDiag->text().isEmpty()){
//    Diagnostico *u = new Diagnostico(this);
//    u->setNomeDiag(ui->le_nomeDiag->text());
//    u->save();
//    ui->le_nomeDiag->clear();
//    }
//}
