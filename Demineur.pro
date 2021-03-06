TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
#☺CONFIG -= qt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += core gui

SOURCES += \
    Model/Case.cpp \
    Model/Game.cpp \
    Model/Board.cpp \
    Util/Coordinates.cpp \
    Scores/Score.cpp \
    Tests/CoordinatesTest.cpp \
    Tests/CaseTests.cpp \
    Tests/BoardTests.cpp \
    View/ConsoleView.cpp \
    Controller.cpp \
    View/ConsoleRead.cpp \
    Libraries/observer/subject.cpp \
    Tests/GameTests.cpp \
    Tests/scoretests.cpp \
    Demineur.cpp \
    GUI/LcdTimer.cpp \
    GUI/configurationdialog.cpp \
    GUI/mainwindow.cpp \
    GUI/MineFieldObserver.cpp \
    GUI/MineSweeperButton.cpp \
    GUI/enddialog.cpp

QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    Model/Case.h \
    Model/Game.h \
    Model/Board.h \
    Util/GameException.h \
    Util/Coordinates.h \
    Scores/Score.h \
    Controller.h \
    View/Consoleview.h \
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
    Libraries/keyboardAndStringConvert/keyboard.hpp \
    Libraries/keyboardAndStringConvert/stringConvert.hpp \
    View/ConsoleRead.h \
    Libraries/observer/observer.h \
    Libraries/observer/subject.h \
    GUI/LcdTimer.h \
    GUI/configurationdialog.h \
    GUI/mainwindow.h \
    GUI/MineFieldObserver.h \
    GUI/MineSweeperButton.h \
    GUI/ui_configurationdialog.h \
    GUI/ui_mainwindow.h \
    GUI/enddialog.h

DISTFILES += \
    Scores.json \
    Libraries/rapidjson/bin/data/glossary.json \
    Libraries/rapidjson/bin/data/menu.json \
    Libraries/rapidjson/bin/data/sample.json \
    Libraries/rapidjson/bin/data/webapp.json \
    Libraries/rapidjson/bin/data/widget.json \
    Libraries/rapidjson/bin/encodings/utf16be.json \
    Libraries/rapidjson/bin/encodings/utf16bebom.json \
    Libraries/rapidjson/bin/encodings/utf16le.json \
    Libraries/rapidjson/bin/encodings/utf16lebom.json \
    Libraries/rapidjson/bin/encodings/utf32be.json \
    Libraries/rapidjson/bin/encodings/utf32bebom.json \
    Libraries/rapidjson/bin/encodings/utf32le.json \
    Libraries/rapidjson/bin/encodings/utf32lebom.json \
    Libraries/rapidjson/bin/encodings/utf8.json \
    Libraries/rapidjson/bin/encodings/utf8bom.json \
    Libraries/rapidjson/bin/jsonchecker/fail1.json \
    Libraries/rapidjson/bin/jsonchecker/fail10.json \
    Libraries/rapidjson/bin/jsonchecker/fail11.json \
    Libraries/rapidjson/bin/jsonchecker/fail12.json \
    Libraries/rapidjson/bin/jsonchecker/fail13.json \
    Libraries/rapidjson/bin/jsonchecker/fail14.json \
    Libraries/rapidjson/bin/jsonchecker/fail15.json \
    Libraries/rapidjson/bin/jsonchecker/fail16.json \
    Libraries/rapidjson/bin/jsonchecker/fail17.json \
    Libraries/rapidjson/bin/jsonchecker/fail18.json \
    Libraries/rapidjson/bin/jsonchecker/fail19.json \
    Libraries/rapidjson/bin/jsonchecker/fail2.json \
    Libraries/rapidjson/bin/jsonchecker/fail20.json \
    Libraries/rapidjson/bin/jsonchecker/fail21.json \
    Libraries/rapidjson/bin/jsonchecker/fail22.json \
    Libraries/rapidjson/bin/jsonchecker/fail23.json \
    Libraries/rapidjson/bin/jsonchecker/fail24.json \
    Libraries/rapidjson/bin/jsonchecker/fail25.json \
    Libraries/rapidjson/bin/jsonchecker/fail26.json \
    Libraries/rapidjson/bin/jsonchecker/fail27.json \
    Libraries/rapidjson/bin/jsonchecker/fail28.json \
    Libraries/rapidjson/bin/jsonchecker/fail29.json \
    Libraries/rapidjson/bin/jsonchecker/fail3.json \
    Libraries/rapidjson/bin/jsonchecker/fail30.json \
    Libraries/rapidjson/bin/jsonchecker/fail31.json \
    Libraries/rapidjson/bin/jsonchecker/fail32.json \
    Libraries/rapidjson/bin/jsonchecker/fail33.json \
    Libraries/rapidjson/bin/jsonchecker/fail4.json \
    Libraries/rapidjson/bin/jsonchecker/fail5.json \
    Libraries/rapidjson/bin/jsonchecker/fail6.json \
    Libraries/rapidjson/bin/jsonchecker/fail7.json \
    Libraries/rapidjson/bin/jsonchecker/fail8.json \
    Libraries/rapidjson/bin/jsonchecker/fail9.json \
    Libraries/rapidjson/bin/jsonchecker/pass1.json \
    Libraries/rapidjson/bin/jsonchecker/pass2.json \
    Libraries/rapidjson/bin/jsonchecker/pass3.json \
    Libraries/rapidjson/bin/jsonschema/remotes/folder/folderInteger.json \
    Libraries/rapidjson/bin/jsonschema/remotes/integer.json \
    Libraries/rapidjson/bin/jsonschema/remotes/subSchemas.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/optional/bignum.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/optional/format.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/optional/jsregex.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/optional/zeroTerminatedFloats.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/additionalItems.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/additionalProperties.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/default.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/dependencies.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/disallow.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/divisibleBy.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/enum.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/extends.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/items.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/maximum.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/maxItems.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/maxLength.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/minimum.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/minItems.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/minLength.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/pattern.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/patternProperties.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/properties.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/ref.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/refRemote.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/required.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/type.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft3/uniqueItems.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/optional/bignum.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/optional/format.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/optional/zeroTerminatedFloats.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/additionalItems.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/additionalProperties.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/allOf.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/anyOf.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/default.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/definitions.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/dependencies.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/enum.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/items.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/maximum.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/maxItems.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/maxLength.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/maxProperties.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/minimum.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/minItems.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/minLength.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/minProperties.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/multipleOf.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/not.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/oneOf.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/pattern.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/patternProperties.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/properties.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/ref.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/refRemote.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/required.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/type.json \
    Libraries/rapidjson/bin/jsonschema/tests/draft4/uniqueItems.json \
    Libraries/rapidjson/bin/types/booleans.json \
    Libraries/rapidjson/bin/types/floats.json \
    Libraries/rapidjson/bin/types/guids.json \
    Libraries/rapidjson/bin/types/integers.json \
    Libraries/rapidjson/bin/types/mixed.json \
    Libraries/rapidjson/bin/types/nulls.json \
    Libraries/rapidjson/bin/types/paragraphs.json \
    Libraries/rapidjson/bin/jsonschema/.travis.yml \
    Libraries/rapidjson/bin/jsonschema/README.md \
    Libraries/rapidjson/bin/data/readme.txt \
    Libraries/rapidjson/bin/draft-04/schema \
    Libraries/rapidjson/bin/jsonchecker/readme.txt \
    Libraries/rapidjson/bin/jsonschema/.gitignore \
    Libraries/rapidjson/bin/jsonschema/LICENSE \
    Libraries/rapidjson/bin/jsonschema/tox.ini \
    Libraries/rapidjson/bin/types/readme.txt \
    Libraries/rapidjson/bin/jsonschema/bin/jsonschema_suite \
    html/search/all_0.js \
    html/search/all_1.js \
    html/search/all_2.js \
    html/search/all_3.js \
    html/search/all_4.js \
    html/search/all_5.js \
    html/search/all_6.js \
    html/search/all_7.js \
    html/search/all_8.js \
    html/search/all_9.js \
    html/search/all_a.js \
    html/search/all_b.js \
    html/search/classes_0.js \
    html/search/classes_1.js \
    html/search/classes_2.js \
    html/search/classes_3.js \
    html/search/functions_0.js \
    html/search/functions_1.js \
    html/search/functions_2.js \
    html/search/functions_3.js \
    html/search/functions_4.js \
    html/search/functions_5.js \
    html/search/functions_6.js \
    html/search/functions_7.js \
    html/search/functions_8.js \
    html/search/functions_9.js \
    html/search/functions_a.js \
    html/search/functions_b.js \
    html/search/search.js \
    html/search/searchdata.js \
    html/dynsections.js \
    html/jquery.js \
    html/menu.js \
    html/menudata.js \
    html/search/close.png \
    html/search/mag_sel.png \
    html/search/search_l.png \
    html/search/search_m.png \
    html/search/search_r.png \
    html/bc_s.png \
    html/bdwn.png \
    html/class_game_exception.png \
    html/closed.png \
    html/doc.png \
    html/doxygen.png \
    html/folderclosed.png \
    html/folderopen.png \
    html/nav_f.png \
    html/nav_g.png \
    html/nav_h.png \
    html/open.png \
    html/splitbar.png \
    html/sync_off.png \
    html/sync_on.png \
    html/tab_a.png \
    html/tab_b.png \
    html/tab_h.png \
    html/tab_s.png \
    html/search/search.css \
    html/doxygen.css \
    html/tabs.css \
    html/search/all_0.html \
    html/search/all_1.html \
    html/search/all_2.html \
    html/search/all_3.html \
    html/search/all_4.html \
    html/search/all_5.html \
    html/search/all_6.html \
    html/search/all_7.html \
    html/search/all_8.html \
    html/search/all_9.html \
    html/search/all_a.html \
    html/search/all_b.html \
    html/search/classes_0.html \
    html/search/classes_1.html \
    html/search/classes_2.html \
    html/search/classes_3.html \
    html/search/functions_0.html \
    html/search/functions_1.html \
    html/search/functions_2.html \
    html/search/functions_3.html \
    html/search/functions_4.html \
    html/search/functions_5.html \
    html/search/functions_6.html \
    html/search/functions_7.html \
    html/search/functions_8.html \
    html/search/functions_9.html \
    html/search/functions_a.html \
    html/search/functions_b.html \
    html/search/nomatches.html \
    html/_board_8h_source.html \
    html/_case_8h_source.html \
    html/_category_8h_source.html \
    html/_consoleview_8h_source.html \
    html/_controller_8h_source.html \
    html/_coordinates_8h_source.html \
    html/_game_8h_source.html \
    html/_game_exception_8h_source.html \
    html/_score_8h_source.html \
    html/annotated.html \
    html/class_board-members.html \
    html/class_board.html \
    html/class_board_public-members.html \
    html/class_board_public.html \
    html/class_case-members.html \
    html/class_case.html \
    html/class_case_public-members.html \
    html/class_case_public.html \
    html/class_category-members.html \
    html/class_category.html \
    html/class_console_view-members.html \
    html/class_console_view.html \
    html/class_controller-members.html \
    html/class_controller.html \
    html/class_coordinates-members.html \
    html/class_coordinates.html \
    html/class_game-members.html \
    html/class_game.html \
    html/class_game_exception-members.html \
    html/class_game_exception.html \
    html/class_score-members.html \
    html/class_score.html \
    html/classes.html \
    html/dir_312950da3f243a51cc00f4a947545131.html \
    html/dir_33c78a012c8d08979f57a54a07694c46.html \
    html/dir_a74f5c11d993936efe832c80e3919182.html \
    html/dir_d4f7a754e06480f800a6fab4b04999ce.html \
    html/dir_f2ee84e8e3a17eaa7015d788fa443c27.html \
    html/files.html \
    html/functions.html \
    html/functions_func.html \
    html/hierarchy.html \
    html/index.html \
    html/maintests_8h_source.html

FORMS += \
    GUI/configurationdialog.ui \
    GUI/mainwindow.ui \
    GUI/enddialog.ui

RESOURCES += \
    minesweeperimg.qrc



