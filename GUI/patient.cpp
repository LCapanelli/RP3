#include "patient.h"
#include "ui_patient.h"
#include "paciente.h"
#include <qdjango/QDjangoQuerySet.h>

Patient::Patient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Patient)
{
    ui->setupUi(this);
    filtred_Patients();
}

Patient::~Patient()
{
    delete ui;
}

void Patient::filtred_Patients(){
    ui->lw_filtredPatients->clear();
    QDjangoQuerySet <Paciente> pat;
    if (!ui->le_patFILTER->text().isEmpty())
        pat = pat.filter(QDjangoWhere("nameP", QDjangoWhere::Contains, ui->le_patFILTER->text()));

    for (int i = 0; i < pat.count(); ++i){
        QListWidgetItem * itemP = new QListWidgetItem(pat.at(i)->nameP(), ui->lw_filtredPatients);
        itemP->setData(Qt::UserRole, pat.at(i)->pront());
    }
}

//terminar de limpar os campos
void Patient::on_pb_saveCPatient_clicked()
{
    if(!ui->le_patNAME->text().isEmpty() /*&& !ui->le_patJOB->text().isEmpty() && !ui->le_patPROCED->text().isEmpty() && !ui->le_patPROVEN->text().isEmpty() &&
       !ui->le_patRG->text().isEmpty() && !ui->le_patMAIL->text().isEmpty() && !ui->le_patALERG->text().isEmpty() &&
       !ui->pT_obsP_2->toPlainText().isEmpty()*/){
    Paciente *p = new Paciente(this);
    p->setNameP(ui->le_patNAME->text());
    p->setJobP(ui->le_patJOB->text());
    p->setProced(ui->le_patPROCED->text());
    p->setRg(ui->le_patRG->text());
    p->setProven(ui->le_patPROVEN->text());
    p->setSex(ui->cb_patSEX->currentIndex());
    p->setBlood(ui->cb_patSang->currentIndex());
    //p->setDbornP(ui->dateEdit_pat->currentSection());
    p->setRace(ui->le_patRace->text());
    p->setRelig(ui->le_patRELIG->text());
    p->setCivilS(ui->cb_patCIVILS->currentIndex());
    p->setMailP(ui->le_patMAIL->text());
    p->setTelR(ui->le_patTELR->text());
    p->setTelC(ui->le_patTELC->text());
    p->setCellP(ui->le_patCELL->text());
    p->setAlerg(ui->le_patALERG->text());
    p->setObsP(ui->pT_obsP_2->toPlainText());
    p->save();

    ui->le_patNAME->clear();
    ui->le_patJOB->clear();
    ui->le_patPROCED->clear();
    ui->le_patRG->clear();
    ui->le_patPROVEN->clear();
    ui->cb_patSEX->clear();
    ui->cb_patSang->clear();
    ui->le_patRELIG->clear();
    ui->cb_patCIVILS->clear();
    ui->le_patMAIL->clear();
    ui->le_patTELC->clear();
    ui->le_patTELR->clear();
    ui->le_patCELL->clear();
    ui->le_patALERG->clear();
    ui->pT_obsP_2->clear();
    ui->le_patRace->clear();
}
}



void Patient::on_le_patFILTER_returnPressed()
{
    filtred_Patients();
}

void Patient::on_pb_paciente_clicked()
{
    filtred_Patients();
}
