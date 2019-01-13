#include "card.h"
#include "catch.h"

TEST_CASE ("Card construtor tests","[card]")
{
    card c1(spades, ace),
         c2(clubs, two),
         c3(hearts, three),
         c4(diamonds, four);

    REQUIRE(c1.getSuit() == spades);
    REQUIRE(c1.getFace() == ace);
    REQUIRE(c1.getColour() == black);
    REQUIRE(c2.getSuit() == clubs);
    REQUIRE(c2.getFace() == two);
    REQUIRE(c2.getColour() == black);
    REQUIRE(c3.getSuit() == hearts);
    REQUIRE(c3.getFace() == three);
    REQUIRE(c3.getColour() == red);
    REQUIRE(c4.getSuit() == diamonds);
    REQUIRE(c4.getFace() == four);
    REQUIRE(c4.getColour() == red);
}

TEST_CASE("Card method getSuit tests","[card]")
{
    card c1(spades, ace),
         c2(clubs, ace),
         c3(hearts, ace),
         c4(diamonds, ace);

    REQUIRE(c1.getSuit() == spades);
    REQUIRE(c2.getSuit() == clubs);
    REQUIRE(c3.getSuit() == hearts);
    REQUIRE(c4.getSuit() == diamonds);
}

TEST_CASE ("Card method getFace tests","[card]")
{
    card c1(spades, ace),
         c2(spades, two),
         c3(spades, three),
         c4(spades, four);

    REQUIRE(c1.getFace() == ace);
    REQUIRE(c2.getFace() == two);
    REQUIRE(c3.getFace() == three);
    REQUIRE(c4.getFace() == four);
}

TEST_CASE("Card method getColour tests","[card]")
{
    card c1(spades, ace),
         c2(clubs, ace),
         c3(hearts, ace),
         c4(diamonds, ace);

    REQUIRE(c1.getColour() == black);
    REQUIRE(c2.getColour() == black);
    REQUIRE(c3.getColour() == red);
    REQUIRE(c4.getColour() == red);
}
