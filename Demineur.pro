TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Model/Case.cpp \
    Main.cpp \
    Model/Game.cpp \
    Model/Board.cpp \
    Model/Util/Coordinates.cpp \
    Category.cpp \
    Score.cpp \
    Controller.cpp

QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    case.h \
    Model/Case.h \
    Model/Game.h \
    Model/Board.h \
    Model/Util/GameException.h \
    Model/Util/Coordinates.h \
    Model/Category.h \
    Model/Score.h \
    Model/Controller.h
