#ifndef DATABASE_H
#define DATABASE_H
#include "Singleton.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QWidget>
#include <QMessageBox>

class Database;
#define DBConnect DataBase::instance()

class DataBase: public Singleton<DataBase>
{
public:
    DataBase();
    QSqlQueryModel *SetQuery(QString someQuery);
    QSqlQuery Query(QString someQuery);

    void Close();
    bool isOk();
    bool Authorization(QString log, QString pass);

private:
    bool ok;
    QSqlDatabase db;
};

#endif // DATABASE_H
