#ifndef KNOWLEDGEREQUIREMENT_H
#define KNOWLEDGEREQUIREMENT_H


#include<QString>
#include<QDateTime>
#include <QSqlQuery>
#include "Tag.h"
#include "User.h"
#include <QVector>

class KnowledgeRequest{
public:

    KnowledgeRequest();

    int getId() const;
    void setId(int value);

    QString getTitle() const;
    void setTitle(const QString &value);

    QString getText() const;
    void setText(const QString &value);

    QDateTime getPublishTime() const;
    void setPublishTime(const QDateTime &value);

    User getOwner() const;
    void setOwner(const User &value);

    QVector<Tag> getTags() const;
    void setTags(const QVector<Tag> &value);

private:
    int id;
    QString title;
    QString text;
    QDateTime publishTime;
    User owner;
    QVector<Tag> tags;
};

#endif // KNOWLEDGEREQUIREMENT_H
