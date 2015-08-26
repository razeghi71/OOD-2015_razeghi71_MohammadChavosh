#include "Notification.h"


User Notification::getOwner() const
{
    return owner;
}

void Notification::setOwner(const User &value)
{
    owner = value;
}
Notification::Notification()
{

}

