#include "diagass.h"
#include "qdjango/QDjango.h"

DiagAss::DiagAss(QObject *parent) :
        QDjangoModel(parent)
{
}

qint32 DiagAss::idDiagAss() const{
    return m_idDiagAss;
}
void DiagAss::setIdDiagAss(const qint32 & idDiagAss){
    m_idDiagAss = idDiagAss;
}

QString DiagAss::patientNameIntakeFK() const{
    return m_patientNameIntakeFK;
}
void DiagAss::setPatientNameIntakeFK(const QString & PatientNameIntakeFK){
    m_patientNameIntakeFK = PatientNameIntakeFK;
}

QDateTime DiagAss::dHour() const{
    return m_dHour;
}
void DiagAss::setDhour(const QDateTime & dHour){
    m_dHour = dHour;
}

QString DiagAss::diagAssNAME() const {
    return m_diagAssNAME;
}
void DiagAss::setDiagAssNAME(const QString &diagAssNAME){
    m_diagAssNAME = diagAssNAME;
}
