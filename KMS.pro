#-------------------------------------------------
#
# Project created by QtCreator 2015-07-06T16:48:13
#
#-------------------------------------------------

QT       += core gui webkitwidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KMS
TEMPLATE = app


SOURCES += ./Tag.cpp \
    ./Employee.cpp \
    ./User.cpp \
    ./main.cpp \
    ./Role.cpp \
    ./HtmlPage.cpp \
    ./Admin.cpp \
    ./KnowledgeItem.cpp\
    ./KnowledgeCatalog.cpp \
    ./RoleCatalog.cpp \
    ./TagCatalog.cpp \
    ./UserCatalog.cpp \
    LoginUI.cpp \
    SearchKnowledgeUI.cpp \
    SearchKnowledgeResultUI.cpp \
    AddKnowledgeUI.cpp \
    DB.cpp \
    AddUserUI.cpp \
    ViewKnowledgeUI.cpp


HEADERS  += ./Admin.h \
    ./Tag.h \
    ./Role.h \
    ./HtmlPage.h \
    ./KnowledgeItem.h \
    ./User.h \
    ./Employee.h \
    ./UserCatalog.h \
    ./KnowledgeCatalog.h \
    ./TagCatalog.h \
    ./RoleCatalog.h \
    defines.h \
    LoginUI.h \
    SearchKnowledgeUI.h \
    SearchKnowledgeResultUI.h \
    AddKnowledgeUI.h \
    DB.h \
    AddUserUI.h \
    ViewKnowledgeUIh


FORMS    += HtmlPage.ui

RESOURCES +=    res.qrc
