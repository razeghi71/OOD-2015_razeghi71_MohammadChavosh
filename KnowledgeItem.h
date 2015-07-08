#ifndef KNOWLEDGEITEM_H
#define KNOWLEDGEITEM_H

#include<QString>
#include<QDateTime>
#include <QSqlQuery>
#include "User.h"

class KnowledgeItem{
public:
    User getOwner() const;
    void setOwner(const User &value);

    QDateTime getPublishTime() const;
    void setPublishTime(const QDateTime &value);

    QString getText() const;
    void setText(const QString &value);

    QString getTitle() const;
    void setTitle(const QString &value);

    int getId() const;
    void setId(int value);

    static KnowledgeItem createKnowledgeBySqlQuery(QSqlQuery *res);

    KnowledgeItem();

private:
    int id;
    QString title;
    QString text;
    QDateTime publishTime;
    User owner;

    // TODO : add Tag and file
};

#endif
