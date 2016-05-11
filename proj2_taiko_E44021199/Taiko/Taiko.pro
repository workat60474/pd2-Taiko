#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T16:46:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taiko
TEMPLATE = app


SOURCES += main.cpp \
    mycircle.cpp \
    score.cpp \
    mytime.cpp \
    moving_face.cpp \
    button.cpp

HEADERS  += \
    moving_face.h \
    mycircle.h \
    score.h \
    mytime.h \
    button.h

FORMS    +=

RESOURCES += \
    resc.qrc
