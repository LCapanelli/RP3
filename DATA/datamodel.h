#ifndef DATAMODEL_H
#define DATAMODEL_H
#import "qdjango/QDjango.h"
#import "qdjango/QDjangoModel.h"
#include "diagnostico.h"
#include "qdjango/QDjangoScript.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

class DataModel
{
public:
    DataModel();

    void criarConexao(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sae.db");
    db.open();

    QDjango::setDatabase(db);QDjango::
    QDjango::registerModel<Diagnostico>();
    QDjango::createTables();


// Este método era booleano
//    if (!db.open()) {
//    return false; }
//    return true;
}
};

#endif // DATAMODEL_H
