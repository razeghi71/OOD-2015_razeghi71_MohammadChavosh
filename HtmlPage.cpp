#include "HtmlPage.h"
#include "ui_HtmlPage.h"
#include <QWebElement>
#include "SearchKnowledgeUI.h"
#include "AddKnowledgeUI.h"
#include "AddMessageUI.h"
#include "LoginUI.h"
#include "UserCatalog.h"
#include "AddUserUI.h"
#include "AddKnowledgeRequirementUI.h"
#include <QPointer>
#include "ChangePasswordUI.h"
#include "EditUserProfileUI.h"
#include "EditUserUI.h"
#include "ForgotPasswordUI.h"
#include "ViewKnowledgeUI.h"
#include "ShowAllUsersUI.h"
#include "ShowNotificationUI.h"
#include "ShowMessageUI.h"

HtmlPage::HtmlPage(QString page_name) :
    QMainWindow(0),
    ui(new Ui::HtmlPage)
{
    ui->setupUi(this);
    ui->webView->setUrl(
                QUrl("qrc:/gui/UI/" + page_name + ".html")
                );
    webFrame =  ui->webView->page()->mainFrame();
    connect(ui->search_kms, SIGNAL(triggered()), this, SLOT(goToSearchKnowledge()));
    connect(ui->add_kms, SIGNAL(triggered()), this, SLOT(gotoAddKnowledge()));
    connect(ui->send_message, SIGNAL(triggered()), this, SLOT(gotoSendMessage()));
    connect(ui->add_kms_req, SIGNAL(triggered()), this, SLOT(gotoAddKnowledgeReq()));
    connect(ui->show_notifications, SIGNAL(triggered()), this, SLOT(gotoViewNotifications()));


    connect(ui->logout, SIGNAL(triggered()), this, SLOT(gotoLogin()));
    connect(ui->add_user, SIGNAL(triggered()), this, SLOT(gotoAddUser()));
    connect(ui->change_password, SIGNAL(triggered()), this, SLOT(gotoChangePassword()));
    connect(ui->edit_current_user, SIGNAL(triggered()), this, SLOT(gotoEditUserProfile()));
    connect(ui->forgot_password, SIGNAL(triggered()), this, SLOT(gotoForgotPassword()));
    connect(ui->all_users, SIGNAL(triggered()), this, SLOT(gotoViewAllUsers()));

    if ( UserCatalog::getLoggedInUser().getId() != 0 )
    {
        ui->forgot_password->setVisible(false);

        if ( UserCatalog::getLoggedInUser().isAdmin() )
            ui->add_user->setVisible(true);
        else
            ui->add_user->setVisible(false);

    } else {
        ui->add_user->setVisible(false);
        ui->forgot_password->setVisible(true);
        ui->go->setEnabled(false);
        ui->logout->setEnabled(false);
    }
}

QVariant HtmlPage::getValueBySelector(QString selector)
{
    return  webFrame->findFirstElement(selector).evaluateJavaScript("this.value");
}

QVariant HtmlPage::getSelectByValue(QString selector)
{
    return  webFrame->findFirstElement(selector).evaluateJavaScript("$(this).val()");
}


void HtmlPage::goToSearchKnowledge()
{
    SearchKnowledgeUI *searchWindow = new SearchKnowledgeUI();
    searchWindow->show();
    this->close();
}

void HtmlPage::gotoAddKnowledge()
{
    AddKnowledgeUI *addWindow = new AddKnowledgeUI();
    addWindow->show();
    this->close();
}

void HtmlPage::gotoSendMessage()
{
    AddMessageUI *msgWindow = new AddMessageUI();
    msgWindow->show();
    this->close();
}

void HtmlPage::gotoLogin()
{
    LoginUI *loginWindow = new LoginUI();
    loginWindow->show();
    this->close();
}

void HtmlPage::gotoAddUser()
{
    AddUserUI *addUserWindow = new AddUserUI();
    addUserWindow->show();
    this->close();
}

void HtmlPage::gotoAddKnowledgeReq()
{
    AddKnowledgeRequirementUI *knowledgeReqUi = new AddKnowledgeRequirementUI();
    knowledgeReqUi->show();
    this->close();
}

void HtmlPage::gotoForgotPassword()
{
    ForgotPasswordUI *forgot_password = new ForgotPasswordUI();
    forgot_password->show();
    this->close();

}

void HtmlPage::gotoViewAllUsers()
{
    ShowAllUsersUI *allUsers = new ShowAllUsersUI();
    allUsers->show();
    this->close();
}

void HtmlPage::gotoChangePassword()
{
    ChangePasswordUI *passwordChange = new ChangePasswordUI();
    passwordChange->show();
    this->close();
}


void HtmlPage::gotoEditUser(User user)
{
    EditUserUI *edit_profile = new EditUserUI(user);
    edit_profile->show();
    this->close();
}

void HtmlPage::gotoViewNotifications()
{
    ShowNotificationUI *notifs = new ShowNotificationUI();
    notifs->show();
    this->close();
}

void HtmlPage::gotoViewMesssage(Message msg)
{
    ShowMessageUI *msgView = new ShowMessageUI(msg);
    msgView->show();
    this->close();
}


void HtmlPage::gotoEditUserProfile()
{
    EditUserProfileUI *edit_profile = new EditUserProfileUI();
    edit_profile->show();
    this->close();
}

void HtmlPage::gotoViewPost(KnowledgeItem post)
{
    ViewKnowledgeUI *knowlegeView = new ViewKnowledgeUI(post);
    knowlegeView->show();
    this->close();
}


HtmlPage::~HtmlPage()
{
    delete ui;
}
