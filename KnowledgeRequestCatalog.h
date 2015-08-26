#ifndef KNOWLEDGEREQUESTCATALOG_H
#define KNOWLEDGEREQUESTCATALOG_H

#include "KnowledgeRequest.h"

class KnowledgeRequestCatalog
{
public:
    static KnowledgeRequestCatalog* getInstance();
    void add(KnowledgeRequest &req);
private:
    KnowledgeRequestCatalog();
};

#endif // KNOWLEDGEREQUESTCATALOG_H
