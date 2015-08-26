#ifndef EDITUSERUI_H
#define EDITUSERUI_H


#include "HtmlPage.h"
#include "UserCatalog.h"


class EditUserUI : public HtmlPage
{
    Q_OBJECT
    User user_edit;
public:
    EditUserUI(User edit_user) ;
public slots:
    void submit();
    void deactivate();
    void populateJavaScriptWindowObject();
    void initCurrentData();
};


#endif // EDITUSERPROFILEUI_H
