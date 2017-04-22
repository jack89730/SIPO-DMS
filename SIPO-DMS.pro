#-------------------------------------------------
#
# Project created by QtCreator 2017-04-22T15:41:54
#
#-------------------------------------------------

QT       += core gui
QT  += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SIPO-DMS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui
