#ifndef UPDATENOTIFICATION_H
#define UPDATENOTIFICATION_H

#include "Notification.h"

class UpdateNotification : public Notification
{
public:
    UpdateNotification();
    QString getJS();
};

#endif // UPDATENOTIFICATION_H
