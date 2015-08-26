#include "MessageNotification.h"
#include <QVariant>

Message MessageNotification::getMsg() const
{
    return msg;
}

void MessageNotification::setMsg(const Message &value)
{
    msg = value;
}

int MessageNotification::getId() const
{
    return id;
}

void MessageNotification::setId(int value)
{
    id = value;
}

QString MessageNotification::getJS()
{
    return QString("add_message_notif('%1','%2','%3');").arg(
                QString::number(getMsg().getSender().getId()),
                getMsg().getSender().getUsername(),
                getMsg().getTitle()
                );
}
MessageNotification::MessageNotification()
{

}

MessageNotification MessageNotification::createMessageNotificationBySqlQuery(QSqlQuery *res)
{
    int id = res->value("id").toInt();
    User owner = UserCatalog::getInstance()->get(res->value("UserID").toInt());
    Message msg = MessageCatalog::getInstance()->get(res->value("MessageID").toInt());

    MessageNotification msgNotif ;

    msgNotif.setId(id);
    msgNotif.setOwner(owner);
    msgNotif.setMsg(msg);
    return msgNotif;
}


