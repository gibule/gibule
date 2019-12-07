TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS +=-pthread

SOURCES += \
        main.cpp \
    gblsocket.cpp \
    gblthread.cpp \
    gbllistener.cpp \
    gblworker.cpp \
    gblchat.cpp

HEADERS += \
    gblsocket.h \
    gblthread.h \
    gbllistener.h \
    gblworker.h \
    gblchat.h
