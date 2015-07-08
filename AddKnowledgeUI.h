#ifndef ADDKNOWLEDGEUI_H
#define ADDKNOWLEDGEUI_H

#include <QWebFrame>
#include "HtmlPage.h"
#include "KnowledgeItem.h"
#include "KnowledgeCatalog.h"

class AddKnowledgeUI : public HtmlPage
{
    Q_OBJECT
public:
    AddKnowledgeUI() ;
public slots:
    void submit();
    void populateJavaScriptWindowObject();
};

#endif // ADDKNOWLEDGEUI_H
