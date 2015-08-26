#include "ReviewKMSRequirement.h"
#include "ui_HtmlPage.h"
#include "UserCatalog.h"
#include <QMessageBox>

using namespace std;

ReviewKMSRequirement::ReviewKMSRequirement() : HtmlPage("review_kms_requirement")
{
    connect(webFrame, SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));
}

void ReviewKMSRequirement::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("Reviewer",this);
}

void ReviewKMSRequirement::submit()
{
}


