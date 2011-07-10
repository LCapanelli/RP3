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

private slots:
    void on_pb_DISCHARGEaPat_clicked();
    void on_lw_DISCHpat_itemClicked();
    void UPDATE_lw_DISCHpat();
};

#endif // DISCHARGED_H
