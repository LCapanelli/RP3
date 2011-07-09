#ifndef PATIENT_H
#define PATIENT_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
    class Patient;
}

class Patient : public QWidget
{
    Q_OBJECT

public:
    explicit Patient(QWidget *parent = 0);
    ~Patient();

private:
    Ui::Patient *ui;

private slots:
    void on_le_prontSearch_returnPressed();
    void on_pb_selPatient_clicked();
    void on_pb_discardPatient_clicked();
    void on_pb_NewPatient_clicked();
    void on_pb_cleanPatList_clicked();
    void on_lw_filtredPatients_itemClicked(QListWidgetItem* item);
    void on_pb_paciente_clicked();
    void on_le_patFILTER_returnPressed();
    void filtred_Patients();
    void on_pb_saveCPatient_clicked();

    void updateTablePatientInfo();
};

#endif // PATIENT_H
