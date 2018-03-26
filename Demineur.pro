TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Model/Case.cpp \
    Main.cpp \
    Model/Game.cpp \
    Model/Board.cpp \
    Model/Coordinates.cpp \
    Model/Category.cpp \
    Model/Score.cpp \
    Model/Controller.cpp

QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    case.h \
    Model/Case.h \
    Model/Game.h \
    Model/Board.h \
    Model/GameException.h \
    Model/Coordinates.h \
    Model/coordinates.h \
    Model/Category.h \
    Model/Score.h \
    Model/Controller.h
