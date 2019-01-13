/**
    \file deck.h
    \author Lucas Zacharewicz
    \brief Defines deck class
    \date 6/4/2018
 */
#ifndef DECK_H
#define DECK_H

#include "card.h"
#include "constants.h"
#include <vector>
class deck
{
    private:
        std::vector<card> d;
        void swap(int i, int j);
    public:
        /**
            \brief Constructor for deck
            \details Assignment consists of itterating through the suit and
             face to populate the deck array with valid cards.
         */
        deck();

        /**
            \brief Shuffles the deck
            \details Implements Knuth shuffle
         */
        void shuffle();

        /**
            \brief gets the card at a given index in the deck
            \param i index of the card
            \throw out of bounds exception
            \return Card at index i in the deck
         */
        card getCard(int i);
};

#endif
