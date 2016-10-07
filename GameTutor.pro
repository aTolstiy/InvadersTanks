#-------------------------------------------------
#
# Project created by QtCreator 2016-06-15T11:50:07
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameTutor
TEMPLATE = app


SOURCES += main.cpp \
    MyRect.cpp \
    Bullet.cpp \
    Enemy.cpp


//HEADERS  += mainwindow.h

//FORMS    += mainwindow.ui

HEADERS += \
    MyRect.h \
    Bullet.h \
    Enemy.h
