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

private:
    Ui::Intake *ui;
    QString tempNameP;

public slots:
    void updatePatList_OnIntake();

private slots:
    void on_pq_SAVEassociatedDIAG_clicked();
    void on_pb_SAVEAnamnese_clicked();
    void on_pb_SAVEexFIS_clicked();
    void on_pb_NEWINTAKE_clicked();
    void on_le_SEARCHpatByID_returnPressed();
    void on_pb_SEARCHpatGO_clicked();
    void on_le_SEARCHpatbyName_returnPressed();

    void update_DiagListOnIntake();
};

#endif // INTAKE_H
