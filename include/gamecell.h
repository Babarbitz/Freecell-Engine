/**
    \file gamecell.h
    \author Lucas Zacharewicz
    \brief Defines gamecell class
    \date 8/4/2018
 */
#ifndef GAMECELL_H
#define GAMECELL_H

#include <vector>
#include "card.h"

class gamecell
{
    private:
        std::vector<card> g;
    public:
        /**
            \brief Force adds a card to the end of the vector
            \param c The card to add to the end of the vector
         */
        void forceAdd(card c);
        /**
            \brief Adds a card to the end of the vector
            \param c The card to add to the end of the vector
            \throw invalid_move exception
         */
        void addCard(card c);
        /**
            \brief Removes the most recently added card from the vector
            \throw outside_bounds exception
         */
        void removeCard();
        /**
            \brief Gets the size of the vector
            \return The size of the vector
         */
        int size();
        /**
            \brief Gets the most recently added card in the vector
            \return The most recently added card in the vector
         */
        card top();
        /**
            \brief Sees if there is a valid move
            \param c The card to test the move for
            \return If the move would be valid
         */
        bool isValid(card c);
};

#endif
