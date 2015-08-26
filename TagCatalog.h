#ifndef TAGCATALOG_H
#define TAGCATALOG_H

#include "DB.h"
#include "Tag.h"
#include "KnowledgeItem.h"
#include "KnowledgeRequest.h"
#include <QVariant>


class TagCatalog{
public :
    static TagCatalog* getInstance();
    void add(Tag &tag);
    bool exist(Tag tag);
    void relateTagToKnowledge(Tag tag, KnowledgeItem knowledge);
    void relateTagToKnowledgeReq(Tag tag, KnowledgeRequest request);
private:
    TagCatalog();
};

#endif
