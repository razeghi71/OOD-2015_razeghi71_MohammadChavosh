#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWebFrame>
#include "QPointer"
#include "KnowledgeItem.h"
#include "Message.h"

namespace Ui {
    class HtmlPage;
}

class HtmlPage : public QMainWindow
{
    Q_OBJECT

public:
    HtmlPage(QString page_name);
    QVariant getValueBySelector(QString selector);
    virtual void populateJavaScriptWindowObject() = 0;

    ~HtmlPage();

    QVariant getSelectByValue(QString selector);
protected:
    Ui::HtmlPage *ui;
    QPointer<QWebFrame> webFrame;

protected slots:
    void goToSearchKnowledge();
    void gotoAddKnowledge();
    void gotoLogin();
    void gotoAddUser();
    void gotoSendMessage();
    void gotoAddKnowledgeReq();
    void gotoForgotPassword();
    void gotoViewAllUsers();
    void gotoChangePassword();
    void gotoEditUserProfile();
    void gotoViewPost(KnowledgeItem post);
    void gotoEditUser(User user);
    void gotoViewNotifications();
    void gotoViewMesssage(Message msg);
};

#endif // MAINWINDOW_H
