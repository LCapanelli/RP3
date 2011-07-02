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

qint32 DiagAss::idIntakeFK() const{
    return m_idIntakeFK;
}
void DiagAss::setIdIntakeFK(const qint32 & idIntakeFK){
    m_idIntakeFK = idIntakeFK;
}

QDateTime DiagAss::dHour() const{
    return m_dHour;
}
void DiagAss::setDhour(const QDateTime & dHour){
    m_dHour = dHour;
}

