#include "Tests/maintests.h"

#if RUN_TESTS

#include "Libraries/catch.hpp" // has to be imported in every test file
#include "Util/Coordinates.h"

using namespace std;

TEST_CASE("Coordinates creation", "Coord create") {
    int line, column;
    SECTION("origin coord"){
        line = 0;
        column = 0;
    }
    SECTION("pos coord"){
        line = 1;
        column = 1;
    }
    SECTION("negative coord"){
        line = -1;
        column = -1;
    }
    SECTION("great number coord"){
        line = 1000;
        column = 1000;
    }

    Coordinates c {line, column};
    REQUIRE(c.getLine() == line);
    REQUIRE(c.getColumn() == column);
}

TEST_CASE("Moving a coordinate with a Direction", "[move(Direction)]"){
    Direction dir;
    Coordinates src {0, 0};
    SECTION("N"){
        Coordinates dest = src.move(N);
        REQUIRE(dest.getLine() == 1);
        REQUIRE(dest.getColumn() == 0);
    }
    SECTION("NE"){
        Coordinates dest = src.move(NE);
        REQUIRE(dest.getLine() == 1);
        REQUIRE(dest.getColumn() == 1);
    }
    SECTION("E"){
        Coordinates dest = src.move(E);
        REQUIRE(dest.getLine() == 0);
        REQUIRE(dest.getColumn() == 1);
    }
    SECTION("SE"){
        Coordinates dest = src.move(SE);
        REQUIRE(dest.getLine() == -1);
        REQUIRE(dest.getColumn() == 1);
    }
    SECTION("S"){
        Coordinates dest = src.move(S);
        REQUIRE(dest.getLine() == -1);
        REQUIRE(dest.getColumn() == 0);
    }
    SECTION("SO"){
        Coordinates dest = src.move(SO);
        REQUIRE(dest.getLine() == -1);
        REQUIRE(dest.getColumn() == -1);
    }
    SECTION("O"){
        Coordinates dest = src.move(O);
        REQUIRE(dest.getLine() == 0);
        REQUIRE(dest.getColumn() == -1);
    }
    SECTION("NO"){
        Coordinates dest = src.move(NO);
        REQUIRE(dest.getLine() == 1);
        REQUIRE(dest.getColumn() == -1);
    }

}

#endif
