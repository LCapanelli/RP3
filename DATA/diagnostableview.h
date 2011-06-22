#ifndef DIAGNOSTABLEVIEW_H
#define DIAGNOSTABLEVIEW_H

#include <QAbstractTableModel>

class DiagnosTableView : public
        QAbstractTableModel
{
    Q_OBJECT
public:
    DiagnosTableView();
};

#endif // DIAGNOSTABLEVIEW_H
