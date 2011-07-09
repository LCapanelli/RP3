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

//Another methods
void Paciente::setPatExamples(){
//    Paciente *p = new Paciente(this);
//    p->setPront(1);
//    p->setNameP("TEST Patient");
//    p->setJobP("Unemployed");
//    p->setProced("UNKNOW");
//    p->setRg("190190190");
//    p->setProven("House");
//    p->setSex(1);
//    p->setBlood(2);
//    QDate data = QDate::currentDate();
//    p->setDbornP(data);
//    p->setEthn("Caucasian");
//    p->setRelig("Unreligious");
//    p->setCivilS(1);
//    p->setMailP("StreetView, 111, FuuTown");
//    p->setTelR("55-112233");
//    p->setTelC("55-998877");
//    p->setCellP("55-9191919");
//    p->setAlerg("NOT detected");
//    p->setObsP("No observations");
//    p->save();

//    p->setPront(2);
//    p->setNameP("Patient 2");
//    p->setJobP("Unemployed TO");
//    p->setProced("UNKNOW");
//    p->setRg("XXXXX");
//    p->setProven("From Job");
//    p->setSex(1);
//    p->setBlood(2);
//    QDate data2 = QDate::currentDate();
//    p->setDbornP(data2);
//    p->setEthn("Indian");
//    p->setRelig("Undefined");
//    p->setCivilS(1);
//    p->setMailP("StreetView, 112, FuuTown");
//    p->setTelR("NO");
//    p->setTelC("NO");
//    p->setCellP("NO");
//    p->setAlerg("Skin alergy");
//    p->setObsP("No observations");
//    p->save();

//    p->setPront(3);
//    p->setNameP("Mr. Panda");
//    p->setJobP("Fighter");
//    p->setProced("Animalia");
//    p->setRg("77777");
//    p->setProven("From a Fight");
//    p->setSex(0);
//    p->setBlood(0);
//    QDate data3 = QDate::currentDate();
//    p->setDbornP(data3);
//    p->setEthn("Animal");
//    p->setRelig("Unrage");
//    p->setCivilS(0);
//    p->setMailP("PandaHood");
//    p->setTelR("NO");
//    p->setTelC("NO");
//    p->setCellP("Yes");
//    p->setAlerg("Breez alergies");
//    p->setObsP("Nothign detected");
//    p->save();
}
