#include "database.h"

DataBase::DataBase():Singleton<DataBase>(*this){}

QSqlQueryModel *DataBase::SetQuery(QString someQuery)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel(nullptr);
    if(!ok)
    {
       QMessageBox::critical(NULL,QObject::tr("Соединение"),QObject::tr("Ошибка соединения с БД"));
    }
    else
    {
        QSqlQuery query(db);
        if(!query.exec(someQuery))
        {
              QMessageBox::critical(NULL,QObject::tr("Соединение"),query.lastError().text());
        }
        else
        {
            queryModel->setQuery(query);
        }
    }
    return queryModel;
}

QSqlQuery DataBase::Query(QString someQuery)
{
    if(!ok)
    {
       QMessageBox::critical(NULL,QObject::tr("Соединение"),QObject::tr("Ошибка соединения с БД"));
    }
    QSqlQuery query(db);
    if(!query.exec(someQuery))
    {
          QMessageBox::critical(NULL,QObject::tr("Соединение"),query.lastError().text());
    }
    return query;
}

void DataBase::Close()
{
    db.close();
}
bool DataBase::isOk()
{
    return db.isOpen();
}

bool DataBase::Authorization(QString log, QString pass)
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setDatabaseName("postgres");
    db.setUserName(log);
    db.setPassword(pass);
    ok = db.open();
    if(!ok)
    {
        QMessageBox::critical(NULL,QObject::tr("Соединение"),"Ошибка, проверьте правильность вводимых данных");
        return false;
        db.close();
    }
    else
        return true;
}
