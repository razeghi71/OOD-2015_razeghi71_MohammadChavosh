#ifndef ReviewKMSRequirement_H
#define ReviewKMSRequirement_H

#include "HtmlPage.h"

class ReviewKMSRequirement : public HtmlPage
{
public:
    ReviewKMSRequirement();
public slots:
    void populateJavaScriptWindowObject();
    void submit();
};

#endif // ReviewKMSRequirement_H
