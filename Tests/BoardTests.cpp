#include "Libraries/catch.hpp" // has to be imported in every test file
#include "Model/Board.h"
#include "Util/GameException.h"

void checkBoardCstr(Board & b, unsigned nbLines, unsigned nbCols, unsigned nbBombs){
    REQUIRE(nbLines == b.getNbLines());
    REQUIRE(nbCols == b.getNbColumns());
    REQUIRE(nbBombs == b.getNbBombs());

    const Case * c;
    for(unsigned line = 0; line < nbLines ; line++){
        for(unsigned col = 0; col < nbCols; col++){
            c = b.getCase(Coordinates(line, col));
            REQUIRE(c->getState() == dft);
            REQUIRE(c->getNbNearBombs() == 0);
            REQUIRE(!c->isBomb());
        }
    }
}

void checkNbBombs(Board & b){
    const Case * c;
    unsigned nbBombs {0};
    for(unsigned line = 0; line < b.getNbLines() ; line++){
        for(unsigned col = 0; col < b.getNbColumns(); col++){
            c = b.getCase(Coordinates(line, col));
            if(c->isBomb()){
                nbBombs++;
            }
        }
    }
    REQUIRE(nbBombs == b.getNbBombs());
}

TEST_CASE("Creation board"){
    unsigned nbLines , nbColumns, nbBombs;

    SECTION("Dft constr"){
        Board b {};
        nbLines = 10;
        nbColumns = 10;
        nbBombs = 10;
        checkBoardCstr(b, nbLines, nbColumns, nbBombs);
    }
    SECTION("Constr with nbLines and nbCols"){
        nbLines = 5;
        nbColumns = 5;
        nbBombs = nbLines*nbColumns*0.1;
        Board b = Board(nbLines, nbColumns);
        checkBoardCstr(b, nbLines, nbColumns, nbBombs);
    }
    SECTION("Constr with nbLines, nbCols and perc"){
        nbLines = 5;
        nbColumns = 5;
        double perc = 0.2;
        nbBombs = nbLines*nbColumns*perc;
        Board b = Board(nbLines, nbColumns, perc);
        checkBoardCstr(b, nbLines, nbColumns, nbBombs);
    }
    SECTION("Constr with nbLines, nbCols and nbBombs"){
        nbLines = 5;
        nbColumns = 5;
        nbBombs = 10;
        Board b = Board(nbLines, nbColumns, nbBombs);
        checkBoardCstr(b, nbLines, nbColumns, nbBombs);
    }
}

TEST_CASE("Mark and unmark coord"){
    Board b{};
    Coordinates pos {0, 0};
    b.mark(pos);
    const Case * c {b.getCase(pos)};
    REQUIRE(c->getState() == marked);
    b.mark(pos);
    c = b.getCase(pos);
    REQUIRE(c->getState() == dft);
    b.mark(pos);
    c= b.getCase(pos);
    REQUIRE(c->getState() == marked);
}

TEST_CASE("isOnBoard"){
    Board b{};
    REQUIRE_THROWS_AS(b.mark({-1, 0}), GameException);
    REQUIRE_NOTHROW(b.mark({0, 0}));
    //TODO check if can put nbLines and nbCols as int over unsigned
    int line {static_cast<int>(b.getNbLines())}, col {static_cast<int>(b.getNbColumns())};
    REQUIRE_THROWS_AS(b.mark({line, col}), GameException);
    REQUIRE_NOTHROW(b.mark({line-1, col-1}));
}

TEST_CASE("generateBombs right amount "){
    unsigned nbLines, nbCols, nbBombs;
    SECTION("default values"){
        nbLines = 5;
        nbCols = 5;
        nbBombs = 5;
    }
    SECTION("other values"){
        nbLines = 5;
        nbCols = 5;
        nbBombs = 10;
    }
    //TODO with percentage (how many at end?)
    Board b {nbLines, nbCols, nbBombs};
}

//TODO test restart method
//TODO test operator = works even if did it in game




