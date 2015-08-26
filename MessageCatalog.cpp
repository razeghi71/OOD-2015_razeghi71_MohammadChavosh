#include "MessageCatalog.h"
#include <QDebug>

MessageCatalog* MessageCatalog::getInstance()
{
    static MessageCatalog *instance;
    return instance;
}

void MessageCatalog::add(Message &message)
{
    DB *db = DB::getInstance();
    QString query = QString("INSERT INTO `Message` VALUES (NULL,'%1','%2','%3','%4');").
            arg(QString::number( message.getSender().getId() ),
                QString::number( message.getReciver().getId()),
                message.getTitle(),
                message.getBody()
                );

    QSqlQuery *res = db->executeQuery(query);
    message.setId(res->lastInsertId().toInt());
}

Message MessageCatalog::get(int id)
{
    DB *db = DB::getInstance();
    QString query = QString("SELECT * from `Message` where `id`='%1'").arg(QString::number(id));
    QSqlQuery *res = db->executeQuery(query);

    if (res->next())
    {
        return Message::createMessageBySqlQuery(res);
    }
    return Message();

}

QVector<Message> MessageCatalog::all()
{
}

