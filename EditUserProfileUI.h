#ifndef EDITUSERPROFILEUI_H
#define EDITUSERPROFILEUI_H


#include "HtmlPage.h"
#include "UserCatalog.h"


class EditUserProfileUI : public HtmlPage
{
    Q_OBJECT

public:
    EditUserProfileUI() ;
public slots:
    void submit();
    void populateJavaScriptWindowObject();
    void initCurrentData();
};


#endif // EDITUSERPROFILEUI_H
