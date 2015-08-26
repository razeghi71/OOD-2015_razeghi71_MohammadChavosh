#ifndef MESSAGE_H
#define MESSAGE_H

#include "UserCatalog.h"
#include "DB.h"

class Message
{

public:
    Message();

    QString getBody() const;
    void setBody(const QString &value);

    User getReciver() const;
    void setReciver(const User &value);

    User getSender() const;
    void setSender(const User &value);

    QString getTitle() const;
    void setTitle(const QString &value);

    static Message createMessageBySqlQuery(QSqlQuery *res);

    int getId() const;
    void setId(int value);

private:
    User sender;
    User reciver;
    QString title;
    QString body;
    int id;

};

#endif // MESSAGE_H
