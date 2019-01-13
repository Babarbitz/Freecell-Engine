#include "freecell.h"
#include "exceptions.h"
#include <iostream>

bool freecell::isOcupied()
{
    if (c.size() == 1)
        return true;
    return false;
}

bool freecell::isValid()
{
    if (c.size() == 1)
        return false;
    return true;
}

card freecell::getC()
{
    return c[0];
}

void freecell::setC(card cs)
{
    try
    {
        if (!isValid())
            throw invalid_move();
        c.push_back(cs);
    }
    catch(std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}

void freecell::clear()
{
    try
    {
        if (!isOcupied())
            throw outside_bounds();
        c.pop_back();
    }
    catch(std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}
