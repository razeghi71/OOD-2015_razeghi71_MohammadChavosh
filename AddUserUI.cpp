#include "AddUserUI.h"
#include <iostream>
#include "ui_HtmlPage.h"
#include <QDebug>
#include "UserCatalog.h"
#include <QMessageBox>

using namespace std;

AddUserUI::AddUserUI() : HtmlPage("add_user")
{
    connect(webFrame, SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));

}


void AddUserUI::submit()
{
    User user;
    user.setUsername( getValueBySelector("#username").toString() );
    user.setPassword( getValueBySelector("#password").toString() );
    user.setName( getValueBySelector("#first_name").toString() );
    user.setFamily( getValueBySelector("#last_name").toString() );
    user.setEmail(getValueBySelector("#email").toString());
    user.setNationalCode(getValueBySelector("#national_code").toString());
    user.setPersonelCode(getValueBySelector("#personal_code").toString());

    UserCatalog::getInstance()->registerUser(user);
    QMessageBox::information(this,"موفقیت","ثبت نام با موفقیت برگزار شد");

}

void AddUserUI::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("UserAdder",this);
}
