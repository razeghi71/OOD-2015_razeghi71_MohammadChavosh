#include "LoginUI.h"
#include "ui_HtmlPage.h"
#include "SearchKnowledgeUI.h"
#include <iostream>
#include <QWebElement>
#include <QMessageBox>
#include "DB.h"
#include "UserCatalog.h"

using namespace std;

LoginUI::LoginUI() : HtmlPage("login")
{
    connect(webFrame, SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));
}

void LoginUI::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("Loginer",this);
}

void LoginUI::submit()
{
    QString username = getValueBySelector("#username").toString();
    QString password = getValueBySelector("#password").toString();

//    DB::getInstance()->initializeDBF  irstTime();

    if ( UserCatalog::getInstance()->login(username,password) )
    {
        goToSearchKnowledge();
    } else {
        QMessageBox::critical(this,"خطا در ورود","نام کاربری و یا رمز عبور اشتباه است");
    }
}


