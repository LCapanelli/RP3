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

qint32 Intervencao::idDiagIFK() const {
    return m_idDiagIFK;
}
void Intervencao::setIdDiagIFK(const qint32 &idDiagIFK){
    m_idDiagIFK = idDiagIFK;
}

QString Intervencao::interName() const {
    return m_interName;
}
void Intervencao::setInterName(const QString &interName){
    m_interName = interName;
}

void Intervencao::setExamplesOfInterventions(){
    Intervencao * interv = new Intervencao(this);
    interv->setIdInter(1);
    interv->setIdDiagIFK(2);
    interv->setInterName("Manter a cabeceira da cama elevada entre 30 e 45 graus durante e após a alimentação.");
    interv->save();
    interv->setIdInter(2);
    interv->setIdDiagIFK(2);
    interv->setInterName("Manter ");
    interv->save();
}
