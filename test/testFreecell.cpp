#include "catch.h"
#include "freecell.h"
#include "exceptions.h"

TEST_CASE("Freecell constructor tests", "[freecell]")
{
    freecell cell = freecell();
    REQUIRE(cell.isOcupied() == false);
}

TEST_CASE("Freecell method isOcupied tests", "[freecell]")
{
    freecell cell = freecell();
    REQUIRE(cell.isOcupied() == false);
    cell.setC(card(spades,ace));
    REQUIRE(cell.isOcupied() == true);
}

TEST_CASE("Freecell method getC tests", "[freecell]")
{
    freecell cell = freecell();
    cell.setC(card(spades,ace));
    REQUIRE(cell.getC().getSuit() == spades);
    REQUIRE(cell.getC().getFace() == ace);
    REQUIRE_THROWS_AS(cell.setC(card(spades,ace)), invalid_move);
}

TEST_CASE("Freecell method setC tests", "[freecell]")
{
    freecell cell = freecell();
    cell.setC(card(spades,ace));
    REQUIRE(cell.getC().getSuit() == spades);
    REQUIRE(cell.getC().getFace() == ace);
}

TEST_CASE("Freecell method clear tests", "[freecell]")
{
    freecell cell = freecell();
    REQUIRE(cell.isOcupied() == false);
    cell.setC(card(spades,ace));
    REQUIRE(cell.isOcupied() == true);
    cell.clear();
    REQUIRE(cell.isOcupied() == false);
    REQUIRE_THROWS_AS(cell.clear(), outside_bounds);
}
