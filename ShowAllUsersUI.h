#ifndef ShowAllUsersUI_H
#define ShowAllUsersUI_H

#include <QWebFrame>
#include "HtmlPage.h"

class ShowAllUsersUI : public HtmlPage
{
    Q_OBJECT
public:
    ShowAllUsersUI() ;
public slots:
    void gotoUserEditor(QString username);
    void populateJavaScriptWindowObject();
};

#endif // ShowAllUsersUI_H
