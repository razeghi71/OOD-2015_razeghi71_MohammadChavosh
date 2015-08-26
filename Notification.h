#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include "User.h"

class Notification
{
protected:
    User owner;
public:
    Notification();
    User getOwner() const;
    void setOwner(const User &value);
    virtual QString getJS() = 0;
};

#endif // NOTIFICATION_H
