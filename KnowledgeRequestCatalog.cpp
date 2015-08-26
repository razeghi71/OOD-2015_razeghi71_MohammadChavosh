#include "KnowledgeRequestCatalog.h"
#include "DB.h"
#include <QVector>
#include "TagCatalog.h"

KnowledgeRequestCatalog *KnowledgeRequestCatalog::getInstance()
{
    static KnowledgeRequestCatalog* instance = new KnowledgeRequestCatalog;
    return instance;
}

void KnowledgeRequestCatalog::add(KnowledgeRequest &req)
{
    DB *db = DB::getInstance();
    QString query = QString("INSERT INTO `KnowledgeRequest` VALUES (NULL,'%1','%2','%3','%4');").
            arg(req.getTitle(),
                req.getText(),
                req.getPublishTime().toString("yyyy-MM-ddTHH:MM"),
                QString::number(req.getOwner().getId())
                );

    QSqlQuery *res = db->executeQuery(query);
    req.setId(res->lastInsertId().toInt());
    QVector<Tag> tagList = req.getTags();

    for ( QVector<Tag>::iterator it = tagList.begin();
          it != tagList.end();
          it++
        )
    {
        Tag tag = *it;
        TagCatalog::getInstance()->relateTagToKnowledgeReq(tag,req);
    }

}

KnowledgeRequestCatalog::KnowledgeRequestCatalog()
{

}

