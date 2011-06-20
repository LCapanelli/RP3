#ifndef DATAMODEL_H
#define DATAMODEL_H
#import <qdjango/QDjango.h>
#import <qdjango/QDjangoModel.h>
#include "diagnostico.h"

class DataModel
{
public:
    DataModel();
    QSqlDatabase db;

    void criarConexao(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sae.db");
    db.open();

    QDjango::setDatabase(db);
    QDjango::registerModel<Diagnostico>();
    QDjango::createTables();


//    if (!db.open()) {
//    return false; }
//    return true;
}
};

#endif // DATAMODEL_H
