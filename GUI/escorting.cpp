#include "escorting.h"
#include "ui_escorting.h"
#include "DATA/diagass.h"
#include <QtSql/QSqlQuery>
#include <QTimer>
#include <QDebug>
#include <qdjango/QDjangoQuerySet.h>
#include <QTableWidgetItem>

Escorting::Escorting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Escorting)
{
    ui->setupUi(this);

    UPDATE_lw_ESCORTING();
    QTimer *timer = new QTimer(this);
    QTimer *timer2 = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(UPDATE_lw_ESCORTING()));
    connect(timer2, SIGNAL(timeout()),this, SLOT(UPDATE_tb_DiagASS()));
    timer->start(9000);
    timer2->start(9000);

    ui->tw_DIAG2EVO->setColumnWidth(0, 130);
        ui->tw_DIAG2EVO->setColumnWidth(1, 130);
            ui->tw_DIAG2EVO->setColumnWidth(2, 470);
                ui->tw_DIAG2EVO->setColumnWidth(3, 150);
                ui->dTime_EVO->setDateTime(QDateTime::currentDateTime());
}

Escorting::~Escorting()
{
    delete ui;
}

//! Catch an User
void Escorting::on_lw_ESCORTINGpatList_itemClicked()
{
    ui->tw_DIAG2EVO->clearContents();
    tempIdName = ui->lw_ESCORTINGpatList->currentItem()->text();
    QSqlQuery q;
    bool tr = true;
    q.prepare("SELECT idIntake, COUNT(idIntake) FROM sae.admissao WHERE patNameFK = :dName AND hasStarted = :true AND hasFinished = FALSE");
    q.bindValue(":dName", tempIdName);
    q.bindValue(":true", tr);
    q.exec();
    while (q.next()){
        tempIdFK = q.value(0).toInt();
        tempCount = q.value(1).toInt();
        qDebug() << tempIdFK;
    }
}

//! Evolute a diagnosis
void Escorting::on_pb_EVOstates_clicked()
{
    QSqlQuery q;
    q.prepare("INSERT INTO sae.diagass (idIntakeFK, diagAssNAME, state, dHour, patientNameIntakeFK) VALUES(:idI, :dName, :state, :hourD, :name)");
    q.bindValue(":idI", tempIdFK);
    q.bindValue(":dName", ui->tw_DIAG2EVO->currentItem()->text());
    q.bindValue(":state", ui->cb_States->currentText());
    q.bindValue(":hourD", ui->dTime_EVO->dateTime());
    q.bindValue(":name", tempIdName);
    q.exec();

}

//! Updates a list of Intakes Patients
void Escorting::UPDATE_lw_ESCORTING()
{
    ui->lw_ESCORTINGpatList->clear();
    QSqlQuery q;
    bool f = false, t = true;
    q.prepare("SELECT patNameFK FROM sae.admissao WHERE hasFinished = :false AND hasStarted = :true");
    q.bindValue(":false", f);
    q.bindValue(":true", t);
    q.exec();
    while (q.next()){
        QString tempName = q.value(0).toString();
        ui->lw_ESCORTINGpatList->addItem(tempName);
}
}

void Escorting::on_pb_EVOLUT_ADD_clicked()
{
    ui->tabWidget_acEvolucao_2->setTabEnabled(0, false);
    ui->tabWidget_acEvolucao_2->setTabEnabled(1, true);
}

//! UPDATE the diagn. table from an User Intake TO an Evol.
void Escorting::UPDATE_tb_DiagASS(){
//    QString blah, state;
//    QString dt;
   QSqlQuery q, u;
//    q.prepare("SELECT state, diagAssNAME, dHour FROM sae.diagass WHERE idIntakeFK = :idI AND patientNameIntakeFK = :pName");
//    q.bindValue(":idI", tempIdFK);
//    q.bindValue(":pName", tempIdName);
//    q.exec();
//    while(q.next()){
//        state = q.value(0).toString();
//        blah = q.value(1).toString();
//        dt = q.value(2).toString();
//    }
    u.prepare("SELECT COUNT(idIntakeFK) FROM sae.diagass WHERE idIntakeFK = :fk");
    u.bindValue(":fk", tempIdFK);
    u.exec();
    while(u.next()){
    tempCount2 = u.value(0).toInt();
    }

//    ui->tw_DIAG2EVO->setRowCount(tempCount2);
//    for (int i = 0; i < tempCount2 ; ++i){
//        ui->tw_DIAG2EVO->setRowHeight(i, 65);

//        //ui->tw_DIAG2EVO->setItem(i, 0, new QTableWidgetItem(foo));
//        ui->tw_DIAG2EVO->setItem(i, 1, new QTableWidgetItem(state));
//        ui->tw_DIAG2EVO->setItem(i, 2, new QTableWidgetItem(blah));
//        ui->tw_DIAG2EVO->setItem(i, 3, new QTableWidgetItem(dt));
//        qDebug()<<blah<< "BLAH";
//    }
    QStringList diagAList, stateList;
    QList <QDateTime> dHList;
    QDjangoQuerySet <DiagAss> diagAssN, state, dHour;

    for(int i = 0;i < diagAssN.count();++i){
        stateList << state.at(i)->state();
        diagAList << diagAssN.at(i)->diagAssNAME();
        dHList << dHour.at(i)->dHour();
    }
    for(int i = 0; i < diagAList.count(); ++i){
        ui->tw_DIAG2EVO->setRowCount(diagAList.count());
        ui->tw_DIAG2EVO->setItem(i, 1, new QTableWidgetItem(stateList.at(i)));
        ui->tw_DIAG2EVO->setItem(i, 2, new QTableWidgetItem(diagAList.at(i)));
        ui->tw_DIAG2EVO->setItem(i, 3, new QTableWidgetItem(dHList.at(i).toString("dd / MM / yyyy - HH:mm:ss")));
    }
}

void Escorting::on_pb_CONT_clicked()
{
    Escorting::tempCount = 0;
    Escorting::tempCount2 = 0;
}
