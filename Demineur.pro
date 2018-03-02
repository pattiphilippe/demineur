TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    case.cpp

QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    case.h
