#include "ShowMessageUI.h"
#include "ui_HtmlPage.h"
#include "Message.h"
#include "UserCatalog.h"
#include "MessageCatalog.h"
#include <QMessageBox>

ShowMessageUI::ShowMessageUI(Message msg) : HtmlPage("show_message")
{
    this->msg = msg;

    connect(webFrame, SIGNAL(loadFinished(bool)),
            this, SLOT(populateJavaScriptWindowObject()));

    ui->send_message->setEnabled(false);

}


void ShowMessageUI::populateJavaScriptWindowObject()
{
    QString jsTitle = QString("$('#title').html('%1 از طرف <small>%2</small>')").arg(msg.getTitle(),msg.getSender().getUsername());
    QString jsBody = QString("$('#body').html('%1')").arg( msg.getBody());


    webFrame->evaluateJavaScript(jsTitle);
    webFrame->evaluateJavaScript(jsBody);
}

void ShowMessageUI::submit()
{
}
