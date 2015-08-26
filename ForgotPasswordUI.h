#ifndef FORGOTPASSWORDUI_H
#define FORGOTPASSWORDUI_H

#include "HtmlPage.h"

class ForgotPasswordUI : public HtmlPage
{
    Q_OBJECT
public:
    ForgotPasswordUI();
public slots:
    void submit();
    void populateJavaScriptWindowObject();
};

#endif // FORGOTPASSWORDUI_H
