#include "KnowledgeRequest.h"

KnowledgeRequest::KnowledgeRequest()
{

}
int KnowledgeRequest::getId() const
{
    return id;
}

void KnowledgeRequest::setId(int value)
{
    id = value;
}
QString KnowledgeRequest::getTitle() const
{
    return title;
}

void KnowledgeRequest::setTitle(const QString &value)
{
    title = value;
}
QString KnowledgeRequest::getText() const
{
    return text;
}

void KnowledgeRequest::setText(const QString &value)
{
    text = value;
}
QDateTime KnowledgeRequest::getPublishTime() const
{
    return publishTime;
}

void KnowledgeRequest::setPublishTime(const QDateTime &value)
{
    publishTime = value;
}
User KnowledgeRequest::getOwner() const
{
    return owner;
}

void KnowledgeRequest::setOwner(const User &value)
{
    owner = value;
}
QVector<Tag> KnowledgeRequest::getTags() const
{
    return tags;
}

void KnowledgeRequest::setTags(const QVector<Tag> &value)
{
    tags = value;
}







