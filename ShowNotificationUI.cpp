#include "ShowNotificationUI.h"
#include <iostream>
#include "ui_HtmlPage.h"
#include <QDebug>
#include "UserCatalog.h"
#include "NotificationCatalog.h"
#include <QMessageBox>
#include <QVector>
#include "Notification.h"

using namespace std;

ShowNotificationUI::ShowNotificationUI() : HtmlPage("show_notifications")
{
    connect(webFrame, SIGNAL(loadFinished(bool)),
            this, SLOT(populateJavaScriptWindowObject()));
    ui->show_notifications->setEnabled(false);
}

void ShowNotificationUI::gotoUserEditor(QString username)
{
    if ( UserCatalog::getLoggedInUser().isAdmin() )
    {
        gotoEditUser(UserCatalog::getInstance()->get(username));
    }
}



void ShowNotificationUI::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("MsgLinker",this);
    QVector<MessageNotification> allNotifs = NotificationCatalog::getInstance()->allMsgNotifs();
    for ( MessageNotification &notif : allNotifs )
    {
        webFrame->evaluateJavaScript (notif.getJS());
    }
}

void ShowNotificationUI::goToViewMsg(int id)
{
    qDebug() << "id " << id;
    gotoViewMesssage(MessageCatalog::getInstance()->get(id));
}



