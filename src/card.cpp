#include "card.h"

card::card(suit x, face y)
{
    s = x;
    f = y;
    if (x == spades || x == clubs)
    {
        c = black;
    }
    else
    {
        c = red;
    }
}

suit card::getSuit()
{
    return s;
}

face card::getFace()
{
    return f;
}

colour card::getColour()
{
    return c;
}
