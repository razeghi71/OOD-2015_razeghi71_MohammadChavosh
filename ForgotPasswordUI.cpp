#include "ForgotPasswordUI.h"
#include "ui_HtmlPage.h"
#include "SMTP/SmtpMime"
#include "UserCatalog.h"
#include <QMessageBox>

ForgotPasswordUI::ForgotPasswordUI() : HtmlPage("forget_password")
{
    connect(webFrame, SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));

    ui->forgot_password->setEnabled(false);
}

void ForgotPasswordUI::submit()
{
    QString email = getValueBySelector("#email").toString();
    User user = UserCatalog::getInstance()->getByEmail(email);
    if ( user.getId()!= 0){

        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
        smtp.setUser("razeghi71@gmail.com");
        smtp.setPassword("LaElahaEllaHoo");

        MimeMessage message;

        EmailAddress sender("razeghi71@gmail.com", "Mohammad Razeghi");
        message.setSender(&sender);

        EmailAddress to(user.getEmail(), user.getName());
        message.addRecipient(&to);

        message.setSubject("Password Rest");

        MimeText text;

        text.setText("Hi,\nYour Password is:" + user.getPassword());

        message.addPart(&text);


        if (!smtp.connectToHost()) {
            QMessageBox::critical(this,"ناموفق","ارتباط با سرور موفقیت آمیر نبود");
            return ;
        }

        if (!smtp.login()) {
            QMessageBox::critical(this,"ناموفق","مشخصات ایمیل فرستنده اشتباه است");
            return ;
        }

        if (!smtp.sendMail(message)) {
            QMessageBox::critical(this,"ناموفق","ریدیمارتباط مشکل دارد");
            return ;
        }

        smtp.quit();
        QMessageBox::information(this, "تلباس", "رمز به ایمیل شما ارسال شد");
    } else {
        QMessageBox::critical(this,"ناموفق","چنین ایمیلی موجود نبود");
    }

}

void ForgotPasswordUI::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("Sender",this);
}

