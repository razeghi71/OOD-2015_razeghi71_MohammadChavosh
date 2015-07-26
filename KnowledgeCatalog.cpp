#include "KnowledgeCatalog.h"
#include "DB.h"
#include <QDebug>
#include <QSqlError>

KnowledgeCatalog::KnowledgeCatalog()
{

}

KnowledgeCatalog* KnowledgeCatalog::getInstance()
{
    static KnowledgeCatalog* kc = new KnowledgeCatalog();
    return kc;
}


void KnowledgeCatalog::addKnowledge(KnowledgeItem item)
{
    DB *db = DB::getInstance();
    QString query = QString("INSERT INTO `KnowledgeItem` VALUES (NULL,'%1','%2','%3','%4'); ").
            arg(item.getTitle(),
                item.getText(),
                item.getPublishTime().toString("yyyy-MM-ddTHH:MM"),
                QString::number(item.getOwner().getId())
                );

    QSqlQuery *res = db->executeQuery(query);
}

QVector<KnowledgeItem> KnowledgeCatalog::search(QString searchQuery, QSet<QString> tag)
{
    QVector<KnowledgeItem> searchResult;
    DB *db = DB::getInstance();
    QString query = QString("SELECT * from `KnowledgeItem` where `title` LIKE '\%%1\%' OR `text` LIKE '\%%1\%'").
            arg(searchQuery);

    qDebug() << query;

    QSqlQuery *res = db->executeQuery(query);

    //TODO: add tag to search

    while(res->next())
    {
        KnowledgeItem resultItem = KnowledgeItem::createKnowledgeBySqlQuery(res);
        searchResult.push_back(resultItem);
    }
    return searchResult;
}

