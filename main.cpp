#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QWidget *widget = new QWidget;
//    widget->showMaximized();

//    Ui::Form_Principal_QW ui;
//    ui.setupUi(widget);
//    ui.widgetPrincipal->showFullScreen();

    //widget->show();

    MainWindow main;
    main.showMaximized();

    return a.exec();
}
