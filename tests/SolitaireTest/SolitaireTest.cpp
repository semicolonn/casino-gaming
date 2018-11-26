#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../../components/Solitaire/Solitaire.hpp"


TEST_CASE("Conversion test"){

  Solitaire patience = Solitaire();

  REQUIRE(patience.symbolToValue("A") == 1);
  REQUIRE(patience.symbolToValue("J") == 11);
  REQUIRE(patience.symbolToValue("Q") == 12);
  REQUIRE(patience.symbolToValue("K") == 13);
}

TEST_CASE("Positive tests"){

  Solitaire patience = Solitaire();

  REQUIRE(patience.differentColor(CLUB, HEART) == true);
  REQUIRE(patience.lessThan("10", "11") == 1);
}

TEST_CASE("Negative tests"){

    Solitaire patience = Solitaire();

    REQUIRE(patience.differentColor(HEART, DIAMOND) == false);
    REQUIRE(patience.lessThan("10", "9") == 0);
}
