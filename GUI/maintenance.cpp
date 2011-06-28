#include "maintenance.h"
#include "ui_maintenance.h"
#include "diagnostico.h"
#include "usuario.h"
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
    if(!ui->le_nomeDiag->text().isEmpty() /*&& !ui->le_taxDiag->text().isEmpty() &&
           !ui->le_YearDiag->text().isEmpty() && !ui->te_DiagDefinition->toPlainText().isEmpty()
            && !ui->te_caractDef->toPlainText().isEmpty() &&
                    !ui->te_Rfactor->toPlainText().isEmpty()*/){
        Diagnostico *diag = new Diagnostico(this);
        diag->setNomeDiag(ui->le_nomeDiag->text());
        diag->setNum01(ui->le_taxDiag->text());
        diag->setNum02(ui->le_YearDiag->text());
        diag->setDefinicao(ui->te_DiagDefinition->toPlainText());
        diag->setCDefin(ui->te_caractDef->toPlainText());
        diag->setFRelac(ui->te_Rfactor->toPlainText());
        diag->save();
        QMessageBox alertDiagMsg;
        alertDiagMsg.setText("Diagnostico salvo com sucesso!");
        alertDiagMsg.setStandardButtons(QMessageBox::Ok);
        alertDiagMsg.exec();
        ui->le_nomeDiag->clear();
        ui->le_taxDiag->clear();
        ui->le_YearDiag->clear();
        ui->te_DiagDefinition->clear();
        ui->te_caractDef->clear();
        ui->te_Rfactor->clear();

    }
}

void Maintenance::on_pb_UserSAVE_clicked()
{//terminar restricoes
    Usuario *usr = new Usuario(this);
    usr->setUsername(ui->le_userName->text());
//    usr->setDborn(ui->dateEdit_user->text());
    //usr.setUtype(ui->cb_userType);
    usr->setEmailUser(ui->le_emailUser->text());
    usr->setCoren(ui->le_coren->text().toInt());
    usr->setLogin(ui->le_userLOG->text());
    usr->setPassW(ui->le_passW->text());
    usr->setTelResUser(ui->le_rTEL->text());
    usr->setCellUser(ui->le_Cell->text());
    usr->setStreetUser(ui->le_streetUser->text());
    usr->setStreetNUser(ui->le_NumStreet->text());
    usr->setCepUser(ui->le_CEP->text());
    usr->setCityUser(ui->le_cityUser->text());
    //usr.setUfUser(ui->cb_UF);
    usr->setBlockUser(ui->le_blockUser->text());
    usr->setCountryUser(ui->le_userCountry->text());
    usr->save();
}
