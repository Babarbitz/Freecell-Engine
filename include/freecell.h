/**
    \file freecell.h
    \author Lucas Zacharewicz
    \brief Defines freecell class
    \date 7/4/2018
 */
 #ifndef FREECELL_H
 #define FREECELL_H

#include "card.h"
#include <vector>

class freecell
{
    private:
        std::vector<card> c;
    public:
        /**
            \brief Defines if the freecell is holding a card
            \return True if the cell is ocupied false if not
         */
        bool isOcupied();

        /**
            \brief Getter for the card held in the freecell
            \return The card in the free cell
         */
        card getC();

        /**
            \brief Setter for the card
            \param cs The card to put in the cell
         */
        void setC(card cs);

        /**
            \brief Clears the freecell
         */
        void clear();
        /**
            \brief Sees if there is a valid move
            \return If the move would be valid
         */
        bool isValid();
};

 #endif
