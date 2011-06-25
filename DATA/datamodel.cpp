#include "datamodel.h"
#include <QtSql/QSqlDatabase>
#include <qdjango/QDjango.h>

DataModel::DataModel()
{
criarConexao();
Diagnostico ex;
ex.setExamples();
}
