#ifndef ESCORTING_H
#define ESCORTING_H

#include <QWidget>

//! @author Lucas Pereira Capanelli

namespace Ui {
    class Escorting;
}

class Escorting : public QWidget
{
    Q_OBJECT

public:
    explicit Escorting(QWidget *parent = 0);
    ~Escorting();

    QString tempIdName;
    qint32 tempIdFK;
    qint32 tempCount;
    qint32 tempCount2;
private:
    Ui::Escorting *ui;

public slots:
    void on_lw_ESCORTINGpatList_itemClicked();
    void UPDATE_lw_ESCORTING();

private slots:
    void on_pb_CONT_clicked();
    void UPDATE_tb_DiagASS();
    void on_pb_EVOLUT_ADD_clicked();
    void on_pb_EVOstates_clicked();
};

#endif // ESCORTING_H
