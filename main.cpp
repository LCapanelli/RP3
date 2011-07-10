#include <QtGui/QApplication>
#include "mainwindow.h"
#include "DATA/datamodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet("QLineEdit{color: #806600; background-color: #F6FFD5; padding: 1px; border-radius: 8px; border-style: solid; border: 2px solid gray; font-size: 15px;}");
    //a.setStyleSheet("#QToolBox{border-radius: 12px;}");
    //a.setStyleSheet("QLabel{font-size: 15px}");
    DataModel data;
    data.criarConexao();
    MainWindow main;
    main.showMaximized();
    return a.exec();
}
