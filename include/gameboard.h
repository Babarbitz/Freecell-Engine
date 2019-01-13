/**
    \file gameboard.h
    \author Lucas Zacharewicz
    \brief Defines gameboard class
    \date 8/4/2018
 */
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "freecell.h"
#include "homecell.h"
#include "gamecell.h"
#include "deck.h"

class gameboard
{
    private:
        freecell fCells[FREECELLS];
        homecell hCells[HOMECELLS];
        gamecell gCells[GAMECELLS];
    public:
        /**
            \brief Adds card from a deck to the game board
         */
        void populateBoard(deck d);
        /**
            \brief Checks for the win condition
            \return True if the game is won, false if that is not the case
         */
        bool checkForWin();
        /**
            \brief Checks if there is any valid move that can be made
            \return True if there is, false if not
         */
        bool checkForValidMove();
        ///\brief Moves a card from a gamecell to another gamecell
        void gameToGame(int i, int j);
        ///\brief Moves a card from a gamecell to a Freecell
        void gameToFree(int i, int j);
        ///\brief Moves a card from a gamecell to a homecell
        void gameToHome(int i, int j);
        ///\brief Moves a card from a homecell to a freecell
        void homeToFree(int i, int j);
        ///\brief Moves a card from a homecell to a gamecell
        void homeToGame(int i, int j);
        ///\brief Moves a card from a freecell to a homecell
        void freeToGame(int i, int j);
        ///\brief Moves a card from a freecell to a homecell
        void freeToHome(int i, int j);

        // These are not nesicary for anything besides testing
        ///\brief Getter for the ith freecell in fCells
        freecell getFCells(int i);
        ///\brief Getter for the ith homeCell in hCells
        homecell getHCells(int i);
        ///\brief Getter for the ith gameCell in gCells
        gamecell getGCells(int i);
        ///\brief Adds card directly to ith freecell
        void addFCells(int i, card c);
        ///\brief Adds card directly to ith homecell
        void addHCells(int i, card c);
        ///\brief Adds card directly to ith gameCell
        void addGCells(int i, card c);
};

#endif
