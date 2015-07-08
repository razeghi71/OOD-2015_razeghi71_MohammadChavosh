#ifndef LOGINUI_H
#define LOGINUI_H
#include <QWebFrame>
#include "HtmlPage.h"

class LoginUI : public HtmlPage
{
    Q_OBJECT
public:
    LoginUI() ;
public slots:
    void submit();
    void populateJavaScriptWindowObject();
};

#endif // LOGINUI_H
