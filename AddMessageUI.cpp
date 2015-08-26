#include "AddMessageUI.h"
#include "ui_HtmlPage.h"
#include "Message.h"
#include "UserCatalog.h"
#include "MessageCatalog.h"
#include <QMessageBox>
#include "NotificationCatalog.h"

AddMessageUI::AddMessageUI() : HtmlPage("send_message")
{

    connect(webFrame, SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));

    ui->send_message->setEnabled(false);

}


void AddMessageUI::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("Sender",this);
}

void AddMessageUI::submit()
{

    QString username = getValueBySelector("#username").toString();
    QString subject = getValueBySelector("#subject").toString();
    QString message = getValueBySelector("#message").toString();

    User reciever = UserCatalog::getInstance()->get(username);

    Message msg;
    msg.setBody(message);
    msg.setTitle(subject);
    msg.setSender(UserCatalog::getLoggedInUser());
    msg.setReciver(reciever);

    MessageCatalog::getInstance()->add(msg);

    MessageNotification msgNotif;
    msgNotif.setMsg(msg);
    msgNotif.setOwner(reciever);

    NotificationCatalog::getInstance()->addMessage(msgNotif);
    QMessageBox::information(this," تمام","پیغام با موفقیت فرستاده شد");

}
