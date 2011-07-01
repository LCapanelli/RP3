#ifndef DATAMODEL_H
#define DATAMODEL_H
#include <qdjango/QDjango.h>
#include <qdjango/QDjangoModel.h>
#include "diagnostico.h"
#include "usuario.h"
#include "intervencao.h"

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
    QDjango::registerModel<Usuario>();
    QDjango::registerModel<Intervencao>();
    QDjango::createTables();

//    if (!db.open()) {
//    return false; }
//    return true;
}
};

#endif // DATAMODEL_H
