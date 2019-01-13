#include "homecell.h"
#include "exceptions.h"
#include <iostream>

homecell::homecell()
{
    currentCard = 0;
}

bool homecell::isValid(card c)
{
    if (currentCard == c.getFace())
    {
        if (currentCard == 0)
        {
            return true;
        }
        else if (h.back().getSuit() == c.getSuit())
        {
            return true;
        }
    }
    return false;
}

void homecell::addCard(card c)
{
    try
    {
        if (isValid(c))
        {
            currentCard++;
            h.push_back(c);
        }
        else
        {
            throw invalid_move();
        }
    }
    catch (std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}

void homecell::removeCard()
{
    try
    {
        if (size() == 0)
            throw outside_bounds();
        h.pop_back();
    }
    catch(std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}

int homecell::getCurrentCard()
{
    return currentCard;
}

int homecell::size()
{
    return h.size();
}

card homecell::top()
{
    try
    {
        if (size() == 0)
            throw outside_bounds();
        return h.back();
    }
    catch(std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}
