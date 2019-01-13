#include "deck.h"
#include "catch.h"
#include "exceptions.h"

TEST_CASE("Deck constructor tests", "[deck]")
{
    deck d1 = deck();

    REQUIRE(d1.getCard(0).getSuit() == spades);
    REQUIRE(d1.getCard(0).getFace() == ace);
    REQUIRE(d1.getCard(1).getSuit() == spades);
    REQUIRE(d1.getCard(1).getFace() == two);
    REQUIRE(d1.getCard(2).getSuit() == spades);
    REQUIRE(d1.getCard(2).getFace() == three);
    REQUIRE(d1.getCard(3).getSuit() == spades);
    REQUIRE(d1.getCard(3).getFace() == four);
    REQUIRE(d1.getCard(4).getSuit() == spades);
    REQUIRE(d1.getCard(4).getFace() == five);
}

TEST_CASE("Deck method shuffle tests", "[deck]")
{
    int count1 = 0,
        count2 = 0,
        count3 = 0,
        count4 = 0,
        count5 = 0;

    deck d1 = deck(),
         d2 = deck(),
         d3 = deck(),
         d4 = deck(),
         d5 = deck(),
         d6 = deck();

    d2.shuffle();
    d3.shuffle();
    d4.shuffle();
    d5.shuffle();
    d6.shuffle();

    for (int i = 0; i < CARDS; i++)
    {
        if (d2.getCard(i).getFace() == d1.getCard(i).getFace() && d2.getCard(i).getSuit() == d1.getCard(i).getSuit())
            count1++;

        if (d3.getCard(i).getFace() == d1.getCard(i).getFace() && d3.getCard(i).getSuit() == d1.getCard(i).getSuit())
            count2++;

        if (d4.getCard(i).getFace() == d1.getCard(i).getFace() && d4.getCard(i).getSuit() == d1.getCard(i).getSuit())
            count3++;

        if (d5.getCard(i).getFace() == d1.getCard(i).getFace() && d5.getCard(i).getSuit() == d1.getCard(i).getSuit())
            count4++;

        if (d6.getCard(i).getFace() == d1.getCard(i).getFace() && d6.getCard(i).getSuit() == d1.getCard(i).getSuit())
            count5++;
    }

    REQUIRE(count1 < CARDS);
    REQUIRE(count2 < CARDS);
    REQUIRE(count3 < CARDS);
    REQUIRE(count4 < CARDS);
    REQUIRE(count5 < CARDS);
}

TEST_CASE("Deck method getCard tests", "[deck]")
{
    deck d1 = deck();

    REQUIRE(d1.getCard(0).getSuit() == spades);
    REQUIRE(d1.getCard(0).getFace() == ace);
    REQUIRE(d1.getCard(1).getSuit() == spades);
    REQUIRE(d1.getCard(1).getFace() == two);
    REQUIRE(d1.getCard(2).getSuit() == spades);
    REQUIRE(d1.getCard(2).getFace() == three);
    REQUIRE(d1.getCard(3).getSuit() == spades);
    REQUIRE(d1.getCard(3).getFace() == four);
    REQUIRE(d1.getCard(4).getSuit() == spades);
    REQUIRE(d1.getCard(4).getFace() == five);

    REQUIRE_THROWS_AS(d1.getCard(-1),outside_bounds);
    REQUIRE_THROWS_AS(d1.getCard(CARDS),outside_bounds);
    REQUIRE_THROWS_AS(d1.getCard(-10000),outside_bounds);
    REQUIRE_THROWS_AS(d1.getCard(10000),outside_bounds);
}
