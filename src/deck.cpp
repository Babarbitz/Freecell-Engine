#include "deck.h"
#include "exceptions.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

deck::deck()
{
    suit s[] = {spades, clubs, hearts, diamonds};
    face f[] = {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};

    for (int i = 0; i < SUITS; i++)
    {
        for (int j = 0; j < FACES; j++)
        {
            d.push_back(card(s[i],f[j]));
        }
    }
}

void deck::shuffle()
{
    srand(time(NULL));
    for (int i = CARDS-1; i >= 1; i--)
    {
        int j = rand() % (i+1);
        swap(i,j);
    }
}

card deck::getCard(int i)
{
    try
    {
        if (i < 0 || i >= CARDS)
        {
            throw outside_bounds();
        }
        return d[i];
    }
    catch(std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}

void deck::swap(int i, int j)
{
    card temp = d[i];
    d[i] = d[j];
    d[j] = temp;
}
