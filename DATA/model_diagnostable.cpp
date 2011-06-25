#include "model_diagnostable.h"

int MODEL_DiagnosTable::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return listOfPairs.size();
}

int MODEL_DiagnosTable::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 6;
}

QVariant MODEL_DiagnosTable::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= listOfPairs.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        QPair<QString, QString> pair = listOfPairs.at(index.row());

        if (index.column() == 0)
            return pair.first;
        else if (index.column() == 1)
            return pair.second;
    }
    return QVariant();
}

QVariant MODEL_DiagnosTable::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Titulo");

            case 1:
                return tr("Taxonomia");

            default:
                return QVariant();
        }
    }
    return QVariant();
}

bool MODEL_DiagnosTable::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row=0; row < rows; row++) {
        QPair<QString, QString> pair(" ", " ");
        listOfPairs.insert(position, pair);
    }

    endInsertRows();
    return true;
}

bool MODEL_DiagnosTable::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row=0; row < rows; ++row) {
        listOfPairs.removeAt(position);
    }

    endRemoveRows();
    return true;
}

bool MODEL_DiagnosTable::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();

        QPair<QString, QString> p = listOfPairs.value(row);

        if (index.column() == 0)
            p.first = value.toString();
        else if (index.column() == 1)
            p.second = value.toString();
        else
            return false;

        listOfPairs.replace(row, p);
        emit(dataChanged(index, index));

        return true;
    }

    return false;
}

Qt::ItemFlags MODEL_DiagnosTable::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QList< QPair<QString, QString> > MODEL_DiagnosTable::getList()
{
    return listOfPairs;
}
