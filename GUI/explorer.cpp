#include "explorer.h"
#include "ui_explorer.h"
#include "diagnostico.h"
#include "qdjango/QDjangoQuerySet.h"
#include "DATA/model_diagnostable.h"
#include <QHeaderView>
#include <QTableWidgetItem>


Explorer::Explorer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Explorer)
{
    ui->setupUi(this);
    ui->tW_showDiagnosReadyOnly->setColumnCount(8);
    QStringList labelList;
    labelList << "ID"<< "Cadastro" << "Título" << "Ano" << "Domínio"
            << "Definição" << "Características Definidoras" << "Fatores Relacionados";
    ui->tW_showDiagnosReadyOnly->setHorizontalHeaderLabels(labelList);
    listUpdate();
    }

Explorer::~Explorer()
{
    delete ui;
}

void Explorer::listUpdate(){
    QDjangoQuerySet <Diagnostico> idDiag ,nomeD, num01, num02, idDom, definicao, cDefin, fRelac;
    QList<qint32> idList;
    QList <int> idDomList;
    QStringList nameList, num01List, num02List, defList, cDList, fRelList;

    //Fills QLists whit content from Diagnostico ORM
    for(int i = 0; i < nomeD.count() && idDiag.count() && num01.count(); ++i){
        idList << idDiag.at(i)->idDiag();
        num01List << num01.at(i)->num01();
        nameList << nomeD.at(i)->nomeDiag();
        num02List << num02.at(i)->num02();
        idDomList << idDom.at(i)->idDom();
        //idClassList << idClasse.at(i)->idClasse();
        defList << definicao.at(i)->definicao();
        cDList << cDefin.at(i)->cDefin();
        fRelList << fRelac.at(i)->fRelac();
    }

    //Fills the GUI TableWidget by column from QLists
    for(int i = 0; i < nameList.count(); ++i){
        ui->tW_showDiagnosReadyOnly->setRowCount(nameList.count());
        ui->tW_showDiagnosReadyOnly->setItem(i, 0, new QTableWidgetItem(idList.at(i)));
        ui->tW_showDiagnosReadyOnly->setItem(i, 1, new QTableWidgetItem(num01List.at(i)));
        ui->tW_showDiagnosReadyOnly->setItem(i, 2, new QTableWidgetItem(nameList.at(i)));
        ui->tW_showDiagnosReadyOnly->setItem(i, 3, new QTableWidgetItem(num02List.at(i)));
        ui->tW_showDiagnosReadyOnly->setItem(i, 4, new QTableWidgetItem(idDomList.at(i)));
        //ui->tW_showDiagnosReadyOnly->setItem(i, 5, new QTableWidgetItem(idClassList.at(i)));
        ui->tW_showDiagnosReadyOnly->setItem(i, 5, new QTableWidgetItem(defList.at(i)));
        ui->tW_showDiagnosReadyOnly->setItem(i, 6, new QTableWidgetItem(cDList.at(i)));
        ui->tW_showDiagnosReadyOnly->setItem(i, 7, new QTableWidgetItem(fRelList.at(i)));
    }

qDebug("====== OK - listUpdate estah executando ======" );
qDebug()<<nameList << idDomList;
}
