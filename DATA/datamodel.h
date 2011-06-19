#ifndef DATAMODEL_H
#define DATAMODEL_H
#import <QSqlDatabase>
#import <qdjango/QDjango.h>
#import <qdjango/QDjangoModel.h>
#include "diagnostico.h"

class DataModel
{
public:
    DataModel();
    QSqlDatabase db;

    bool criarConexao(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("RP3");
    db.setDatabaseName("sae");
    db.setUserName("sae");
    db.setPassword("sae0192");
    db.open();

    QDjango::setDatabase(db);
    QDjango::registerModel<diagnostico>();
    QDjango::createTables();

    if (! db.open() ) {

    return false; }
    return true; }
};


#endif // DATAMODEL_H
