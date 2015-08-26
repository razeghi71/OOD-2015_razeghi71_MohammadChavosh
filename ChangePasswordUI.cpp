#include "ChangePasswordUI.h"
#include "ui_HtmlPage.h"
#include "UserCatalog.h"
#include <QMessageBox>

ChangePasswordUI::ChangePasswordUI() : HtmlPage("change_password")
{
    connect(webFrame, SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));

    ui->change_password->setEnabled(false);
}



void ChangePasswordUI::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("Changer",this);
}

void ChangePasswordUI::submit()
{
    QString oldPass = getValueBySelector("#current_password").toString();
    QString newPass = getValueBySelector("#new_password").toString();
    QString newPassConfirm = getValueBySelector("#new_password_confirm").toString();


    if ( UserCatalog::getLoggedInUser().getPassword() == oldPass )
    {
        if ( newPass == newPassConfirm )
        {
            User user = UserCatalog::getLoggedInUser();
            user.setPassword(newPass);
            UserCatalog::getInstance()->add(user);
            QMessageBox::information(this," تمام","پسورد با موفقیت عوض شد");
        }  else {
            QMessageBox::critical(this," متاسفیم","پسورد و تکرار آن با هم برابر نیستند");
        }

    } else
    {
        QMessageBox::critical(this," متاسفیم","پسورد فعلی وارد شده اشتباه هست");
    }


}


