#include "maintenance.h"
#include "ui_maintenance.h"
#include "diagnostico.h"
#include "usuario.h"
#include "intervencao.h"
#include <QMessageBox>
#include "qdjango/QDjangoQuerySet.h"
#include <QList>
Maintenance::Maintenance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Maintenance)
{
    ui->setupUi(this);
    nic_updateDiagView();
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

//SAVE User Reg
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

//Update DiagName_list for NIC
void Maintenance::nic_updateDiagView(){
    ui->lw_DiagNIC->clear();
    QDjangoQuerySet <Diagnostico> nomeD;
    if (!ui->le_FILTER_DIAGonNIC->text().isEmpty())
        nomeD = nomeD.filter(QDjangoWhere("nomeDiag", QDjangoWhere::Contains, ui->le_FILTER_DIAGonNIC->text()));

    for (int i = 0; i < nomeD.count(); ++i){
        QListWidgetItem * item = new QListWidgetItem(nomeD.at(i)->nomeDiag(), ui->lw_DiagNIC);
        item->setData(Qt::UserRole, nomeD.at(i)->idDiag());
    }
}

void Maintenance::on_le_FILTER_DIAGonNIC_returnPressed()
{
nic_updateDiagView();
}

void Maintenance::on_pq_NICSAVE_clicked()
{//implementar o FK e salvar o NIC

}

void Maintenance::on_pb_SEARCH_DIAGonNIC_clicked()
{
    nic_updateDiagView();
}

void Maintenance::on_pb_NICRemove_clicked()
{

}

void Maintenance::on_lw_DiagNIC_itemClicked(QListWidgetItem* item)
{
//    QDjangoQuerySet<Diagnostico> idDiag;
//    for (int i = 0; i < idDiag.count(); ++i){
//        QListWidgetItem * item = new QListWidgetItem(idDiag.at(i)->idDiag());
//        item->setData(Qt::UserRole, idDiag.at(i)->idDiag());
//    }
    //idDiag = idDiag.filter(QDjangoWhere("idDiag", QDjangoWhere::Equals, item->text()));
    //int id = idDiag.get(QDjangoWhere("idDiag"));

    qDebug() << item;
}
