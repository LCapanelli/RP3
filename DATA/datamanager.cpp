#include "datamanager.h"
#include <QSqlDatabase>

DataManager::DataManager()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName(":memory:");
    db.open();

}



