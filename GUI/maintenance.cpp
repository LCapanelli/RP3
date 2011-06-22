#include "maintenance.h"
#include "ui_maintenance.h"
#include "diagnostico.h"
#include <QMessageBox>

Maintenance::Maintenance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Maintenance)
{
    ui->setupUi(this);
}

Maintenance::~Maintenance()
{
    delete ui;
}
//System Maintenance - NANDA Recorder
void Maintenance::on_pb_SalvarDiag_clicked()
{
        if(!ui->le_nomeDiag->text().isEmpty() && !ui->le_taxDiag->text().isEmpty() &&
           !ui->le_YearDiag->text().isEmpty() && !ui->te_DiagDefinition->toPlainText().isEmpty()
            && !ui->te_caractDef->toPlainText().isEmpty() &&
                    !ui->te_Rfactor->toPlainText().isEmpty()){
        Diagnostico *u = new Diagnostico(this);
        u->setNomeDiag(ui->le_nomeDiag->text());
        u->setNum01(ui->le_taxDiag->text());
        u->setNum02(ui->le_YearDiag->text());
        u->setDefinicao(ui->te_DiagDefinition->toPlainText());
        u->setCDefin(ui->te_caractDef->toPlainText());
        u->setFRelac(ui->te_Rfactor->toPlainText());
        u->save();
        QMessageBox aviso;
        aviso.setText("Diagnostico salvo");
        aviso.setStandardButtons(QMessageBox::Ok);
        aviso.exec();
        ui->le_nomeDiag->clear();
        ui->le_taxDiag->clear();
        ui->le_YearDiag->clear();
        ui->te_DiagDefinition->clear();
        ui->te_caractDef->clear();
        ui->te_Rfactor->clear();
}
    }
