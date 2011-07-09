#include <QtGui/QApplication>
#include "mainwindow.h"
#include "DATA/datamodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QWidget *widget = new QWidget;
//    widget->showMaximized();

//    Ui::Form_Principal_QW ui;
//    ui.setupUi(widget);
//    ui.widgetPrincipal->showFullScreen();

    //widget->show();
    a.setStyleSheet("QLineEdit{color: #806600; background-color: #F6FFD5; }");
    DataModel data;
    data.criarConexao();
    MainWindow main;
    main.showMaximized();
    return a.exec();
}
