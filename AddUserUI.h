#ifndef ADDUSERUI_H
#define ADDUSERUI_H

#include <QWebFrame>
#include "HtmlPage.h"

class AddUserUI : public HtmlPage
{
    Q_OBJECT
public:
    AddUserUI() ;
public slots:
    void submit();
    void populateJavaScriptWindowObject();
};

#endif // ADDUSERUI_H
