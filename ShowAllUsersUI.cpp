#include "ShowAllUsersUI.h"
#include <iostream>
#include "ui_HtmlPage.h"
#include <QDebug>
#include "UserCatalog.h"
#include <QMessageBox>

using namespace std;

ShowAllUsersUI::ShowAllUsersUI() : HtmlPage("show_all_users")
{
    connect(webFrame, SIGNAL(loadFinished(bool)),
            this, SLOT(populateJavaScriptWindowObject()));
    ui->all_users->setEnabled(false);
}

void ShowAllUsersUI::gotoUserEditor(QString username)
{
    if ( UserCatalog::getLoggedInUser().isAdmin() )
    {
        gotoEditUser(UserCatalog::getInstance()->get(username));
    }
}



void ShowAllUsersUI::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("Editor",this);
    QVector<User> allUsers = UserCatalog::getInstance()->all();
    for ( auto &user : allUsers )
    {
        QString js = QString("add_user('%1','%2','%3','%4');").arg(
                user.getPersonelCode(),
                user.getUsername(),
                user.getName(),
                user.getFamily());
        qDebug() << js;
        webFrame->evaluateJavaScript (
                    js
                    );
    }
}



