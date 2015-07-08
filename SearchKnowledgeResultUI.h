#ifndef SEARCHKNOWLEDGERESULT_H
#define SEARCHKNOWLEDGERESULT_H

#include "HtmlPage.h"
#include <QVector>
#include "KnowledgeCatalog.h"

class SearchKnowledgeResult : public HtmlPage
{
Q_OBJECT
public:
    SearchKnowledgeResult(QVector<KnowledgeItem> res);
public slots:
    void populateJavaScriptWindowObject();

private:
    QVector<KnowledgeItem> result;

};

#endif // SEARCHKNOWLEDGERESULT_H
