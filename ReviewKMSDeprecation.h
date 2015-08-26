#ifndef REVIEWKMSDEPRECATION_H
#define REVIEWKMSDEPRECATION_H

#include "HtmlPage.h"

class ReviewKMSDeprecation : public HtmlPage
{
public:
    ReviewKMSDeprecation();
public slots:
    void populateJavaScriptWindowObject();
    void submit();
};

#endif // REVIEWKMSDEPRECATION_H
