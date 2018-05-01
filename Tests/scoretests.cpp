#include "Scores/Score.h"
#include "Libraries/catch.hpp"

TEST_CASE("Operator < normal case"){
    Score s1 (10, "m");
    Score s2(11, "d");
    REQUIRE(s1 < s2);
}

TEST_CASE("Operator < 0 et 0"){
    Score s1 {};
    Score s2{};
    REQUIRE_FALSE(s1 < s2);
}

TEST_CASE("Operator < 0 et nb"){
    Score s1 (10, "m");
    Score s2{};
    REQUIRE(s1 < s2);
    REQUIRE_FALSE(s2 < s1);
}

