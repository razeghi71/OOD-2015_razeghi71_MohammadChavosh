#include "HtmlPage.h"
#include "ui_HtmlPage.h"
#include <QWebElement>
#include "SearchKnowledgeUI.h"
#include "AddKnowledgeUI.h"
#include "LoginUI.h"
#include "UserCatalog.h"
#include "AddUserUI.h"
#include <QPointer>

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
    connect(ui->logout, SIGNAL(triggered()), this, SLOT(gotoLogin()));
    connect(ui->add_user, SIGNAL(triggered()), this, SLOT(gotoAddUser()));

    if ( UserCatalog::getLoggedInUser().getId() != 0 )
    {
        if ( UserCatalog::getLoggedInUser().getAdmin() )
            ui->add_user->setVisible(true);
        else
            ui->add_user->setVisible(false);

    } else {
        ui->add_user->setVisible(false);
    }
}

QVariant HtmlPage::getValueBySelector(QString selector)
{
    return  webFrame->findFirstElement(selector).evaluateJavaScript("this.value");
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


HtmlPage::~HtmlPage()
{
    delete ui;
}
