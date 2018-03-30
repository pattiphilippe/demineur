#include "Tests/maintests.h"

#if RUN_TESTS
#include "Libraries/catch.hpp" // has to be imported in every test file
#include "Model/Board.h"
#include "Util/GameException.h"

#include <iostream>

using namespace std;

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

//TODO add constr with check for default params
TEST_CASE("Creation board"){
    int nbLines , nbColumns;
    unsigned nbBombs;
    Board b;

    SECTION("Dft constr"){
        b = Board();
        nbLines = 10;
        nbColumns = 10;
        nbBombs = 10;
    }
    SECTION("Constr with nbLines and nbCols"){
        nbLines = 5;
        nbColumns = 5;
        nbBombs = nbLines*nbColumns*0.1;
        b = Board(nbLines, nbColumns);
    }
    SECTION("Constr with nbLines, nbCols and perc"){
        nbLines = 5;
        nbColumns = 5;
        double perc = 0.2;
        nbBombs = static_cast<unsigned>(nbLines*nbColumns*perc);
        b = Board(nbLines, nbColumns, perc);
    }
    SECTION("Constr with nbLines, nbCols and nbBombs"){
        nbLines = 5;
        nbColumns = 5;
        nbBombs = 10;
        b = Board(nbLines, nbColumns, nbBombs);
    }
    checkBoardCstr(b, nbLines, nbColumns, nbBombs);
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
    int line {b.getNbLines()}, col {b.getNbColumns()};
    REQUIRE_THROWS_AS(b.mark({line, col}), GameException);
    REQUIRE_NOTHROW(b.mark({line-1, col-1}));
}

TEST_CASE("generateBombs right amount "){
    unsigned nbLines, nbCols, nbBombs;
    double perc {0};
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
    SECTION("with perc"){
        nbLines = 5;
        nbCols = 5;
        perc = 0.5;
        nbBombs = static_cast<unsigned>(nbLines * nbCols * perc);
    }
    Board b;
    if(perc == 0){
        b = Board (nbLines, nbCols, nbBombs);
    } else {
        b = Board (nbLines, nbCols, perc);
    }
    const Case * c;
    unsigned nbBombsOnBoard {0};
    for(int line = 0; line < b.getNbLines() ; line++){
        for(int col = 0; col < b.getNbColumns(); col++){
            c = b.getCase(Coordinates(line, col));
            if(c->isBomb()){
                nbBombsOnBoard++;
            }
        }
    }
    REQUIRE(nbBombs == b.getNbBombs());
}

TEST_CASE("nbNearBombs"){
    Board b {};
    b.setFirstAction(false);
    b.setBomb({1, 1});
    REQUIRE(b.getCase({0, 0})->getNbNearBombs() == 1);
}

TEST_CASE("Board Public"){
    Board b{};
    BoardPublic bp{b};

    REQUIRE(b.getNbBombs() == bp.getNbBombs());
    REQUIRE(b.getNbColumns() == bp.getNbColumns());
    REQUIRE(b.getNbLines() == bp.getNbLines());

    const Case * c;
    const CasePublic * cp;
    for(int line = 0; line < bp.getNbLines(); line ++){
        for(int col = 0; col < bp.getNbColumns(); col++){
            c = b.getCase({line, col});
            cp = bp.getCase({line, col});
            REQUIRE(c->getState() == cp->getState());
        }
    }

    b.mark({0, 0});
    c = b.getCase({0, 0});
    cp = bp.getCase({0, 0});
    REQUIRE(c->getState() == marked);
    REQUIRE(cp->getState() == marked);
}


//TODO test restart method
//TODO test operator = works even if did it in game

#endif


