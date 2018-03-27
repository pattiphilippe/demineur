#include "Libraries/catch.hpp" // has to be imported in every test file
#include "Model/Case.h"
#include "Util/GameException.h"

TEST_CASE("Creation and init state"){
    Case c {};
    SECTION("Simple creation"){
    }
    SECTION("Creation and init method"){
        c.init();
    }
    SECTION("init after changes"){
        c.addNearBomb();
        c.setBomb();
        c.setState(marked);
        c.init();
    }
    REQUIRE(c.getNbNearBombs() == 0);
    REQUIRE(!c.isBomb());
    REQUIRE(c.getState() == dft);
}

TEST_CASE("Modifying bomb"){
    Case c {};
    c.setBomb();
    REQUIRE(c.isBomb());
}

TEST_CASE("Modifying state") {
    Case c {};
    REQUIRE(c.getState() == dft);
    CaseState state;
    SECTION("state dft"){
        state = dft;
    }
    SECTION("state marked"){
        state = marked;
    }
    SECTION("state revealed"){
        state = revealed;
    }
    c.setState(state);
    REQUIRE(c.getState() == state);
    c.init();
    REQUIRE(c.getState() == dft);
}

TEST_CASE("Modifying nbNearBombs"){
    Case c {};
    REQUIRE(c.getNbNearBombs() == 0);
    c.addNearBomb();
    REQUIRE(c.getNbNearBombs() == 1);
    for(unsigned i = 2; i < 10; i ++){
        c.addNearBomb();
    }
    REQUIRE(c.getNbNearBombs() == 9);
    c.init();
    REQUIRE(c.getNbNearBombs() == 0);
}

TEST_CASE("CasePublic creation"){
    Case c {};
    CasePublic cp{&c};
    SECTION("state dft"){
        REQUIRE(c.getState() == dft);
        REQUIRE(cp.getState() == dft);
        REQUIRE_THROWS_AS(cp.getNbNearBombs(), GameException);
        REQUIRE_THROWS_AS(cp.isBomb(), GameException);
    }
    SECTION("state marked"){
        c.setState(marked);
        REQUIRE(cp.getState() == marked);
        REQUIRE_THROWS_AS(cp.getNbNearBombs(), GameException);
        REQUIRE_THROWS_AS(cp.isBomb(), GameException);
    }
    SECTION("state revealed"){
        c.setState(revealed);
        REQUIRE(cp.getState() == revealed);
        REQUIRE(cp.getNbNearBombs() == 0);
        REQUIRE(!cp.isBomb());
    }
}

TEST_CASE("CasePublic after changes"){
    Case c{};
    CasePublic cp{&c};
    c.setState(revealed);
    c.addNearBomb();
    c.setBomb();
    REQUIRE(cp.getState() == revealed);
    REQUIRE(cp.getNbNearBombs() == 1);
    REQUIRE(cp.isBomb());
    c.init();
    REQUIRE(cp.getState() == dft);
    REQUIRE_THROWS_AS(cp.getNbNearBombs(), GameException);
    REQUIRE_THROWS_AS(cp.isBomb(), GameException);
}








