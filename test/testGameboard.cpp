#include "catch.h"
#include "gameboard.h"
#include "deck.h"
#include "exceptions.h"
#include <iostream>

TEST_CASE("Gameboard method populateBoard test","[gameboard]")
{
    gameboard board;
    deck d = deck();

    board.populateBoard(d);

    REQUIRE(board.getGCells(0).top().getSuit() == diamonds);
    REQUIRE(board.getGCells(0).top().getFace() == ten);
    REQUIRE(board.getGCells(1).top().getSuit() == diamonds);
    REQUIRE(board.getGCells(1).top().getFace() == jack);
    REQUIRE(board.getGCells(2).top().getSuit() == diamonds);
    REQUIRE(board.getGCells(2).top().getFace() == queen);
    REQUIRE(board.getGCells(3).top().getSuit() == diamonds);
    REQUIRE(board.getGCells(3).top().getFace() == king);
}

TEST_CASE("Gameboard method checkForWin test","[gameboard]")
{
    gameboard board1, board2;
    deck d = deck();
    face f[] = {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};

    for (int i = 0; i < FACES; i++)
    {
        board1.addHCells(0,card(spades,f[i]));
        board1.addHCells(1,card(clubs,f[i]));
        board1.addHCells(2,card(hearts,f[i]));
        board1.addHCells(3,card(diamonds,f[i]));
    }
    REQUIRE(board1.checkForWin() == true);
    board2.populateBoard(d);
    REQUIRE(board2.checkForWin() == false);
}

TEST_CASE("Gameboard method checkForValidMove test","[gameboard]")
{
    gameboard board;
    deck d = deck();
    board.populateBoard(d);

    REQUIRE(board.checkForValidMove() == true);
    board.gameToFree(0,0);
    REQUIRE(board.checkForValidMove() == true);
    board.gameToFree(1,1);
    REQUIRE(board.checkForValidMove() == true);
    board.gameToFree(2,2);
    REQUIRE(board.checkForValidMove() == true);
    board.gameToFree(3,3);
    REQUIRE(board.checkForValidMove() == false);
}

TEST_CASE("Gameboard method gameToGame test","[gameboard]")
{
    gameboard board;

    board.addGCells(0,card(spades,two));
    board.addGCells(1,card(hearts,ace));

    REQUIRE_THROWS_AS(board.gameToGame(-1,0), invalid_move);
    REQUIRE_THROWS_AS(board.gameToGame(9,0), invalid_move);
    REQUIRE_THROWS_AS(board.gameToGame(0,-1), invalid_move);
    REQUIRE_THROWS_AS(board.gameToGame(0,9), invalid_move);
    board.gameToGame(1,0);
    REQUIRE(board.getGCells(0).top().getFace() == ace);
}

TEST_CASE("Gameboard method gameToFree test","[gameboard]")
{
    gameboard board;

    board.addGCells(0,card(spades,two));


    REQUIRE_THROWS_AS(board.gameToFree(-1,0), invalid_move);
    REQUIRE_THROWS_AS(board.gameToFree(9,0), invalid_move);
    REQUIRE_THROWS_AS(board.gameToFree(0,-1), invalid_move);
    REQUIRE_THROWS_AS(board.gameToFree(0,9), invalid_move);
    board.gameToFree(0,0);
    REQUIRE(board.getFCells(0).getC().getFace() == two);
}

TEST_CASE("Gameboard method gameToHome test","[gameboard]")
{
    gameboard board;

    board.addGCells(0,card(spades,ace));


    REQUIRE_THROWS_AS(board.gameToHome(-1,0), invalid_move);
    REQUIRE_THROWS_AS(board.gameToHome(9,0), invalid_move);
    REQUIRE_THROWS_AS(board.gameToHome(0,-1), invalid_move);
    REQUIRE_THROWS_AS(board.gameToHome(0,9), invalid_move);
    board.gameToHome(0,0);
    REQUIRE(board.getHCells(0).top().getFace() == ace);
}

TEST_CASE("Gameboard method homeToFree test","[gameboard]")
{
    gameboard board;

    board.addHCells(0,card(spades,ace));

    REQUIRE_THROWS_AS(board.homeToFree(-1,0), invalid_move);
    REQUIRE_THROWS_AS(board.homeToFree(9,0), invalid_move);
    REQUIRE_THROWS_AS(board.homeToFree(0,-1), invalid_move);
    REQUIRE_THROWS_AS(board.homeToFree(0,9), invalid_move);
    board.homeToFree(0,0);
    REQUIRE(board.getFCells(0).getC().getFace() == ace);
}

TEST_CASE("Gameboard method homeToGame test","[gameboard]")
{
    gameboard board;

    board.addHCells(0,card(spades,ace));

    REQUIRE_THROWS_AS(board.homeToGame(-1,0), invalid_move);
    REQUIRE_THROWS_AS(board.homeToGame(9,0), invalid_move);
    REQUIRE_THROWS_AS(board.homeToGame(0,-1), invalid_move);
    REQUIRE_THROWS_AS(board.homeToGame(0,9), invalid_move);
    board.homeToGame(0,0);
    REQUIRE(board.getGCells(0).top().getFace() == ace);
}

TEST_CASE("Gameboard method freeToGame test","[gameboard]")
{
    gameboard board;

    board.addFCells(0,card(spades,ace));

    REQUIRE_THROWS_AS(board.freeToGame(-1,0), invalid_move);
    REQUIRE_THROWS_AS(board.freeToGame(9,0), invalid_move);
    REQUIRE_THROWS_AS(board.freeToGame(0,-1), invalid_move);
    REQUIRE_THROWS_AS(board.freeToGame(0,9), invalid_move);
    board.freeToGame(0,0);
    REQUIRE(board.getGCells(0).top().getFace() == ace);
}

TEST_CASE("Gameboard method freeToHome test","[gameboard]")
{
    gameboard board;

    board.addFCells(0,card(spades,ace));

    REQUIRE_THROWS_AS(board.freeToHome(-1,0), invalid_move);
    REQUIRE_THROWS_AS(board.freeToHome(9,0), invalid_move);
    REQUIRE_THROWS_AS(board.freeToHome(0,-1), invalid_move);
    REQUIRE_THROWS_AS(board.freeToHome(0,9), invalid_move);
    board.freeToHome(0,0);
    REQUIRE(board.getHCells(0).top().getFace() == ace);
}
