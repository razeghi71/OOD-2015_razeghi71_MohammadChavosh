#ifndef VIEWKNOWLEDGEUI_H
#define VIEWKNOWLEDGEUI_H

#include "HtmlPage.h"
#include "KnowledgeItem.h"
#include <QObject>
#include <QWebFrame>

class ViewKnowledgeUI : public HtmlPage
{
    Q_OBJECT
public:
    ViewKnowledgeUI(KnowledgeItem post);
private:
    KnowledgeItem post;
public slots:
    void populateJavaScriptWindowObject();
};

#endif // VIEWKNOWLEDGEUI_H
