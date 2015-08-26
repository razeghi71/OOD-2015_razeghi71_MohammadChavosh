#ifndef CHANGEPASSWORDUI_H
#define CHANGEPASSWORDUI_H

#include <QWebFrame>
#include "HtmlPage.h"

class ChangePasswordUI : public HtmlPage
{
    Q_OBJECT
public:
    ChangePasswordUI();
public slots:
    void populateJavaScriptWindowObject();
    void submit();
};

#endif // CHANGEPASSWORDUI_H
