#include "paciente.h"
#include "qdjango/QDjangoModel.h"
/**
Esta classe serve para a criação de um Paciente,
um Paciente tem um registro fixo e vário registros atualizáveis.
Um Paciente pode possuir várias Internações (H.E., evoluções e altas)
  **/
Paciente::Paciente(QObject *parent) :
        QDjangoModel(parent)
{
}

qint32 Paciente::pront() const {
     return m_pront;
 }
void Paciente::setPront(const qint32 &pront){
    m_pront = pront;
}

QString Paciente::nameP() const {
    return m_nameP;
}
void Paciente::setNameP(const QString &nameP){
    m_nameP = nameP;
}

QString Paciente::jobP() const {
    return m_jobP;
}
void Paciente::setJobP(const QString &jobP){
    m_jobP = jobP;
}

QString Paciente::proced() const {
    return m_proced;
}
void Paciente::setProced(const QString &proced){
    m_proced = proced;
}

QString Paciente::rg() const {
    return m_rg;
}
void Paciente::setRg(const QString &rg){
    m_rg = rg;
}

QString Paciente::proven() const{
    return m_proven;
}
void Paciente::setProven(const QString &proven){
    m_proven = proven;
}

int Paciente::sex() const {
    return m_sex;
}
void Paciente::setSex(const int & sex){
    m_sex = sex;
}

int Paciente::blood() const {
    return m_blood;
}
void Paciente::setBlood(const int & blood){
    m_blood = blood;
}

QDate Paciente::dBornP() const{
    return m_dBornP;
}
void Paciente::setDbornP(const QDate & dBornP){
    m_dBornP = dBornP;
}

QString Paciente::ethn() const {
    return m_ethn;
}
void Paciente::setEthn(const QString & ethn){
    m_ethn = ethn;
}

QString Paciente::relig() const {
    return m_relig;
}
void Paciente::setRelig(const QString & relig){
    m_relig = relig;
}

int Paciente::civilS() const {
    return m_civilS;
}
void Paciente::setCivilS(const int & civilS){
    m_civilS = civilS;
}

QString Paciente::mailP() const {
    return m_mailP;
}
void Paciente::setMailP(const QString & mailP){
    m_mailP = mailP;
}

QString Paciente::telR() const {
    return m_telR;
}
void Paciente::setTelR(const QString & telR){
    m_telR = telR;
}

QString Paciente::telC() const {
    return m_telC;
}
void Paciente::setTelC(const QString & telC){
    m_telC = telC;
}

QString Paciente::cellP() const {
    return m_cellP;
}
void Paciente::setCellP(const QString & cellP){
    m_cellP = cellP;
}

QString Paciente::alerg() const {
    return m_alerg;
}
void Paciente::setAlerg(const QString & alerg){
    m_alerg = alerg;
}

QString Paciente::obsP() const {
    return m_obsP;
}
void Paciente::setObsP(const QString & obsP){
    m_obsP = obsP;
}

void Paciente::setPatExamples(){
}
