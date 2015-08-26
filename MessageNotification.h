#ifndef MESSAGENOTIFICATION_H
#define MESSAGENOTIFICATION_H

#include "Notification.h"
#include "MessageCatalog.h"
#include <QSqlQuery>

class MessageNotification : public Notification
{
    Message msg;
    int id;
public:
    MessageNotification();
    static MessageNotification createMessageNotificationBySqlQuery(QSqlQuery *res);

    Message getMsg() const;
    void setMsg(const Message &value);
    int getId() const;
    void setId(int value);

    QString getJS();
};

#endif // MESSAGENOTIFICATION_H
