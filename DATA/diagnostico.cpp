#include "mainwindow.h"
#include "ui_PrincipalForm.h"
#include "qdjango/QDjango.h"
#include "qdjango/QDjangoQuerySet.h"
#include "diagnostico.h"
#include "qdjango/QDjangoScript.h"
#include <QListWidget>
#include <QString>

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

int Diagnostico::num01() const {
    return m_num01;
}
void Diagnostico::setNum01(const int &num01){
    m_num01 = num01;
}

int Diagnostico::num02() const {
    return m_num02;
}
void Diagnostico::setNum02(const int &num02){
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

//SLOTS
void Diagnostico::on_le_FiltroCadDiag_returnPressed(){
    updateViewDiag();
}

void Diagnostico::on_pb_SalvarDiag_clicked(){
    //if(!ui.le_nomeDiag->text().isEmpty() && !ui.te_caractDefinidoras->toPlainText().isEmpty() && !ui.te_fatoresRelac->toPlainText().isEmpty()){
    if(!ui->le_nomeDiag->text().isEmpty()){
    Diagnostico *u = new Diagnostico(this);
    u->setNomeDiag(ui->le_nomeDiag->text());
    u->save();
    ui->le_nomeDiag->clear();
//    u->setCDefin(ui->te_caractDefinidoras->toPlainText());
//    u->setFRelac(ui->te_fatoresRelac->toPlainText());
//    ui->te_caractDefinidoras->clear();
//    ui->te_fatoresRelac->clear();
    }
    updateViewDiag();
}

void Diagnostico::updateViewDiag(){
    ui->listaDiag->clear();
    QDjangoQuerySet <Diagnostico> nomeD;
    nomeD = nomeD.filter(QDjangoWhere("nomeDiag", QDjangoWhere::Contains, ui->le_FiltroCadDiag->text()));
    for (int i = 0; i < nomeD.count(); ++i){
        QListWidgetItem * item = new QListWidgetItem(nomeD.at(i)->nomeDiag(), ui->listaDiag);
        item->setData(Qt::UserRole, nomeD.at(i)->idDiag());
    }
}
