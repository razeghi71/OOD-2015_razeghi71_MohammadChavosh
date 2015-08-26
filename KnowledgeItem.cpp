#include "KnowledgeItem.h"
#include "UserCatalog.h"
#include <QVariant>


User KnowledgeItem::getOwner() const
{
    return owner;
}

void KnowledgeItem::setOwner(const User &value)
{
    owner = value;
}

QDateTime KnowledgeItem::getPublishTime() const
{
    return publishTime;
}

void KnowledgeItem::setPublishTime(const QDateTime &value)
{
    publishTime = value;
}

QString KnowledgeItem::getText() const
{
    return text;
}

void KnowledgeItem::setText(const QString &value)
{
    text = value;
}

QString KnowledgeItem::getTitle() const
{
    return title;
}

void KnowledgeItem::setTitle(const QString &value)
{
    title = value;
}

int KnowledgeItem::getId() const
{
    return id;
}

void KnowledgeItem::setId(int value)
{
    id = value;
}

KnowledgeItem KnowledgeItem::createKnowledgeBySqlQuery(QSqlQuery *res)
{
    int id = res->value("id").toInt();
    QString title = res->value("title").toString();
    QString body = res->value("text").toString();
    QDateTime publish_time = res->value("publish_time").toDateTime();

    int owner = res->value("owner").toInt();
    User ownerUser = UserCatalog::getInstance()->get(owner);


    // TODO: add tag and file

    KnowledgeItem item;

    item.setId(id);
    item.setTitle(title);
    item.setText(body);
    item.setPublishTime(publish_time);
    item.setOwner(ownerUser);

    return item;

}

KnowledgeItem::KnowledgeItem()
{
    id = 0;
}
QVector<Tag> KnowledgeItem::getTags() const
{
    return tags;
}

void KnowledgeItem::setTags(const QVector<Tag> &value)
{
    tags = value;
}


