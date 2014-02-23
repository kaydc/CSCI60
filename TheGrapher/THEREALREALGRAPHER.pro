#-------------------------------------------------
#
# Project created by QtCreator 2014-02-13T11:27:22
#
#-------------------------------------------------

QT       += core gui

CONFIG -= x86_64

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = THEREALREALGRAPHER
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    grapher.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    grapher.h \
    about.h

FORMS    += mainwindow.ui \
    about.ui
