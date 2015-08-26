#ifndef ShowMessageUI_H
#define ShowMessageUI_H

#include "HtmlPage.h"
#include "Message.h"

class ShowMessageUI : public HtmlPage
{
    Message msg;
    Q_OBJECT
public:
    ShowMessageUI(Message msg);
public slots:
    void populateJavaScriptWindowObject();
    void submit();
};

#endif // ShowMessageUI_H
