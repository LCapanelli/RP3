#include "patient.h"
#include "ui_patient.h"
#include "paciente.h"

Patient::Patient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Patient)
{
    ui->setupUi(this);
}

Patient::~Patient()
{
    delete ui;
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
}
}
