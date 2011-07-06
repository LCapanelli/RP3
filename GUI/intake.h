#ifndef INTAKE_H
#define INTAKE_H

#include <QWidget>
#include "admissao.h"

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

public slots:
    void updatePatList_OnIntake();

private slots:
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
    void update_PresAndAprazList();
};

#endif // INTAKE_H
