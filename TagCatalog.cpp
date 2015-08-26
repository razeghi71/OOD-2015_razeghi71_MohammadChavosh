#include "TagCatalog.h"
#include <QDebug>

TagCatalog *TagCatalog::getInstance()
{
    static TagCatalog *instance = new TagCatalog();
    return instance;
}

void TagCatalog::add(Tag &tag)
{
    DB *db = DB::getInstance();
    QString query = QString("INSERT INTO `Tag` VALUES (NULL,'%1')").
            arg(tag.getText());

    QSqlQuery *res = db->executeQuery(query);
    tag.setId(res->lastInsertId().toInt());
}

bool TagCatalog::exist(Tag tag)
{
    DB *db = DB::getInstance();
    QString query = QString("SELECT * from `Tag` where `text` like '%1'").
            arg(tag.getText());

    QSqlQuery *res = db->executeQuery(query);
    if ( res->next() )
        return true;
    return false;
}

void TagCatalog::relateTagToKnowledge(Tag tag, KnowledgeItem knowledge)
{
    if ( !exist(tag) )
        add(tag);

    DB *db = DB::getInstance();
    QString query = QString("INSERT INTO `KnowledgeTag` VALUES (NULL,'%1','%2')").
            arg(knowledge.getId()).
            arg(tag.getId());

    db->executeQuery(query);
}

void TagCatalog::relateTagToKnowledgeReq(Tag tag, KnowledgeRequest request)
{
    if ( !exist(tag) )
        add(tag);

    DB *db = DB::getInstance();
    QString query = QString("INSERT INTO `KnowledgeRequestTag` VALUES (NULL,'%1','%2')").
            arg(request.getId()).
            arg(tag.getId());


    db->executeQuery(query);
}

TagCatalog::TagCatalog()
{

}
