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
    Tests/CaseTests.cpp \
    Tests/BoardTests.cpp \
    Model/Board.cpp \
    Model/Case.cpp \
    Model/Game.cpp \
    Scores/Category.cpp \
    Scores/Score.cpp \
    Tests/BoardTests.cpp \
    Tests/CaseTests.cpp \
    Tests/CoordinatesTest.cpp \
    Util/Coordinates.cpp \
    Controller.cpp \
    Model/Board.cpp \
    Model/Case.cpp \
    Model/Game.cpp \
    Scores/Category.cpp \
    Scores/Score.cpp \
    Tests/BoardTests.cpp \
    Tests/CaseTests.cpp \
    Tests/CoordinatesTest.cpp \
    Util/Coordinates.cpp \
    Controller.cpp \
    View/ConsoleView.cpp

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
    Libraries/catch.hpp \
    Libraries/catch.hpp \
    Model/Board.h \
    Model/Case.h \
    Model/Game.h \
    Scores/Category.h \
    Scores/Score.h \
    Util/Coordinates.h \
    Util/GameException.h \
    Controller.h \
    Libraries/catch.hpp \
    Model/Board.h \
    Model/Case.h \
    Model/Game.h \
    Scores/Category.h \
    Scores/Score.h \
    Util/Coordinates.h \
    Util/GameException.h \
    Controller.h \
    View/Consoleview.h \
    View/ConsoleView.h
