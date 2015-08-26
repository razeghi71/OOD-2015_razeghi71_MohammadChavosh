#ifndef ShowNotificationUI_H
#define ShowNotificationUI_H

#include <QWebFrame>
#include "HtmlPage.h"

class ShowNotificationUI : public HtmlPage
{
    Q_OBJECT
public:
    ShowNotificationUI() ;
public slots:
    void gotoUserEditor(QString username);
    void populateJavaScriptWindowObject();
    void goToViewMsg(int id);
};

#endif // ShowNotificationUI_H
