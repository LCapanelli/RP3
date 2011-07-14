#include "intake.h"
#include "ui_intake.h"
#include "qdjango/QDjangoQuerySet.h"
#include "paciente.h"
#include "admissao.h"
#include "diagnostico.h"
#include "intervencao.h"
#include "DATA/diagass.h"
#include "DATA/actass.h"
#include <QMessageBox>
#include <QtSql/qsql.h>
#include <QTableWidgetItem>
#include "DATA/dom.h"
#include <QTimer>

Intake::Intake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Intake)
{
    ui->setupUi(this);

    ui->tableW_PrescAndApraz->setColumnWidth(0, 330);
    ui->tableW_PrescAndApraz->setColumnWidth(1, 130);
    ui->dateb_DateHourFromDiag->setDateTime(QDateTime::currentDateTime());

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_PresAndAprazList()));
    timer->start(1000);

    updatePatList_OnIntake();
    update_DiagListOnIntake();
    update_DiagList4interv();
    update_PresAndAprazList();
}

Intake::~Intake()
{
    delete ui;
}

//! Refresh patient list and provide filter by ID or Name
void Intake::updatePatList_OnIntake(){
ui->lw_PatList_INTAKE->clear();
QDjangoQuerySet <Paciente> pat;
if (!ui->le_SEARCHpatbyName->text().isEmpty())
    pat = pat.filter(QDjangoWhere("nameP", QDjangoWhere::Contains, ui->le_SEARCHpatbyName->text()));
    else
    if (!ui->le_SEARCHpatByID->text().isEmpty())
         pat = pat.filter(QDjangoWhere("pront", QDjangoWhere::Contains, ui->le_SEARCHpatByID->text()));

    for (int i = 0; i < pat.count(); ++i){
    QListWidgetItem * itemP = new QListWidgetItem(pat.at(i)->nameP(), ui->lw_PatList_INTAKE);
    itemP->setData(Qt::UserRole, pat.at(i)->pront());
    }
}

void Intake::on_le_SEARCHpatbyName_returnPressed()
{
    updatePatList_OnIntake();
}

void Intake::on_pb_SEARCHpatGO_clicked()
{
    updatePatList_OnIntake();
}

void Intake::on_le_SEARCHpatByID_returnPressed()
{
    updatePatList_OnIntake();
}

//NEW OBJECT
Admissao *intake = new Admissao();

//! NEW INTAKE -- get the Name of the selected Patient to a new Table Intake
void Intake::on_pb_NEWINTAKE_clicked()
{
    intake->setPatNameFK(ui->lw_PatList_INTAKE->currentItem()->text());
    tempNameP = ui->lw_PatList_INTAKE->currentItem()->text();
   qDebug()<< tempNameP <<"  <<<<<<< NOME ADM Quando CLicar em ADMITIR";
    QSqlQuery q;
    q.prepare("SELECT pront FROM sae.paciente WHERE nameP = :name");
    q.bindValue(":name", tempNameP);
    q.exec();
    while(q.next()){
        tempPront = q.value(0).toInt();
        intake->setProntPK(tempPront);
    }
    intake->setHasFinished(false);
    intake->setHasStarted(true);
    ui->tabWidget_admissao_2->setTabEnabled(0, false);
    ui->tabWidget_admissao_2->setTabEnabled(1, true);
    ui->tabWidget_admissao_2->setTabEnabled(2,true);
        ui->tabWidget_admissao_2->setTabEnabled(3,true);
            ui->tabWidget_admissao_2->setTabEnabled(4,true);
    intake->save();
}

void Intake::on_pb_SAVEexFIS_clicked()
{

        intake->setFis(ui->qtext_exFisics->toPlainText());
        ui->tabWidget_admissao_2->setTabEnabled(1, false);
        intake->save();

}

void Intake::on_pb_SAVEAnamnese_clicked()
{
    intake->setAnam(ui->pt_anamnese->toPlainText());
    ui->tabWidget_admissao_2->setTabEnabled(2, false);
    intake->save();
}

//! Upate List of diagnosis on Intake
void Intake::update_DiagListOnIntake(){
    ui->lw_IntakeDiag->clear();
    QDjangoQuerySet<Dom> dom;
    for(int i = 0; i < dom.count(); ++i){
        QListWidgetItem * itemDom = new QListWidgetItem(dom.at(i)->nameDom(), ui->lw_domDiag);
        itemDom->setData(Qt::UserRole, dom.at(i)->idDom());
    }

    QDjangoQuerySet <Diagnostico> nomeD;
    for (int i = 0; i < nomeD.count(); ++i){
        QListWidgetItem * item = new QListWidgetItem(nomeD.at(i)->nomeDiag(), ui->lw_IntakeDiag);
        item->setData(Qt::UserRole, nomeD.at(i)->idDiag());
    }
    ui->lw_IntakeDiag->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->lw_IntakeDiag->setDragDropMode(QAbstractItemView::InternalMove);
    ui->lw_IntakeDiag->setDefaultDropAction(Qt::MoveAction);
    ui->lw_IntakeDiag->setDropIndicatorShown(true);
    ui->lw_IntakeDiag->viewport()->setAcceptDrops(false);

    ui->lw_diaAssociated->viewport()->setAcceptDrops(true);
    ui->lw_diaAssociated->setDragDropOverwriteMode(false);

    ui->lw_Activities4diag->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->lw_Activities4diag->setDragDropMode(QAbstractItemView::InternalMove);
    ui->lw_Activities4diag->setDefaultDropAction(Qt::MoveAction);
    ui->lw_Activities4diag->setDropIndicatorShown(true);
    ui->lw_Activities4diag->viewport()->setAcceptDrops(false);

    ui->lw_DROP_ACT->viewport()->setAcceptDrops(true);
    ui->lw_DROP_ACT->setDragDropOverwriteMode(false);
}

DiagAss *assD = new DiagAss();
//! SAVE and Associates a list of Diagnosis
void Intake::on_pb_SAVEassociatedDIAG_clicked()
{
        ui->pb_SAVEassociatedDIAG->setEnabled(true);
        assD->setIdDiagAss(0);
        assD->setPatientNameIntakeFK(tempNameP);
        assD->setDhour(ui->dateb_DateHourFromDiag->dateTime());
        assD->setDiagAssNAME(ui->lw_diaAssociated->currentItem()->text());
        QSqlQuery q;
        q.prepare("SELECT idIntake FROM admissao WHERE patNameFK = :name");
        q.bindValue(":name", tempNameP);
        q.exec();
        while(q.next()){
            tempIdFromIntake = q.value(0).toInt();
        }
        //wlk.rnd
        QSqlQuery k;
        k.prepare("INSERT INTO sae.diagass (idIntakeFK, patientNameIntakeFK, dHour, diagAssNAME) VALUES (:idIntakeFK, :patNameFK, :dH, :dName)");
        k.bindValue(":idIntakeFK", tempIdFromIntake);
        k.bindValue(":patNameFK", tempNameP);
        k.bindValue(":dH", ui->dateb_DateHourFromDiag->dateTime());
        k.bindValue(":dName", ui->lw_diaAssociated->currentItem()->text());
        //wlk.rnd END
        assD->setIdIntakeFK(tempIdFromIntake);
        assD->save();
        QMessageBox info;
        info.setText("DIAGNOSTICO " + ui->lw_diaAssociated->currentItem()->text() + " ASSOCIADO AO " + tempNameP);
        info.setButtonText(1, "OK");
        info.exec();
}

//! Go to an Intervention
void Intake::on_pb_InterventionOK_clicked()
{
    ui->lw_diagASS4interv->clear();
    QMessageBox alertDiagMsg;
    alertDiagMsg.setText("Deseja Prosseguir para Intervencoes?");
    alertDiagMsg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = alertDiagMsg.exec();
    switch (ret) {
      case QMessageBox::Ok:
          // Save was clicked
        ui->tabWidget_admissao_2->setTabEnabled(3, false);
        update_DiagList4interv();
          break;
      case QMessageBox::Cancel:
          // Cancel was clicked
                  ui->tabWidget_admissao_2->setTabEnabled(3, true);
          break;
    }
}

//! UPDATE the Associated Diagnosis list on Intervations tab
void Intake::update_DiagList4interv(){
    ui->lw_diagASS4interv->clear();

    QSqlQuery q;
    q.prepare("SELECT idIntake FROM admissao WHERE patNameFK = :name");
    q.bindValue(":name", tempNameP);
    q.exec();
    while(q.next()){
        tempIdFromIntake = q.value(0).toInt();
    }

    QDjangoQuerySet<DiagAss> dia;
    dia = dia.filter(QDjangoWhere("idIntakeFK", QDjangoWhere::Equals, tempIdFromIntake));

    qDebug() <<"TEMP<<<<"<< tempNameP << "ID >> " << tempIdFromIntake;
    for (int i = 0; i < dia.count(); ++i){
    QListWidgetItem * itemAss = new QListWidgetItem(dia.at(i)->diagAssNAME(), ui->lw_diagASS4interv);
    itemAss->setData(Qt::UserRole, dia.at(i)->idDiagAss());
    }
}

//! Make a association with de Intervantions and the aprazing time for an Intake
void Intake::on_pb_aprazingInterv_clicked()
{
    int tempId;
    QSqlQuery q;
    q.prepare("SELECT idIntake FROM sae.admissao WHERE patNameFK = :name");
    q.bindValue(":name", tempNameP);
    q.exec();
    while(q.next()){
        tempId = q.value(0).toInt();
    }
    QSqlQuery w;
    w.prepare("INSERT INTO sae.actass (idIntakeFK, prescr, apraz) VALUES (:id, :pr, :apraz)");
    w.bindValue("id", tempId);
    w.bindValue(":pr", ui->lw_DROP_ACT->currentItem()->text());
    w.bindValue(":apraz", ui->le_aprazInterv->text());
    w.exec();

    ui->le_aprazInterv->clear();
    tempId = tempIdOut;
}

//! UPDATE list of Prescriptions and aprazing Times
void Intake::update_PresAndAprazList(){
    QStringList actAssNList, aprazList;
    QDjangoQuerySet <ActAss> actAssN, apraz;
    actAssN = actAssN.filter(QDjangoWhere("idIntakeFK", QDjangoWhere::Equals, tempIdFromIntake));
    apraz = apraz.filter(QDjangoWhere("idIntakeFK", QDjangoWhere::Equals, tempIdFromIntake));

    for(int i = 0;i < actAssN.count();++i){
        actAssNList << actAssN.at(i)->prescr();
        aprazList << apraz.at(i)->apraz();
    }
    for(int i = 0; i < actAssNList.count(); ++i){
        ui->tableW_PrescAndApraz->setRowCount(actAssNList.count());
        ui->tableW_PrescAndApraz->setItem(i, 0, new QTableWidgetItem(actAssNList.at(i)));
        ui->tableW_PrescAndApraz->setItem(i, 1, new QTableWidgetItem(aprazList.at(i)));
    }
        }

void Intake::on_lw_diagASS4interv_itemClicked(QListWidgetItem* item)
{
    ui->lw_Activities4diag->clear();
    QString t = ui->lw_diagASS4interv->currentItem()->text();
    int u;
    QSqlQuery p;
    p.prepare("SELECT idDiag FROM diagnostico WHERE nomeDiag = :nameD");
    p.bindValue("nameD", t);
    p.exec();
    while(p.next()){
    u = p.value(0).toInt();
        qDebug()<<"contem ID "<< u;
    }

    QSqlQuery q;
    q.prepare("SELECT interName FROM intervencao WHERE idDiagIFK = :idfk");
    q.bindValue(":idfk", u);
    q.exec();
    while(q.next()){
        QString r = q.value(0).toString();
        ui->lw_Activities4diag->addItem(r);
    }
}

void Intake::update_Act4IntervAndApraz(){

}

void Intake::on_pb_CANCEL_FIS_clicked()
{
    QMessageBox alertDiagMsg;
    alertDiagMsg.setText(tr("Deseja Realmente CANCELAR o Exame Fisico?"));
    alertDiagMsg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = alertDiagMsg.exec();
    switch (ret) {
      case QMessageBox::Yes:
        ui->tabWidget_admissao_2->setTabEnabled(0, true);
        ui->tabWidget_admissao_2->setTabEnabled(1, false);
        ui->tabWidget_admissao_2->setTabEnabled(2, false);
        ui->tabWidget_admissao_2->setTabEnabled(3, false);
        ui->tabWidget_admissao_2->setTabEnabled(4, false);
          break;
      case QMessageBox::No:

          break;
    }
}

void Intake::on_pb_CANCEL_anam_clicked()
{
    QMessageBox alertDiagMsg;
    alertDiagMsg.setText(tr("Deseja Realmente CANCELAR a anamnese?"));
    alertDiagMsg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = alertDiagMsg.exec();
    switch (ret) {
      case QMessageBox::Yes:
        ui->tabWidget_admissao_2->setTabEnabled(0, true);
        ui->tabWidget_admissao_2->setTabEnabled(1, false);
        ui->tabWidget_admissao_2->setTabEnabled(2, false);
        ui->tabWidget_admissao_2->setTabEnabled(3, false);
        ui->tabWidget_admissao_2->setTabEnabled(4, false);
          break;
      case QMessageBox::No:

          break;
    }
}

void Intake::on_pb_CANCEL_Diag_clicked()
{
    QMessageBox alertDiagMsg;
    alertDiagMsg.setText(tr("Deseja Realmente CANCELAR associacoes?"));
    alertDiagMsg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = alertDiagMsg.exec();
    switch (ret) {
      case QMessageBox::Yes:
        ui->tabWidget_admissao_2->setTabEnabled(0, true);
        ui->tabWidget_admissao_2->setTabEnabled(1, false);
        ui->tabWidget_admissao_2->setTabEnabled(2, false);
        ui->tabWidget_admissao_2->setTabEnabled(3, false);
        ui->tabWidget_admissao_2->setTabEnabled(4, false);
          break;
      case QMessageBox::No:

          break;
    }
}

void Intake::on_pb_EXCLUDE_DIAG_clicked()
{
    ui->lw_diaAssociated->clear();
    update_DiagListOnIntake();
}

void Intake::on_pb_CANCEL_INTERV_clicked()
{
    QMessageBox alertDiagMsg;
    alertDiagMsg.setText(tr("Deseja Realmente CANCELAR a prescricao?"));
    alertDiagMsg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = alertDiagMsg.exec();
    switch (ret) {
      case QMessageBox::Yes:
        ui->tabWidget_admissao_2->setTabEnabled(0, true);
        ui->tabWidget_admissao_2->setTabEnabled(1, false);
        ui->tabWidget_admissao_2->setTabEnabled(2, false);
        ui->tabWidget_admissao_2->setTabEnabled(3, false);
        ui->tabWidget_admissao_2->setTabEnabled(4, false);
          break;
      case QMessageBox::No:

          break;
    }
}

void Intake::on_pb_Intake_finished_clicked()
{
    Admissao *d = new Admissao();
    ui->lw_DROP_ACT->clear();
    ui->lw_diagASS4interv->clear();
    ui->lw_diaAssociated->clearSelection();
    ui->lw_diaAssociated->clear();
    ui->lw_Activities4diag->clear();
    update_DiagListOnIntake();
    QMessageBox alertDiagMsg;
    alertDiagMsg.setText(tr("Deseja CONCLUIR a evolucao?"));
    alertDiagMsg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = alertDiagMsg.exec();
    switch (ret) {
      case QMessageBox::Yes:
        tempAnam.clear();
        tempExFis.clear();
        tempNameP.clear();
        ui->tableW_PrescAndApraz->clearContents();
        ui->lw_diagASS4interv->clear();
        ui->lw_Activities4diag->clear();
        tempIdFromIntake = 0;

        intake->setHasFinished(false    );
        intake->save();
        ui->tabWidget_admissao_2->setTabEnabled(0, true);
        ui->tabWidget_admissao_2->setTabEnabled(1, false);
        ui->tabWidget_admissao_2->setTabEnabled(2, false);
        ui->tabWidget_admissao_2->setTabEnabled(3, false);
        ui->tabWidget_admissao_2->setTabEnabled(4, false);
          break;
      case QMessageBox::No:

          break;
    }
}

//! When a Dom is clicked a list of those diagnosis is showed
void Intake::on_lw_domDiag_itemClicked(QListWidgetItem* item)
{
    ui->lw_IntakeDiag->clear();
    QString t = ui->lw_domDiag->currentItem()->text();
    int u;
    QSqlQuery p;
    p.prepare("SELECT idDom FROM sae.dom WHERE nameDom = :nameD");
    p.bindValue("nameD", t);
    p.exec();
    while(p.next()){
        u = p.value(0).toInt();
        qDebug()<<"contem ID "<< u;
    }

    QSqlQuery q;
    q.prepare("SELECT nomeDiag FROM sae.diagnostico WHERE idDom = :idDom");
    q.bindValue(":idDom", u);
    q.exec();
    while(q.next()){
        QString r = q.value(0).toString();
        ui->lw_IntakeDiag->addItem(r);
    }
}

//! Catch a temp. ID from a non Intaked clicked User
void Intake::on_lw_PatList_INTAKE_itemClicked()
{
    tempNameP = ui->lw_PatList_INTAKE->currentItem()->text();
    QSqlQuery q;
    q.prepare("SELECT idIntake FROM sae.admissao WHERE patNameFK = :dName AND hasFinished = FALSE");
    q.bindValue(":dName", tempNameP);
    q.exec();
    while (q.next()){
        tempIdFromIntake = q.value(0).toInt();
    }
}
