#-------------------------------------------------
#
# Project created by QtCreator 2017-03-06T15:30:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TagMaster
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tag.cpp \
    file.cpp \
    fenprincipale.cpp \
    sessionActuel.cpp

HEADERS  += mainwindow.h \
    tag.h \
    file.h \
    fenprincipale.h \
    sessionActuel.h

FORMS    += mainwindow.ui
