#include "intervencao.h"
#include "qdjango/QDjango.h"
#include "qdjango/QDjangoQuerySet.h"
#include <QString>

/**
Esta classe serve para a criação de uma Intervenção
  **/
Intervencao::Intervencao(QObject *parent) :
        QDjangoModel(parent)
{
}

qint32 Intervencao::idInter() const {
     return m_idInter;
 }
void Intervencao::setIdInter(const qint32 &idInter){
     m_idInter = idInter;
 }

QString Intervencao::idDiagFK() const {
    return m_idDiagFK;
}
void Intervencao::setIdDiagFK(const QString &idDiagFK){
    m_idDiagFK = idDiagFK;
}

QString Intervencao::interName() const {
    return m_interName;
}
void Intervencao::setInterName(const QString &interName){
    m_interName = interName;
}
