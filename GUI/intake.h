#ifndef INTAKE_H
#define INTAKE_H

#include <QWidget>
#include "admissao.h"
#include <QListWidgetItem>

namespace Ui {
    class Intake;
}

class Intake : public QWidget
{
    Q_OBJECT

public:
    explicit Intake(QWidget *parent = 0);
    ~Intake();
//    Admissao * tempAdm;

private:
    Ui::Intake *ui;
    QString tempNameP;
    QString tempExFis;
    QString tempAnam;
    int tempPront;
    int tempIdFromIntake;
    int tempIdOut;

public slots:
    void updatePatList_OnIntake();

private slots:
    void on_lw_domDiag_itemClicked(QListWidgetItem* item);
    void on_pb_Intake_finished_clicked();
    void on_pb_CANCEL_INTERV_clicked();
    void on_pb_EXCLUDE_DIAG_clicked();
    void on_pb_CANCEL_Diag_clicked();
    void on_pb_CANCEL_anam_clicked();
    void on_pb_CANCEL_FIS_clicked();
    void on_lw_diagASS4interv_itemClicked(QListWidgetItem* item);
    void on_pb_aprazingInterv_clicked();
    void on_pb_InterventionOK_clicked();
    void on_pb_SAVEassociatedDIAG_clicked();
    void on_pb_SAVEAnamnese_clicked();
    void on_pb_SAVEexFIS_clicked();
    void on_pb_NEWINTAKE_clicked();
    void on_le_SEARCHpatByID_returnPressed();
    void on_pb_SEARCHpatGO_clicked();
    void on_le_SEARCHpatbyName_returnPressed();

    void update_DiagListOnIntake();
    void update_DiagList4interv();
    void update_Act4IntervAndApraz();
    void update_PresAndAprazList();
};

#endif // INTAKE_H
