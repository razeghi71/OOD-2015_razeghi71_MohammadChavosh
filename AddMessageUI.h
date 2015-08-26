#ifndef ADDMESSAGEUI_H
#define ADDMESSAGEUI_H

#include "HtmlPage.h"

class AddMessageUI : public HtmlPage
{
    Q_OBJECT
public:
    AddMessageUI();
public slots:
    void populateJavaScriptWindowObject();
    void submit();
};

#endif // ADDMESSAGEUI_H
