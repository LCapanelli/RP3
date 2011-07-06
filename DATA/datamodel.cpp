#include "datamodel.h"
#include <QtSql/QSqlDatabase>
#include <qdjango/QDjango.h>

DataModel::DataModel()
{
criarConexao();
Diagnostico exD; Usuario exUs; Paciente exPc; Intervencao in;
exD.setExamples();
exUs.setUserExamples();
exPc.setPatExamples();
in.setExamplesOfInterventions();
}
