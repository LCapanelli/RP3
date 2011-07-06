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
//#include <QHeaderView>

Intake::Intake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Intake)
{
    ui->setupUi(this);

//    ui->tableW_PrescAndApraz->setColumnCount(3);
//    QStringList labelList;
//    labelList << tr("ID") << tr("Prescrição") << tr("Aprazamento");
//    ui->tableW_PrescAndApraz->setHorizontalHeaderLabels(labelList);

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
    //tempIdFromIntake = intake->idIntake();
   qDebug()<< tempNameP <<"  <<<<<<< NOME ADM Quando CLicar em ADMITIR";
    QSqlQuery q;
    q.prepare("SELECT pront FROM paciente WHERE nameP = :name");
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
    ui->lw_diaAssociated->setDragDropOverwriteMode(0);
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
        assD->setIdIntakeFK(tempIdFromIntake);
        assD->save();
        QMessageBox info;
        info.setText("DIAGNOSTICO " + ui->lw_diaAssociated->currentItem()->text() + " ASSOCIADO AO " + tempNameP);
        info.setButtonText(1, "OK");
        info.exec();
}


void Intake::on_pb_InterventionOK_clicked()
{
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

//! UPDATE list of Prescriptions and Time
void Intake::update_PresAndAprazList(){

    QDjangoQuerySet<ActAss> idAct, acPrescr, acApraz;
    QStringList acPrescrList, acAprazList;
    QList<qint32> idActList;

    //Fills QLists with content from ActAss ORM table
    for (int i = 0; i < idAct.count() /*&& acPrescr.count() && acApraz.count()*/; ++i){
        idActList << idAct.at(i)->idAt();
        acPrescrList << acPrescr.at(i)->prescr();
        acAprazList << acApraz.at(i)->apraz();
    }

    //Fills the GUI TableWidget by column from QLists
    for (int i = 0; i < idActList.count(); ++i){
        ui->tableW_PrescAndApraz->setRowCount(idActList.count());
        //ui->tableW_PrescAndApraz->setItem(i, 0, new QTableWidgetItem(idActList.at(i)));
        ui->tableW_PrescAndApraz->setItem(i, 0, new QTableWidgetItem(acPrescrList.at(i)));
        ui->tableW_PrescAndApraz->setItem(i, 1, new QTableWidgetItem(acAprazList.at(i)));
    }

    qDebug() <<"AQUI"<< idActList;
}


void Intake::on_pb_aprazingInterv_clicked()
{
    QSqlQuery q;
    q.prepare("SELECT idIntake FROM admissao WHERE patNameFK = :name");
    q.bindValue(":name", tempNameP);
    q.exec();
    while(q.next()){
        tempIdFromIntake = q.value(0).toInt();
    }
    //NEW OBJECT
    ActAss *act= new ActAss(this);
    act->setIdAt(0);
    act->setIdIntakeFK(tempIdFromIntake);
    act->setApraz(ui->le_aprazInterv->text());
    act->setPrescr(ui->td_PrescrInt->toPlainText());
    ui->le_aprazInterv->clear();
    ui->td_PrescrInt->clear();
    act->save();

    update_PresAndAprazList();
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
        qDebug()<<"NOMES "<< r;
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
    ui->lw_diagASS4interv->clear();
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

        intake->setHasFinished(true);
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
