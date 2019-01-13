#include "catch.h"
#include "homecell.h"
#include "exceptions.h"

TEST_CASE("Homecell constructor tests","[homecell]")
{
    homecell cell = homecell();

    REQUIRE(cell.getCurrentCard() == 0);
}

TEST_CASE("Homecell method addCard tests","[homecell]")
{
    homecell cell = homecell();

    REQUIRE_THROWS_AS(cell.addCard(card(spades,king)),invalid_move);

    cell.addCard(card(spades,ace));
    REQUIRE(cell.top().getSuit() == spades);
    REQUIRE(cell.top().getFace() == ace);

    REQUIRE_THROWS_AS(cell.addCard(card(spades,king)),invalid_move);

    cell.addCard(card(spades,two));
    REQUIRE(cell.top().getSuit() == spades);
    REQUIRE(cell.top().getFace() == two);
}

TEST_CASE("Homecell method removeCard tests","[homecell]")
{
    homecell cell = homecell();

    cell.addCard(card(spades,ace));
    cell.addCard(card(spades,two));
    cell.removeCard();
    REQUIRE(cell.size() == 1);
    cell.removeCard();
    REQUIRE(cell.size() == 0);
    REQUIRE_THROWS_AS(cell.removeCard(), outside_bounds);
}

TEST_CASE("Homecell method getCurrentCard tests","[homecell]")
{
    homecell cell = homecell();
    REQUIRE(cell.getCurrentCard() == 0);
    cell.addCard(card(spades,ace));
    REQUIRE(cell.getCurrentCard() == 1);
    cell.addCard(card(spades,two));
    REQUIRE(cell.getCurrentCard() == 2);
}

TEST_CASE("Homecell method size tests","[homecell]")
{
    homecell cell = homecell();
    REQUIRE(cell.size() == 0);
    cell.addCard(card(spades,ace));
    REQUIRE(cell.size() == 1);
    cell.addCard(card(spades,two));
    REQUIRE(cell.size() == 2);
}

TEST_CASE("Homecell method top tests","[homecell]")
{
    homecell cell = homecell();

    REQUIRE_THROWS_AS(cell.top(), outside_bounds);
    cell.addCard(card(spades,ace));
    REQUIRE(cell.top().getSuit() == spades);
    REQUIRE(cell.top().getFace() == ace);
    cell.addCard(card(spades,two));
    REQUIRE(cell.top().getSuit() == spades);
    REQUIRE(cell.top().getFace() == two);
}
