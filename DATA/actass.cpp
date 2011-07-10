#include "actass.h"
#include "qdjango/QDjango.h"

    ActAss::ActAss(QObject *parent) :
        QDjangoModel(parent)
{
}

qint32 ActAss::idAt() const{
    return m_idAt;
}
void ActAss::setIdAt(const qint32 & idAt){
    m_idAt = idAt;
}

qint32 ActAss::idIntakeFK() const{
    return m_idIntakeFK;
}
void ActAss::setIdIntakeFK(const qint32 & idIntakeFK){
    m_idIntakeFK = idIntakeFK;
}

QString ActAss::prescr() const{
    return m_prescr;
}
void ActAss::setPrescr(const QString & prescr){
    m_prescr = prescr;
}

QString ActAss::apraz() const{
    return m_apraz;
}
void ActAss::setApraz(const QString & apraz){
    m_apraz = apraz;
}

void ActAss::setExamplesOfActivitiesAndApraz(){

}
