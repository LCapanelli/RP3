#include "intake.h"
#include "ui_intake.h"
#include "qdjango/QDjangoQuerySet.h"
#include "paciente.h"
#include "admissao.h"
#include "diagnostico.h"

Intake::Intake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Intake)
{
    ui->setupUi(this);
    updatePatList_OnIntake();
    update_DiagListOnIntake();
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
    Admissao *intake = new Admissao();
//! NEW INTAKE -- get the Name of the selected Patient to a new Table Intake
void Intake::on_pb_NEWINTAKE_clicked()
{
    intake->setPatNameFK(ui->lw_PatList_INTAKE->currentItem()->text());
    tempNameP = ui->lw_PatList_INTAKE->currentItem()->text();
    intake->setHasFinished(false);
    ui->tabWidget_admissao_2->setTabEnabled(0, false);
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

void Intake::on_pq_SAVEassociatedDIAG_clicked()
{   //Admissao *intake2 = new Admissao();
    intake->setAssocDiag(ui->lw_diaAssociated->currentItem()->text());
    intake->setAssocDiagTime(ui->dateb_DateHourFromDiag->dateTime());
    intake->save();
}

