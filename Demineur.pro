TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Model/Case.cpp \
    Model/Game.cpp \
    Model/Board.cpp \
    Util/Coordinates.cpp \
    Scores/Category.cpp \
    Scores/Score.cpp \
    Controller.cpp \
    Tests/CoordinatesTest.cpp \
    Tests/CaseTests.cpp

QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    case.h \
    Model/Case.h \
    Model/Game.h \
    Model/Board.h \
    Util/GameException.h \
    Util/Coordinates.h \
    Scores/Category.h \
    Scores/Score.h \
    Controller.h \
    Libraries/catch.hpp
