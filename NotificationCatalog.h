#ifndef NOTIFICATIONCATALOG_H
#define NOTIFICATIONCATALOG_H

#include "Notification.h"
#include <QVector>
#include <QPointer>
#include "MessageNotification.h"

using namespace std;

class NotificationCatalog
{
    NotificationCatalog();
public:
//    QVector<Notification> all();
//    void add(Notification notif);
    QVector<MessageNotification> allMsgNotifs();
    static NotificationCatalog* getInstance();
    void addMessage(MessageNotification notif);
};

#endif // NOTIFICATIONCATALOG_H
