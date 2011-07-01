#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QWidget>
#include <QListWidget>

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

private slots:
    void on_lw_DiagNIC_itemClicked(QListWidgetItem* item);
    void on_pb_NICRemove_clicked();
    void on_pb_SEARCH_DIAGonNIC_clicked();
    void on_le_FILTER_DIAGonNIC_returnPressed();
    void on_pq_NICSAVE_clicked();
    void on_pb_UserSAVE_clicked();
    void on_pb_SalvarDiag_clicked();
    void nic_updateDiagView();
};

#endif // MAINTENANCE_H
