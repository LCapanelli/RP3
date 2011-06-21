#ifndef DISCHARGED_H
#define DISCHARGED_H

#include <QWidget>

namespace Ui {
    class Discharged;
}

class Discharged : public QWidget
{
    Q_OBJECT

public:
    explicit Discharged(QWidget *parent = 0);
    ~Discharged();

private:
    Ui::Discharged *ui;
};

#endif // DISCHARGED_H
