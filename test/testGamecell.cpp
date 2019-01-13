#include "catch.h"
#include "gamecell.h"
#include "exceptions.h"

TEST_CASE("Gamecell constructor tests","[gamecell]")
{
    gamecell cell = gamecell();

    REQUIRE(cell.size() == 0);
}

TEST_CASE("Gamecell method forceAdd tests","[gamecell]")
{
    gamecell cell = gamecell();

    cell.forceAdd(card(spades,king));
    REQUIRE(cell.size() == 1);

    cell.forceAdd(card(spades, queen));
    REQUIRE(cell.size() == 2);

    cell.forceAdd(card(diamonds, five));
    REQUIRE(cell.size() == 3);
}

TEST_CASE("Gamecell method addCard tests","[gamecell]")
{
    gamecell cell = gamecell();

    cell.addCard(card(spades,king));
    REQUIRE(cell.size() == 1);

    REQUIRE_THROWS_AS(cell.addCard(card(spades,ace)),invalid_move);

    cell.addCard(card(diamonds, queen));
    REQUIRE(cell.size() == 2);
}

TEST_CASE("Gamecell method removeCard tests","[gamecell]")
{
    gamecell cell = gamecell();

    cell.addCard(card(spades,three));
    cell.addCard(card(diamonds,two));
    cell.removeCard();
    REQUIRE(cell.size() == 1);
    cell.removeCard();
    REQUIRE(cell.size() == 0);
    REQUIRE_THROWS_AS(cell.removeCard(), outside_bounds);
}

TEST_CASE("Gamecell method size tests","[gamecell]")
{
    gamecell cell = gamecell();
    REQUIRE(cell.size() == 0);
    cell.addCard(card(spades,three));
    REQUIRE(cell.size() == 1);
    cell.addCard(card(diamonds,two));
    REQUIRE(cell.size() == 2);
}

TEST_CASE("Gamecell method top tests","[gamecell]")
{
    gamecell cell = gamecell();

    REQUIRE_THROWS_AS(cell.top(), outside_bounds);
    cell.addCard(card(spades,three));
    REQUIRE(cell.top().getSuit() == spades);
    REQUIRE(cell.top().getFace() == three);
    cell.addCard(card(diamonds,two));
    REQUIRE(cell.top().getSuit() == diamonds);
    REQUIRE(cell.top().getFace() == two);
}
