#include "SearchKnowledgeResultUI.h"

#include "ui_HtmlPage.h"
#include "SearchKnowledgeUI.h"
#include <iostream>
#include <QWebElement>
using namespace std;

SearchKnowledgeResult::SearchKnowledgeResult(QVector<KnowledgeItem> res) : HtmlPage("search_kms_results")
{
    this->result = res;
    connect(webFrame, SIGNAL(loadFinished(bool  )),
            this, SLOT(populateJavaScriptWindowObject()));
}

void SearchKnowledgeResult::viewPost(int id)
{
    gotoViewPost(KnowledgeCatalog::getInstance()->get(id));
}

void SearchKnowledgeResult::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("Viewer",this);

    for (int i = 0; i < result.size() ; i++)
    {
        KnowledgeItem item = result.at(i);

        QString tagRes;
        for ( Tag &i : item.getTags())
        {
            tagRes += i.getText().append(",");
        }

        tagRes.chop(1);

        QString js = QString("add_new_result('%1','%2','%3','%4');").arg(
                    item.getTitle(),
                    item.getText(),
                    tagRes,
                    QString::number(item.getId()));
        qDebug() << js;
        webFrame->evaluateJavaScript(js);
    }
}
