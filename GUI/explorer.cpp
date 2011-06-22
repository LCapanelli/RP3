#include "explorer.h"
#include "ui_explorer.h"
#include "diagnostico.h"
//#include "qdjango/QDjangoQuerySet.h"
//#include "DATA/model_diagnostable.h"

Explorer::Explorer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Explorer)
{
    ui->setupUi(this);
}

Explorer::~Explorer()
{
    delete ui;
}

void Explorer::listUpdate(){
        //QDjangoQuerySet <Diagnostico> nomeD;

//    for (int i = 0; i < nomeD.count(); ++i){
//        QListWidgetItem * item = new QListWidgetItem(nomeD.at(i)->nomeDiag(), ui.diagnosticos_adm);
//        item->setData(Qt::UserRole, nomeD.at(i)->idDiag());
}
