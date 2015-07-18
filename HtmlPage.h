#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWebFrame>
#include "QPointer"

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

protected:
    Ui::HtmlPage *ui;
    QPointer<QWebFrame> webFrame;

protected slots:
    void goToSearchKnowledge();
    void gotoAddKnowledge();
    void gotoLogin();
    void gotoAddUser();

};

#endif // MAINWINDOW_H
