#include "SearchKnowledgeUI.h"
#include <iostream>
#include "SearchKnowledgeResultUI.h"
#include "ui_HtmlPage.h"
#include "KnowledgeCatalog.h"

using namespace std;

SearchKnowledgeUI::SearchKnowledgeUI() : HtmlPage("search_kms")
{
    connect(webFrame, SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));
    ui->search_kms->setEnabled(false);
}

void SearchKnowledgeUI::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("Searcher",this);
}

void SearchKnowledgeUI::submit()
{
    QString query = getValueBySelector("#query").toString();
    QString tagList = getValueBySelector("#tags").toString();
    QSet<QString> tagSet = tagList.split(",").toSet();

    QVector<KnowledgeItem> res = KnowledgeCatalog::getInstance()->search(query,tagSet);

    SearchKnowledgeResult *result = new SearchKnowledgeResult(res);
    result->show();
    this->close();
}
