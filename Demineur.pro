TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Model/Case.cpp \
    Main.cpp \
    Model/Game.cpp \
    Model/Board.cpp \
    Model/Coordinates.cpp

QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    case.h \
    Model/Case.h \
    Model/Game.h \
    Model/Board.h \
    Model/GameException.h \
    Model/Coordinates.h \
    Model/coordinates.h
