#include "datamodel.h"
#include <QtSql/QSqlDatabase>
#include <qdjango/QDjango.h>

DataModel::DataModel()
{
criarConexao();
Diagnostico exD; Usuario exUs;
exD.setExamples();
exUs.setUserExamples();
}
