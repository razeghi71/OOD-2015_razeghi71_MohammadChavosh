#include "AddKnowledgeRequirementUI.h"
#include "ui_HtmlPage.h"
#include "KnowledgeRequestCatalog.h"
#include "UserCatalog.h"
#include <QMessageBox>

using namespace std;

AddKnowledgeRequirementUI::AddKnowledgeRequirementUI() : HtmlPage("add_kms_requirement")
{
    connect(webFrame, SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));

    ui->add_kms_req->setEnabled(false);
}

void AddKnowledgeRequirementUI::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("Adder",this);
}

void AddKnowledgeRequirementUI::submit()
{
        //TODO : add to kms
    QString title = getValueBySelector("#title").toString();
    QString body = getValueBySelector("#message").toString();
    QStringList tags = getValueBySelector("#tags").toString().split(",");

    QVector<Tag> tagList;

    for ( QStringList::iterator it = tags.begin(); it!= tags.end(); it++)
    {
        QString current = *it;
        tagList.append(current);
    }

    KnowledgeRequest *item = new KnowledgeRequest();
    item->setOwner(UserCatalog::getLoggedInUser());
    item->setTitle(title);
    item->setText(body);
    item->setPublishTime(QDateTime::currentDateTime());
    item->setTags(tagList);

    KnowledgeRequestCatalog::getInstance()->add(*item);
    QMessageBox::information(this," تمام","دانش با موفقیت افزوده شد");
}


