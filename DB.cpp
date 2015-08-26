#include "DB.h"
#include <QDebug>
#include <QSqlError>
#include "UserCatalog.h"

DB::DB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("kms.db");

    if ( !db.open() )
    {
        qFatal("can not connect to db")   ;
    } else {
//        qDebug() << "Database Openned Successfully";
    }
}

DB::~DB()
{
    db.close();
}

void DB::initializeDBFirstTime()
{
    QFile *file = new QFile(":/sql/init.sql");
    file->open(QIODevice::ReadOnly | QIODevice::Text);
    executeQueriesFromFile(file);


    /* test data */

    User admin;
    admin.setUsername("mohammad");
    admin.setPassword("mohammad");
    admin.setType(0);

    User simple;
    simple.setUsername("ali");
    simple.setPassword("ali");
    simple.setType(1);

    UserCatalog::getInstance()->add(simple);
    UserCatalog::getInstance()->add(admin);

    qDebug() << "initialized database";
}

QSqlQuery* DB::executeQuery(QString q)
{
    QSqlQuery *query = new QSqlQuery(db);
    query->exec(q);
    return query;
}

void DB::executeQueriesFromFile(QFile *file)
{
    QSqlQuery *query = new QSqlQuery(db);
    while (!file->atEnd()){

        QByteArray readLine="";
        QString cleanedLine;
        QString line="";
        bool finished=false;
        while(!finished){
            readLine = file->readLine();
            cleanedLine=readLine.trimmed();
            // remove comments at end of line
            if ( cleanedLine == "")
                break;

            QStringList strings=cleanedLine.split("--");
            cleanedLine=strings.at(0);

            // remove lines with only comment, and DROP lines
            if(!cleanedLine.startsWith("--")

                    && !cleanedLine.startsWith("DROP")
                    && !cleanedLine.isEmpty()){
                line+=cleanedLine;
            }
            if(cleanedLine.endsWith(";")){
                break;
            }
            if(cleanedLine.startsWith("END")){
                finished=true;
            }
        }

        if(!line.isEmpty()){
            qDebug() << line;
            query->exec(line);
        }
        if(!query->isActive()){
            qFatal(query->lastError().text().toStdString().c_str());
        }
    }
}

DB* DB::getInstance()
{
    static DB *instance = new DB();
    return instance;
}

