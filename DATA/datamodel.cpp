#include "datamodel.h"
#include <QtSql/QSqlDatabase>
#include <qdjango/QDjango.h>

DataModel::DataModel()
{
criarConexao();
Diagnostico exD; Usuario exUs; Paciente exPc; Intervencao in; ActAss ac;
exD.setExamples();
exUs.setUserExamples();
exPc.setPatExamples();
in.setExamplesOfInterventions();
ac.setExamplesOfActivitiesAndApraz();
}
