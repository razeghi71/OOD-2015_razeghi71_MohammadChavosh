#ifndef SEARCHKNOWLEDGEUI_H
#define SEARCHKNOWLEDGEUI_H

#include "HtmlPage.h"

class SearchKnowledgeUI : public HtmlPage
{
    Q_OBJECT
public:
    SearchKnowledgeUI();

public slots:
    void submit();
    void populateJavaScriptWindowObject();

};

#endif // SEARCHKNOWLEDGEUI_H
