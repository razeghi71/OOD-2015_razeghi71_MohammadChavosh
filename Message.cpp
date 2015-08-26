#include "Message.h"
#include <QVariant>

Message::Message()
{
    id = 0;
}
User Message::getSender() const
{
    return sender;
}

void Message::setSender(const User &value)
{
    sender = value;
}
QString Message::getTitle() const
{
    return title;
}

void Message::setTitle(const QString &value)
{
    title = value;
}

User Message::getReciver() const
{
    return reciver;
}

void Message::setReciver(const User &value)
{
    reciver = value;
}

QString Message::getBody() const
{
    return body;
}

void Message::setBody(const QString &value)
{
    body = value;
}


Message Message::createMessageBySqlQuery(QSqlQuery *res)
{
    int id = res->value("id").toInt();
    User sender = UserCatalog::getInstance()->get(res->value("SenderID").toInt());
    User reciever = UserCatalog::getInstance()->get(res->value("RecieverID").toInt());
    QString title = res->value("subject").toString();
    QString message = res->value("body").toString();

    Message msg ;

    msg.setId(id);
    msg.setReciver(reciever);
    msg.setSender(sender);
    msg.setTitle(title);
    msg.setBody(message);

    return msg;
}

int Message::getId() const
{
    return id;
}

void Message::setId(int value)
{
    id = value;
}

