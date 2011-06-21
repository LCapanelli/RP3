#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QWidget>

namespace Ui {
    class Maintenance;
}

class Maintenance : public QWidget
{
    Q_OBJECT

public:
    explicit Maintenance(QWidget *parent = 0);
    ~Maintenance();

private:
    Ui::Maintenance *ui;
};

#endif // MAINTENANCE_H
