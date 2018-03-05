TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Model/Case.cpp \
    Main.cpp

QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    case.h \
    Model/Case.h
