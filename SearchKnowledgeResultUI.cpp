#include "SearchKnowledgeResultUI.h"

#include "ui_HtmlPage.h"
#include "SearchKnowledgeUI.h"
#include <iostream>
#include <QWebElement>
using namespace std;

SearchKnowledgeResult::SearchKnowledgeResult(QVector<KnowledgeItem> res) : HtmlPage("search_kms_results")
{
    this->result = res;
    connect(webFrame, SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));
}


void SearchKnowledgeResult::populateJavaScriptWindowObject()
{

    QWebElementCollection summaryElements = webFrame->findAllElements(".result-summary");
    QWebElementCollection titleElements = webFrame->findAllElements(".result-title");
    for (int i = 0; i < std::min(result.size(),3) ; i++)
    {
        KnowledgeItem item = result.at(i);
        summaryElements.at(i).firstChild().evaluateJavaScript("this.innerHTML='" + item.getText() +"';");
        titleElements.at(i).
                firstChild().
                firstChild().
                evaluateJavaScript("this.innerHTML='<span class=\\'glyphicon glyphicon-triangle-left\\'></span>" + item.getTitle() +"';");
    }
}



