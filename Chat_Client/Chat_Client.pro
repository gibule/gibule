TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_LIBDIR = ../GBL_Library
LIBS += -pthread \
        -lGBL

SOURCES += \
        main.cpp \
    gblchatclient.cpp

HEADERS += \
    gblchatclient.h
