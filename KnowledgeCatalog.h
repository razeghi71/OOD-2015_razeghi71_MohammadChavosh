#ifndef KNOWLEDGECATALOG_H
#define KNOWLEDGECATALOG_H

#include <QString>
#include "User.h"
#include "KnowledgeItem.h"
#include <QVector>
#include <QSet>

class KnowledgeCatalog{
private :
    KnowledgeCatalog();
public :
    static KnowledgeCatalog* getInstance();
    void add(KnowledgeItem item);
    KnowledgeItem get(int id);
    QVector<KnowledgeItem> search(QString searchQuery,QSet<QString> tagList);
};

#endif
