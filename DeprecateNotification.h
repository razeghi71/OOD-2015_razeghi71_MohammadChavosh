#ifndef DEPRECATENOTIFICATION_H
#define DEPRECATENOTIFICATION_H

#include "Notification.h"

class DeprecateNotification : public Notification
{
public:
    DeprecateNotification();
    QString getJS();
};

#endif // DEPRECATENOTIFICATION_H
