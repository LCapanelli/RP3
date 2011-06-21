#ifndef INTAKE_H
#define INTAKE_H

#include <QWidget>

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
};

#endif // INTAKE_H
