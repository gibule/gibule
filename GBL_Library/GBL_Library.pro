#-------------------------------------------------
#
# Project created by QtCreator 2019-12-14T18:00:50
#
#-------------------------------------------------

QT       -= core gui

TARGET = GBL
TEMPLATE = lib

DEFINES += GBL_LIBRARY_LIBRARY



SOURCES += \
    gblsocket.cpp \
    gblthread.cpp \
    gblworker.cpp

HEADERS += \
    gbllistener.h \
    gblsocket.h \
    gblthread.h \
    gblworker.h \
    gblutility.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
