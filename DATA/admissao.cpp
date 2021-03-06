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

qint32 Admissao::prontPK() const{
    return m_prontPK;
}
void Admissao::setProntPK(const qint32 & prontPK){
    m_prontPK = prontPK;
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

bool Admissao::hasStarted() const{
    return m_hasStarted;
}
void Admissao::setHasStarted(const bool &hasStarted){
    m_hasStarted = hasStarted;
}
