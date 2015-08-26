#include "ReviewKMSDeprecation.h"
#include "ui_HtmlPage.h"
#include "UserCatalog.h"
#include <QMessageBox>

using namespace std;

ReviewKMSDeprecation::ReviewKMSDeprecation() : HtmlPage("review_kms_deprecation")
{
    connect(webFrame, SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));
}

void ReviewKMSDeprecation::populateJavaScriptWindowObject()
{
    webFrame->addToJavaScriptWindowObject("Reviewer",this);
}

void ReviewKMSDeprecation::submit()
{
}


