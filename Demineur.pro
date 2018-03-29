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
    ConsoleDemineur.cpp \
    Model/Board.cpp \
    Model/Case.cpp \
    Model/Game.cpp \
    Scores/Category.cpp \
    Scores/Score.cpp \
    Tests/BoardTests.cpp \
    Tests/CaseTests.cpp \
    Tests/CoordinatesTest.cpp \
    Util/Coordinates.cpp \
    View/ConsoleView.cpp \
    ConsoleDemineur.cpp \
    Controller.cpp

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
    Libraries/rapidjson/include/rapidjson/error/en.h \
    Libraries/rapidjson/include/rapidjson/error/error.h \
    Libraries/rapidjson/include/rapidjson/internal/biginteger.h \
    Libraries/rapidjson/include/rapidjson/internal/diyfp.h \
    Libraries/rapidjson/include/rapidjson/internal/dtoa.h \
    Libraries/rapidjson/include/rapidjson/internal/ieee754.h \
    Libraries/rapidjson/include/rapidjson/internal/itoa.h \
    Libraries/rapidjson/include/rapidjson/internal/meta.h \
    Libraries/rapidjson/include/rapidjson/internal/pow10.h \
    Libraries/rapidjson/include/rapidjson/internal/regex.h \
    Libraries/rapidjson/include/rapidjson/internal/stack.h \
    Libraries/rapidjson/include/rapidjson/internal/strfunc.h \
    Libraries/rapidjson/include/rapidjson/internal/strtod.h \
    Libraries/rapidjson/include/rapidjson/internal/swap.h \
    Libraries/rapidjson/include/rapidjson/msinttypes/inttypes.h \
    Libraries/rapidjson/include/rapidjson/msinttypes/stdint.h \
    Libraries/rapidjson/include/rapidjson/allocators.h \
    Libraries/rapidjson/include/rapidjson/cursorstreamwrapper.h \
    Libraries/rapidjson/include/rapidjson/document.h \
    Libraries/rapidjson/include/rapidjson/encodedstream.h \
    Libraries/rapidjson/include/rapidjson/encodings.h \
    Libraries/rapidjson/include/rapidjson/filereadstream.h \
    Libraries/rapidjson/include/rapidjson/filewritestream.h \
    Libraries/rapidjson/include/rapidjson/fwd.h \
    Libraries/rapidjson/include/rapidjson/istreamwrapper.h \
    Libraries/rapidjson/include/rapidjson/memorybuffer.h \
    Libraries/rapidjson/include/rapidjson/memorystream.h \
    Libraries/rapidjson/include/rapidjson/ostreamwrapper.h \
    Libraries/rapidjson/include/rapidjson/pointer.h \
    Libraries/rapidjson/include/rapidjson/prettywriter.h \
    Libraries/rapidjson/include/rapidjson/rapidjson.h \
    Libraries/rapidjson/include/rapidjson/reader.h \
    Libraries/rapidjson/include/rapidjson/schema.h \
    Libraries/rapidjson/include/rapidjson/stream.h \
    Libraries/rapidjson/include/rapidjson/stringbuffer.h \
    Libraries/rapidjson/include/rapidjson/writer.h \
    Libraries/catch.hpp \
    Model/Board.h \
    Model/Case.h \
    Model/Game.h \
    Scores/Category.h \
    Scores/Score.h \
    Util/Coordinates.h \
    Util/GameException.h \
    View/consoleview.h \
    Controller.h

