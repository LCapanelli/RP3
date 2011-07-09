#include "patient.h"
#include "ui_patient.h"
#include "paciente.h"
#include <qdjango/QDjangoQuerySet.h>
#include <QtSql/qsql.h>

Patient::Patient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Patient)
{
    ui->setupUi(this);

    ui->tblW_selectedPatient->setRowCount(1);
    ui->tblW_selectedPatient->setColumnCount(5);
    ui->tblW_selectedPatient->setRowHeight(0, 150);
    ui->tblW_selectedPatient->setColumnWidth(0, 90);
    ui->tblW_selectedPatient->setColumnWidth(1, 120);
    ui->tblW_selectedPatient->setColumnWidth(2, 150);
    ui->tblW_selectedPatient->setColumnWidth(3, 320);
    ui->tblW_selectedPatient->setColumnWidth(4, 150);
    ui->tblW_selectedPatient->verticalHeader()->hide();

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
else
    if(!ui->le_prontSearch->text().isEmpty())
        pat = pat.filter(QDjangoWhere("pront", QDjangoWhere::Contains, ui->le_prontSearch->text()));

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
    p->setRg(ui->le_patRG->text());
    p->setSex(ui->cb_patSEX->currentIndex());
    p->setBlood(ui->cb_patSang->currentIndex());
    //p->setDbornP(ui->dateEdit_pat->currentSection());
    p->setEthn(ui->le_patRace->text());
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
    ui->le_patRG->clear();
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

void Patient::updateTablePatientInfo(){


//    QDjangoQuerySet<Paciente> ptPront, ptMailP, ptRG, ptDborn, ptEthn;
//    QList <int> prontList;
//    QList <QDate> dBornList;
//    QStringList mailList, rgList, ethnList;

//    ptPront = ptPront.filter(QDjangoWhere("nameP", QDjangoWhere::Equals, ui->lw_filtredPatients->currentItem()->text()));

//    for(int i = 0; i < (ptPront.count())/* && (ptMailP.count()) | (ptRG.count()) | (ptDborn.count()) | (ptEthn.count())*/; ++i){
//        prontList << ptPront.at(i)->pront();
//        mailList << ptMailP.at(i)->mailP();
//        rgList << ptRG.at(i)->rg();
//        dBornList << ptDborn.at(i)->dBornP();
//        ethnList << ptEthn.at(i)->ethn();
//    }
//    for(int i = 0; i < prontList.count(); ++i){
//        ui->tblW_selectedPatient->setRowCount(prontList.count());
//        ui->tblW_selectedPatient->setItem(i, 0, new QTableWidgetItem(prontList.at(i)));
//        ui->tblW_selectedPatient->setItem(i, 1, new QTableWidgetItem(dBornList.at(i).toString()));
//        ui->tblW_selectedPatient->setItem(i, 2, new QTableWidgetItem(rgList.at(i)));
//        ui->tblW_selectedPatient->setItem(i, 3, new QTableWidgetItem(ethnList.at(i)));
//        ui->tblW_selectedPatient->setItem(i, 4, new QTableWidgetItem(mailList.at(i)));
//    }
//    qDebug()<< "HEUTE"<<mailList << rgList;
}

//! When a Patient is clicked those informations is showed in a QTableWidget
void Patient::on_lw_filtredPatients_itemClicked(QListWidgetItem* item)
{
    QDjangoQuerySet<Paciente> ptPront;
    ptPront = ptPront.filter(QDjangoWhere("nameP", QDjangoWhere::Equals, ui->lw_filtredPatients->currentItem()->text()));
    for(int i = 0; i < ptPront.count(); ++i){
        QString t;
        QSqlQuery s; s.prepare("SELECT pront FROM sae.paciente WHERE nameP = :name");
        s.bindValue(":name", ui->lw_filtredPatients->currentItem()->text());
        s.exec();
        while (s.next()){
            t = s.value(0).toString();
        }
        ui->tblW_selectedPatient->setItem(0, 0, new QTableWidgetItem(t));
        ui->tblW_selectedPatient->setItem(0, 1, new QTableWidgetItem(ptPront.at(i)->rg()));
        ui->tblW_selectedPatient->setItem(0, 2, new QTableWidgetItem(ptPront.at(i)->dBornP().toString("dd / MM / yyyy")));
        ui->tblW_selectedPatient->setItem(0, 3, new QTableWidgetItem(ptPront.at(i)->mailP()));
        ui->tblW_selectedPatient->setItem(0, 4, new QTableWidgetItem(ptPront.at(i)->ethn()));
    }
}

void Patient::on_pb_cleanPatList_clicked()
{
    ui->tblW_selectedPatient->clearContents();
}

void Patient::on_pb_NewPatient_clicked()
{
    ui->toolBox->setCurrentIndex(1);
}

void Patient::on_pb_discardPatient_clicked()
{
    ui->toolBox->setCurrentIndex(0);
}

void Patient::on_pb_selPatient_clicked()
{

}

void Patient::on_le_prontSearch_returnPressed()
{
    filtred_Patients();
}
