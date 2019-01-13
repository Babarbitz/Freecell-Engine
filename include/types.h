/**
    \file types.h
    \author Lucas Zacharewicz
    \brief Defines types for the rest of the program
    \date 6/4/2018
 */
#ifndef TYPES_H
#define TYPES_H

/// Defines the new type suit as all possible suits a card can have
typedef enum {spades, clubs, hearts, diamonds} suit;

/// Defines the new type face as all possible face values a card can have
typedef enum {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king} face;

/// Defines the new type colour as all the possible colours a card can have
typedef enum {red,black} colour;

#endif
