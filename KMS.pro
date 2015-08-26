#-------------------------------------------------
#
# Project created by QtCreator 2015-07-06T16:48:13
#
#-------------------------------------------------

QT       += core gui webkitwidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KMS
TEMPLATE = app

CONFIG += c++11



SOURCES += Tag.cpp \
    Employee.cpp \
    User.cpp \
    main.cpp \
    HtmlPage.cpp \
    Admin.cpp \
    KnowledgeItem.cpp\
    KnowledgeCatalog.cpp \
    TagCatalog.cpp \
    UserCatalog.cpp \
    LoginUI.cpp \
    SearchKnowledgeUI.cpp \
    SearchKnowledgeResultUI.cpp \
    AddKnowledgeUI.cpp \
    DB.cpp \
    AddUserUI.cpp \
    ViewKnowledgeUI.cpp \
    Message.cpp \
    MessageCatalog.cpp \
    Notification.cpp \
    MessageNotification.cpp \
    NotificationCatalog.cpp \
    AddMessageUI.cpp \
    AddKnowledgeRequirementUI.cpp \
    KnowledgeRequest.cpp \
    KnowledgeRequestCatalog.cpp \
    ChangePasswordUI.cpp \
    EditUserUI.cpp \
    EditUserProfileUI.cpp \
    ForgotPasswordUI.cpp \
    SMTP/emailaddress.cpp \
    SMTP/mimeattachment.cpp \
    SMTP/mimefile.cpp \
    SMTP/mimehtml.cpp \
    SMTP/mimeinlinefile.cpp \
    SMTP/mimemessage.cpp \
    SMTP/mimepart.cpp \
    SMTP/mimetext.cpp \
    SMTP/smtpclient.cpp \
    SMTP/quotedprintable.cpp \
    SMTP/mimemultipart.cpp \
    SMTP/mimecontentformatter.cpp \
    ReviewKMSDeprecation.cpp \
    ReviewKMSRequirement.cpp \
    ShowAllUsersUI.cpp \
    ShowMessageUI.cpp \
    DeprecateNotification.cpp \
    RequestNotification.cpp \
    UpdateNotification.cpp \
    ShowNotificationUI.cpp


HEADERS  += Admin.h \
    Tag.h \
    HtmlPage.h \
    KnowledgeItem.h \
    User.h \
    Employee.h \
    UserCatalog.h \
    KnowledgeCatalog.h \
    TagCatalog.h \
    defines.h \
    LoginUI.h \
    SearchKnowledgeUI.h \
    SearchKnowledgeResultUI.h \
    AddKnowledgeUI.h \
    DB.h \
    AddUserUI.h \
    ViewKnowledgeUI.h \
    Message.h \
    MessageCatalog.h \
    Notification.h \
    MessageNotification.h \
    NotificationCatalog.h \
    AddMessageUI.h \
    AddKnowledgeRequirementUI.h \
    KnowledgeRequest.h \
    KnowledgeRequestCatalog.h \
    ChangePasswordUI.h \
    EditUserUI.h \
    EditUserProfileUI.h \
    ForgotPasswordUI.h \
    SMTP/emailaddress.h \
    SMTP/mimeattachment.h \
    SMTP/mimefile.h \
    SMTP/mimehtml.h \
    SMTP/mimeinlinefile.h \
    SMTP/mimemessage.h \
    SMTP/mimepart.h \
    SMTP/mimetext.h \
    SMTP/smtpclient.h \
    SMTP/SmtpMime \
    SMTP/quotedprintable.h \
    SMTP/mimemultipart.h \
    SMTP/mimecontentformatter.h \
    SMTP/smtpexports.h \
    ReviewKMSDeprecation.h \
    ReviewKMSRequirement.h \
    ShowAllUsersUI.h \
    ShowMessageUI.h \
    DeprecateNotification.h \
    RequestNotification.h \
    UpdateNotification.h \
    ShowNotificationUI.h

FORMS    += HtmlPage.ui

RESOURCES +=    res.qrc
