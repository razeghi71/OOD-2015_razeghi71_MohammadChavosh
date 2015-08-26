#ifndef ADDKNOWLEDGEREQUIREMENTUI_H
#define ADDKNOWLEDGEREQUIREMENTUI_H


#include <QWebFrame>
#include "HtmlPage.h"
#include "KnowledgeItem.h"
#include "KnowledgeCatalog.h"

class AddKnowledgeRequirementUI : public HtmlPage
{
    Q_OBJECT
public:
    AddKnowledgeRequirementUI() ;
public slots:
    void submit();
    void populateJavaScriptWindowObject();
};


#endif // ADDKNOWLEDGEREQUIREMENTUI_H
