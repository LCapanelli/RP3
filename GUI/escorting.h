#ifndef ESCORTING_H
#define ESCORTING_H

#include <QWidget>

namespace Ui {
    class Escorting;
}

class Escorting : public QWidget
{
    Q_OBJECT

public:
    explicit Escorting(QWidget *parent = 0);
    ~Escorting();

private:
    Ui::Escorting *ui;
};

#endif // ESCORTING_H
