#include "evolucao.h"

/**
Esta classe serve para a criação das Evoluções,

  **/
Evolucao::Evolucao(QObject *parent):
        QDjangoModel(parent)
{
}

qint32 Evolucao::idEvDiag() const {
    return m_idEvDiag;
}
void Evolucao::setIdEvDiag(const qint32 &idEvDiag){
    m_idEvDiag = idEvDiag;
}

qint32 Evolucao::idIntake() const {
    return m_idIntake;
}
void Evolucao::setIdIntake(const qint32 &idIntake){
    m_idIntake = idIntake;
}

QString Evolucao::diagName() const{
    return m_diagName;
}
void Evolucao::setDiagName(const QString &diagName){
    m_diagName = diagName;
}

QString Evolucao::state() const{
    return m_state;
}
void Evolucao::setState(const QString &state){
    m_state = state;
}

QDateTime Evolucao::hourD() const{
    return m_hourD;
}
void Evolucao::setHourD(const QDateTime & hourD){
    m_hourD = hourD;
}
