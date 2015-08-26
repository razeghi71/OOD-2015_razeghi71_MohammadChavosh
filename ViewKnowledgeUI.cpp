#include "ViewKnowledgeUI.h"


ViewKnowledgeUI::ViewKnowledgeUI(KnowledgeItem post) : HtmlPage("show_kms_entry")
{
    this->post = post;
    connect(webFrame, SIGNAL(loadFinished(bool  )),
            this, SLOT(populateJavaScriptWindowObject()));

}


void ViewKnowledgeUI::populateJavaScriptWindowObject()
{
    webFrame->evaluateJavaScript(QString("$('#title').text('%1')").arg(post.getTitle()));
    webFrame->evaluateJavaScript(QString("$('#body').text('%1')").arg(post.getText()));
}
