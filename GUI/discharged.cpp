#include "discharged.h"
#include "ui_discharged.h"
#include <QtSql/QSqlQuery>
#include <QTimer>
#include "paciente.h"

Discharged::Discharged(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Discharged)
{
    ui->setupUi(this);

    UPDATE_lw_DISCHpat();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(UPDATE_lw_DISCHpat()));
    timer->start(9000);
}

Discharged::~Discharged()
{
    delete ui;
}

void Discharged::on_lw_DISCHpat_itemClicked()
{

}

void Discharged::UPDATE_lw_DISCHpat(){
    ui->lw_DISCHpat->clear();
    QSqlQuery q;
    int f = 0, t = 1;
    q.prepare("SELECT patNameFK FROM sae.admissao WHERE hasFinished = :false AND hasStarted = :true");
    q.bindValue(":false", f);
    q.bindValue(":true", t);
    q.exec();
    while (q.next()){
        QString tempName = q.value(0).toString();
        ui->lw_DISCHpat->addItem(tempName);
}
}

void Discharged::on_pb_DISCHARGEaPat_clicked()
{
    QString tempName01 = ui->lw_DISCHpat->currentItem()->text();
    QSqlQuery q;
    q.prepare("UPDATE sae.admissao SET hasFinished = TRUE WHERE patNameFK = :name");
    q.bindValue(":name", tempName01);
    q.exec();
}
