#include "constants.h"
#include "gamecell.h"
#include "exceptions.h"
#include <iostream>

void gamecell::forceAdd(card c)
{
    g.push_back(c);
}

bool gamecell::isValid(card c)
{
    face f[] = {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};
    face expected;

    if (size() == 0)
        return true;

    for (int i = 0; i < FACES; i++)
    {
        if (f[i] == top().getFace())
        {
            if (i == 0)
                return false;
            expected = f[i-1];
        }
    }

    if (expected == c.getFace() && g.back().getColour() != c.getColour())
        return true;

    return false;
}

void gamecell::addCard(card c)
{
    try
    {
        if(isValid(c))
            g.push_back(c);
        else
            throw invalid_move();
    }
    catch (std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}

void gamecell::removeCard()
{
    try
    {
        if (size() == 0)
            throw outside_bounds();
        g.pop_back();
    }
    catch(std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}

int gamecell::size()
{
    return g.size();
}

card gamecell::top()
{
    try
    {
        if (size() == 0)
            throw outside_bounds();
        return g.back();
    }
    catch(std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}
