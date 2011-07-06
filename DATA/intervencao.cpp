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
    interv->setInterName("Monitorar volume hídrico administrado e eliminado.");
    interv->save();
    interv->setIdInter(3);
    interv->setIdDiagIFK(2);
    interv->setInterName("Monitorar a ocorrências de sensações de plenitudes, náuseas e vômitos.");
    interv->save();
    interv->setIdInter(4);
    interv->setIdDiagIFK(2);
    interv->setInterName("Avaliar presença de ruídos intestinais a cada turno.");
    interv->save();
    interv->setIdInter(5);
    interv->setIdDiagIFK(2);
    interv->setInterName("Monitorar a presença de sinais de edemas ou desidratação.");
    interv->save();
    interv->setIdInter(6);
    interv->setIdDiagIFK(2);
    interv->setInterName("Observar aceitação da ingesta hídrica e alimentar.");
    interv->save();
    interv->setIdInter(7);
    interv->setIdDiagIFK(2);
    interv->setInterName("Explicar o procedimento ao paciente e familiares.");
    interv->save();
    interv->setIdInter(8);
    interv->setIdDiagIFK(2);
    interv->setInterName("Monitorar os sinais vitais( temperatura axilar, frequência cardíaca, frequência respiratória, pressão arterial, dor).");
    interv->save();
    interv->setIdInter(9);
    interv->setIdDiagIFK(2);
    interv->setInterName("Pesar rotineiramente (mesma hora do dia e após eliminação urinária).");
    interv->save();
    interv->setIdInter(10);
    interv->setIdDiagIFK(2);
    interv->setInterName("Estimular o paciente a automonitorar-se em relação à ingestão diária de alimentos e a pesar-se/ manter o peso.");
    interv->save();
    interv->setIdInter(11);
    interv->setIdDiagIFK(2);
    interv->setInterName("Fixar  a sonda alimentar com fita adesiva.");
    interv->save();
}
