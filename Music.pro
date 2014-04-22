#-------------------------------------------------
#
# Project created by QtCreator 2014-04-22T09:45:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Music
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fileinfo.cpp \
    playlistitem.cpp \
    playlistmodel.cpp

HEADERS  += mainwindow.h \
    KPlayer.h \
    fileinfo.h \
    playlistitem.h \
    playlistmodel.h

FORMS    += mainwindow.ui
