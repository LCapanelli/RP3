#include "admissao.h"
#include "qdjango/QDjango.h"

/**
Esta classe serve para a criação de uma Admissão,
a Admissão é vinculada ao Paciente, e contém um H.E., um Diagnóstico, um R.E. e um Cuidado(Intervenção).
Uma Admissão contém dados iniciais, os dados derivados são considerados Evoluções.
O fim de uma Admissão (encerramento de todas evoluções) é considerado Alta.
**/

Admissao::Admissao(QObject *parent) :
        QDjangoModel(parent)
{
}

qint32 Admissao::idIntake() const{
    return m_idIntake;
}
void Admissao::setIdIntake(const qint32 & idIntake){
    m_idIntake = idIntake;
}

qint32 Admissao::prontFK() const{
    return m_prontFK;
}
void Admissao::setProntFK(const qint32 & prontFK){
    m_prontFK = prontFK;
}

QString Admissao::Fis() const{
    return m_Fis;
}
void Admissao::setFis(const QString & Fis){
    m_Fis = Fis;
}

QString Admissao::anam() const{
    return m_anam;
}
void Admissao::setAnam(const QString & anam){
    m_anam = anam;
}

QString Admissao::prescr() const{
    return m_prescr;
}
void Admissao::setPrescr(const QString & prescr){
    m_prescr = prescr;
}

QString Admissao::patNameFK() const{
    return m_patNameFK;
}
void Admissao::setPatNameFK(const QString & patNameFK){
    m_patNameFK = patNameFK;
}

bool Admissao::hasFinished() const{
    return m_hasFinished;
}
void Admissao::setHasFinished(const bool & hasFinished){
    m_hasFinished = hasFinished;
}

QString Admissao::assocDiag() const {
    return m_assocDiag;
}
void Admissao::setAssocDiag(const QString & assocDiag){
    m_assocDiag = assocDiag;
}

QDateTime Admissao::assocDiagTime() const{
    return m_assocDiagTime;
}
void Admissao::setAssocDiagTime(const QDateTime & assocDiagTime){
    m_assocDiagTime = assocDiagTime;
}
