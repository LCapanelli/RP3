#include "escorting.h"
#include "ui_escorting.h"
#include "DATA/diagass.h"
#include <QtSql/QSqlQuery>
#include <QTimer>
#include <QDebug>
#include <qdjango/QDjangoQuerySet.h>
#include <QTableWidgetItem>
#include "admissao.h"

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
        qDebug() << tempIdFK << tempIdName;
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
    ui->tw_DIAG2EVO->clearContents();

   QSqlQuery q, u;
    u.prepare("SELECT COUNT(idIntakeFK) FROM sae.diagass WHERE idIntakeFK = :fk");
    u.bindValue(":fk", tempIdFK);
    u.exec();
    while(u.next()){
    tempCount2 = u.value(0).toInt();
    }

    q.prepare("SELECT a.prontPK FROM sae.admissao a, sae.diagass s WHERE s.idIntakeFK = a.idIntake AND patientNameIntakeFK = :idName");
    q.bindValue(":idName", tempIdName);
    q.exec();
    QStringList prontList;
    while(q.next()){
        prontList << q.value(0).toString();
    }

    QStringList diagAList, stateList;
    QList <QDateTime> dHList;
    QDjangoQuerySet <DiagAss> diagAssN, state, dHour;
    diagAssN = diagAssN.filter(QDjangoWhere("idIntakeFK", QDjangoWhere::Equals, tempIdFK));
    state = state.filter(QDjangoWhere("idIntakeFK", QDjangoWhere::Equals, tempIdFK));
    dHour = dHour.filter(QDjangoWhere("idIntakeFK", QDjangoWhere::Equals, tempIdFK));

    for(int i = 0;i < diagAssN.count();++i){
        stateList << state.at(i)->state();
        diagAList << diagAssN.at(i)->diagAssNAME();
        dHList << dHour.at(i)->dHour();
    }
    for(int i = 0; i < diagAList.count(); ++i){
        ui->tw_DIAG2EVO->setRowCount(diagAList.count());
        ui->tw_DIAG2EVO->setItem(i, 0, new QTableWidgetItem(prontList.at(i)));
        ui->tw_DIAG2EVO->setItem(i, 1, new QTableWidgetItem(stateList.at(i)));
        ui->tw_DIAG2EVO->setItem(i, 2, new QTableWidgetItem(diagAList.at(i)));
        ui->tw_DIAG2EVO->setItem(i, 3, new QTableWidgetItem(dHList.at(i).toString("dd / MM / yyyy - HH:mm:ss")));
    }
}

void Escorting::on_pb_CONT_clicked()
{
    ui->tw_DIAG2EVO->clearContents();
    Escorting::tempCount = 0;
    Escorting::tempCount2 = 0;
}
