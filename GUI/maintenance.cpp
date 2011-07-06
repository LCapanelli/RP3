#include "maintenance.h"
#include "ui_maintenance.h"
#include "diagnostico.h"
#include "usuario.h"
#include "intervencao.h"
#include <QMessageBox>
#include "qdjango/QDjangoQuerySet.h"
#include <QSqlQuery>
#include <QSqlRelationalTableModel>

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
//! System Maintenance - NANDA Recorder
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

        nic_updateDiagView();
    }
}

//! System Maintenance - User Recorder
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

//! Update DiagName_list for NIC_view
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

void Maintenance::on_pb_SEARCH_DIAGonNIC_clicked()
{
    nic_updateDiagView();
}

void Maintenance::on_pb_NICRemove_clicked()
{
    if (ui->lw_AtivityOnNIC->count() == 0)
        return;

    QDjangoQuerySet <Intervencao> remIn;
    qint32 id = ui->lw_AtivityOnNIC->currentItem()->data(Qt::UserRole).toInt();
    remIn = remIn.filter(QDjangoWhere("idInter", QDjangoWhere::Equals, id));
    //Itera nos resultados
         for (int i = 0 ; i < remIn.count(); ++i)
             remIn.at(i)->remove(); //remove
}

//terminar este método
void Maintenance::on_lw_DiagNIC_itemClicked(QListWidgetItem* item)
{
    ui->lw_AtivityOnNIC->clear();
    QDjangoQuerySet<Intervencao> idDiagFK;
    idDiagFK = idDiagFK.filter(QDjangoWhere("idDiagFK", QDjangoWhere::Equals, ui->lw_DiagNIC->currentItem()->text()));

    for (int i = 0; i < idDiagFK.count(); ++i){
        QListWidgetItem * item = new QListWidgetItem(idDiagFK.at(i)->interName(), ui->lw_AtivityOnNIC);
        item->setData(Qt::UserRole, idDiagFK.at(i)->idInter());
    }
}

void Maintenance::on_pb_NICSAVE_clicked()
{
    Intervencao *in = new Intervencao(this);
    if(!ui->le_NIC_register->text().isEmpty()){
        in->setInterName(ui->le_NIC_register->text());
        in->setIdDiagFK(ui->lw_DiagNIC->currentItem()->text());
        in->setIdInter(0);
        in->save();
    }
}
