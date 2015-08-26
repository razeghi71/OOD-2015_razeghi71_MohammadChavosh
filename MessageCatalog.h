#ifndef MESSAGECATALOG_H
#define MESSAGECATALOG_H

#include "Message.h"
#include <QVector>

class MessageCatalog
{
public:

    static MessageCatalog* getInstance();
    void add(Message &message);
    Message get(int id);
    QVector<Message> all();
private:
    MessageCatalog();
};

#endif // MESSAGECATALOG_H
