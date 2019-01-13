/**
    \file card.h
    \author Lucas Zacharewicz
    \brief Defines card class
    \date 5/4/2018
 */
#ifndef CARD_H
#define CARD_H

#include "types.h"

class card
{
    private:
        suit s;
        face f;
        colour c;
    public:

        /**
            \brief Constructor for card
            \details Colour is determined from the suit
            \param x Suit of the card
            \param y Face of the card
         */
        card(suit x, face y);

        /**
            \breif Getter for the card's suit
            \return The value of the suit
         */
        suit getSuit();

        /**
            \breif Getter for the card's face
            \return The value of the face
         */
        face getFace();

        /**
            \breif Getter for the card's colour
            \return The value of the colour
         */
        colour getColour();
};

#endif
