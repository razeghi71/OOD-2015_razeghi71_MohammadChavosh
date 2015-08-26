#include "EditUserProfileUI.h"
#include <iostream>
#include "ui_HtmlPage.h"
#include <QDebug>
#include "UserCatalog.h"
#include <QMessageBox>
#include <QWebFrame>

using namespace std;

EditUserProfileUI::EditUserProfileUI() : HtmlPage("edit_user_profile")
{
    connect(webFrame, SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));
    connect(webFrame, SIGNAL(loadFinished(bool)),
            this, SLOT(initCurrentData()));
}

void EditUserProfileUI::initCurrentData()
{
    User user_edit = UserCatalog::getLoggedInUser();

    webFrame->evaluateJavaScript(QString("$('#username').val('%1')").arg(user_edit.getUsername()));
    webFrame->evaluateJavaScript(QString("$('#first_name').val('%1')").arg(user_edit.getName()));
    webFrame->evaluateJavaScript(QString("$('#last_name').val('%1')").arg(user_edit.getFamily()));
    webFrame->evaluateJavaScript(QString("$('#national_code').val('%1')").arg(user_edit.getNationalCode()));
    webFrame->evaluateJavaScript(QString("$('#personal_code').val('%1')").arg(user_edit.getPersonelCode()));
    webFrame->evaluateJavaScript(QString("$('#email').val('%1')").arg(user_edit.getEmail()));
}

void EditUserProfileUI::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("Changer",this);
}


void EditUserProfileUI::submit()
{

    QString username = getValueBySelector("#username").toString();
    QString name = getValueBySelector("#first_name").toString();
    QString family = getValueBySelector("#last_name").toString();
    QString email = getValueBySelector("#email").toString();
    QString national_code = getValueBySelector("#national_code").toString();
    QString personel_code = getValueBySelector("#personal_code").toString();

    User user =  UserCatalog::getInstance()->get(username);
    user.setName( name );
    user.setFamily( family );
    user.setEmail( email );
    user.setNationalCode( national_code );
    user.setPersonelCode( personel_code );

    UserCatalog::getInstance()->add(user);
    QMessageBox::information(this,"تلباس","مشخصات با موفقیت عوض گردید");
}
