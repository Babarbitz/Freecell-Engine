/**
    \file homecell.h
    \author Lucas Zacharewicz
    \brief Defines homecell class
    \date 8/4/2018
 */
#ifndef HOMECELL_H
#define HOMECELL_H

#include <vector>
#include "card.h"

class homecell
{
    private:
        std::vector<card> h;
        int currentCard;
        bool isValid();
    public:
        /**
            \brief Default constructor for homecell
            \details Sets currentCard to 0
         */
        homecell();
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
            \brief Gets the value of currentCard
            \return The value of currentCard
         */
        int getCurrentCard();
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
