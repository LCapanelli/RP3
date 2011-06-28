#include "diagnostico.h"
#include <QString>
#include "qdjango/QDjango.h"
#include "qdjango/QDjangoQuerySet.h"

/**
Esta classe serve para criação de Diagnósticos,
Um diagnóstico pertence a uma Classe, uma Classe pertence a um Domínio
  **/

Diagnostico::Diagnostico(QObject *parent) :
        QDjangoModel(parent)
    {
}

qint32 Diagnostico::idDiag() const {
     return m_idDiag;
 }
void Diagnostico::setIdDiag(const qint32 &idDiag){
     m_idDiag = idDiag;
 }

QString Diagnostico::nomeDiag() const{
    return m_nomeDiag;
}
void Diagnostico::setNomeDiag(const QString &nomeDiag){
    m_nomeDiag = nomeDiag;
}

QString Diagnostico::num01() const {
    return m_num01;
}
void Diagnostico::setNum01(const QString &num01){
    m_num01 = num01;
}

QString Diagnostico::num02() const {
    return m_num02;
}
void Diagnostico::setNum02(const QString &num02){
    m_num02 = num02;
}

int Diagnostico::idDom() const {
    return m_idDom;
}
void Diagnostico::setIdDom(const int &idDom){
        m_idDom = idDom;
}

int Diagnostico::idClasse() const {
    return m_idClasse;
}
void Diagnostico::setIdClasse(const int &idClasse){
    m_idClasse = idClasse;
}

QString Diagnostico::definicao() const{
    return m_definicao;
}
void Diagnostico::setDefinicao(const QString &definicao){
    m_definicao = definicao;
}

QString Diagnostico::cDefin() const{
    return m_cDefin;
}
void Diagnostico::setCDefin(const QString &cDefin){
    m_cDefin = cDefin;
}

QString Diagnostico::fRelac() const{
    return m_fRelac;
}
void Diagnostico::setFRelac(const QString &fRelac){
    m_fRelac = fRelac;
}
//Outros métodos

void Diagnostico::setExamples(){
    Diagnostico *u = new Diagnostico();
    u->setIdDiag(1);
    u->setNomeDiag("Padrão Respiratório Ineficaz");
    u->setNum01("(00032)");
    u->setNum02("1980, 1996, 1998");
    u->setIdDom(4);
    u->setIdClasse(4);
    u->setDefinicao("Inspiração e/ou expiração que não proporciona ventilação adequada.");
    u->setCDefin("-Alteração na profundidade respiratória\n -Assumir uma posição de três pontos \n -Batimentos de asa do nariz");
    u->setFRelac("-Ansiedade \n -Danos cognitivos \n -Dano de percepção ");
    u->save();
    u->setIdDiag(2);
    u->setNomeDiag("BLAH");
    u->setNum01("(00032)");
    u->setNum02("1980, 1996, 1998");
    u->setIdDom(4);
    u->setIdClasse(4);
    u->setDefinicao(" # - Inspiração e/ou expiração que não proporciona ventilação adequada.");
    u->setCDefin("-Alteração na profundidade respiratória\n -Assumir uma posição de três pontos \n -Batimentos de asa do nariz");
    u->setFRelac("-Ansiedade \n -Danos cognitivos \n -Dano de percepção ");
    u->save();
    u->setIdDiag(3);
    u->setNomeDiag("BLAH BLAH");
    u->setNum01("(38473)");
    u->setNum02("2011");
    u->setIdDom(1);
    u->setIdClasse(3);
    u->setDefinicao("SEM DEF");
    u->setCDefin("SEM CD");
    u->setFRelac("SEM FR");
    u->save();
}

//QVariant Diagnostico::data(const QModelIndex &index, int role) const{
//    if(role == Qt::DisplayRole){
//        return QString ("Row%1, Column%2")
//                .arg(index.row() + 1)
//                .arg(index.column() +1);
//    }
//    return QVariant();
//}


//SLOTS

void Diagnostico::updateViewDiag(){
//    ui.diagnosticos_adm->clear();
//    QDjangoQuerySet <Diagnostico> nomeD;
//    for (int i = 0; i < nomeD.count(); ++i){
//        QListWidgetItem * item = new QListWidgetItem(nomeD.at(i)->nomeDiag(), ui.diagnosticos_adm);
//        item->setData(Qt::UserRole, nomeD.at(i)->idDiag());
//    }
}
