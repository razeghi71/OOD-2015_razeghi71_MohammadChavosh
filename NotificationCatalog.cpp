#include "NotificationCatalog.h"
#include <QVector>
#include "DB.h"
#include "MessageNotification.h"
#include <QVariant>
#include <QDebug>

NotificationCatalog::NotificationCatalog()
{

}

void NotificationCatalog::addMessage(MessageNotification notif)
{
    DB *db = DB::getInstance();
    QString query = QString("INSERT INTO `MessageNotification` VALUES (NULL,'%1','%2')").
            arg(
                QString::number(notif.getOwner().getId()),
                QString::number(notif.getMsg().getId())
                );

    qDebug() << query ;
    QSqlQuery *res = db->executeQuery(query);
    notif.setId(res->lastInsertId().toInt());
}

QVector<MessageNotification> NotificationCatalog::allMsgNotifs()
{
    QVector<MessageNotification> notifs;

    DB *db = DB::getInstance();
    QString query = QString("SELECT * from `MessageNotification` where `UserID`='%1'").arg(
                UserCatalog::getLoggedInUser().getId()
                );
    QSqlQuery *res = db->executeQuery(query);

    while (res->next())
    {
        notifs.append(MessageNotification::createMessageNotificationBySqlQuery(res));
    }

    return notifs;
}

//QVector<Notification> NotificationCatalog::all()
//{
//    QVector<Notification> notifs;

//    DB *db = DB::getInstance();
//    QString query = "SELECT * from `MessageNotification`";
//    QSqlQuery *res = db->executeQuery(query);

//    while (res->next())
//    {
//        notifs.append(MessageNotification::createMessageNotificationBySqlQuery(res));
//    }

//    return notifs;
//}

NotificationCatalog *NotificationCatalog::getInstance()
{
    static NotificationCatalog *instance = new NotificationCatalog();
    return instance;
}
