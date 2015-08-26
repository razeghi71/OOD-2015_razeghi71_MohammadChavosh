#ifndef REQUESTNOTIFICATION_H
#define REQUESTNOTIFICATION_H

#include "Notification.h"

class RequestNotification : public Notification
{
public:
    RequestNotification();
    QString getJS();
};

#endif // REQUESTNOTIFICATION_H
