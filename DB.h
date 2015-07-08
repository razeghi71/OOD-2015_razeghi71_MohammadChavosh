#ifndef DB_H
#define DB_H

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QFile>
#include <QSqlRecord>


class DB
{
private:
    QSqlDatabase db;
    DB();
    ~DB();
    void executeQueriesFromFile(QFile *file);
public:
    static DB* getInstance();
    void initializeDBFirstTime();
    QSqlQuery* executeQuery(QString q);
};

#endif // DB_H
