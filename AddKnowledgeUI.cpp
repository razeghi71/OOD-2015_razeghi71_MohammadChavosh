#include "AddKnowledgeUI.h"
#include <iostream>
#include "ui_HtmlPage.h"
#include <QDebug>
#include "UserCatalog.h"
#include <QMessageBox>
#include "Tag.h"

using namespace std;

AddKnowledgeUI::AddKnowledgeUI() : HtmlPage("add_kms")
{
    connect(webFrame, SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));

    ui->add_kms->setEnabled(false);
}

void AddKnowledgeUI::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("Adder",this);
}

void AddKnowledgeUI::submit()
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



    KnowledgeItem *item = new KnowledgeItem();
    item->setOwner(UserCatalog::getLoggedInUser());
    item->setTitle(title);
    item->setText(body);
    item->setPublishTime(QDateTime::currentDateTime());
    item->setTags(tagList);

    KnowledgeCatalog::getInstance()->add(*item);
    QMessageBox::information(this," تمام","دانش با موفقیت افزوده شد");
}


