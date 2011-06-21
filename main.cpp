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
    new DataModel;
    new MainWindow;
//    Diagnostico *u = new Diagnostico(u);
//    u->setNomeDiag("blah");
//    u->save();

    return a.exec();
}
