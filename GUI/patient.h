#ifndef PATIENT_H
#define PATIENT_H

#include <QWidget>

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
    void on_pb_saveCPatient_clicked();
};

#endif // PATIENT_H
