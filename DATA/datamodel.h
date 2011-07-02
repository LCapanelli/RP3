#ifndef DATAMODEL_H
#define DATAMODEL_H
#include <qdjango/QDjango.h>
#include <qdjango/QDjangoModel.h>
#include "diagnostico.h"
#include "usuario.h"
#include "intervencao.h"
#include "paciente.h"
#include <QtSql/QSqlDatabase>

class DataModel
{
public:
    DataModel();
    QSqlDatabase db;

    void criarConexao(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("sae");
    db.setUserName("sae");
    db.setPassword("sae0192");
    db.setPort(3306);
    db.open();

    QDjango::setDatabase(db);
    QDjango::registerModel<Diagnostico>();
    QDjango::registerModel<Usuario>();
    QDjango::registerModel<Intervencao>();
    QDjango::registerModel<Paciente>();
    QDjango::createTables();

//    if (!db.open()) {
//    return false; }
//    return true;
}
};

#endif // DATAMODEL_H
