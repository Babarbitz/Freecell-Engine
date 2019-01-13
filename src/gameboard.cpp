#include "gameboard.h"
#include "exceptions.h"
#include <iostream>

void gameboard::populateBoard(deck d)
{
    for (int i = 0; i < CARDS; i++)
    {
        gCells[i % GAMECELLS].forceAdd(d.getCard(i));
    }
}

bool gameboard::checkForWin()
{
    if (getHCells(0).size() == FACES && getHCells(1).size() == FACES &&
        getHCells(2).size() == FACES && getHCells(3).size() == FACES)
        return true;
    return false;
}

bool gameboard::checkForValidMove()
{
    for (int i = 0; i < GAMECELLS; i++)
    {
        for (int j = 0; j < GAMECELLS; j++)
        {
            if (gCells[j].size() != 0)
                if (gCells[i].isValid(gCells[j].top()))
                    return true;
        }

        for (int k = 0; k < HOMECELLS; k++)
        {
            if (hCells[k].size() != 0)
                if (gCells[i].isValid(hCells[k].top()))
                    return true;
        }

        for (int h = 0; h < FREECELLS; h++)
        {
            if (fCells[h].isOcupied())
                if (gCells[i].isValid(fCells[h].getC()))
                    return true;
        }
    }

    for (int i = 0; i < HOMECELLS; i++)
    {
        for (int j = 0; j < GAMECELLS; j++)
        {
            if (gCells[j].size() != 0)
                if (hCells[i].isValid(gCells[j].top()))
                    return true;
        }

        for (int k = 0; k < FREECELLS; k++)
        {
            if (fCells[k].isOcupied())
                if (hCells[i].isValid(fCells[k].getC()))
                    return true;
        }
    }

    for (int i = 0; i < FREECELLS; i++)
    {
        if (fCells[i].isValid())
            return true;
    }

    return false;
}

void gameboard::gameToGame(int i, int j)
{
    try
    {
        if (i < 0 || GAMECELLS <= i)
            throw invalid_move();

        if (j < 0 || GAMECELLS <= j)
            throw invalid_move();

        card c = gCells[i].top();

        if (gCells[j].isValid(c))
        {
            gCells[i].removeCard();
            gCells[j].addCard(c);
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

void gameboard::gameToFree(int i, int j)
{
    try
    {
        if (i < 0 || GAMECELLS <= i)
            throw invalid_move();

        if (j < 0 || FREECELLS <= j)
            throw invalid_move();

        card c = gCells[i].top();

        if (fCells[j].isValid())
        {
            gCells[i].removeCard();
            fCells[j].setC(c);
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

void gameboard::gameToHome(int i, int j)
{
    try
    {
        if (i < 0 || GAMECELLS <= i)
            throw invalid_move();

        if (j < 0 || HOMECELLS <= j)
            throw invalid_move();

        card c = gCells[i].top();

        if (hCells[j].isValid(c))
        {
            gCells[i].removeCard();
            hCells[j].addCard(c);
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

void gameboard::homeToFree(int i, int j)
{
    try
    {
        if (i < 0 || HOMECELLS <= i)
            throw invalid_move();

        if (j < 0 || FREECELLS <= j)
            throw invalid_move();

        card c = hCells[i].top();

        if (fCells[j].isValid())
        {
            hCells[i].removeCard();
            fCells[j].setC(c);
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

void gameboard::homeToGame(int i, int j)
{
    try
    {
        if (i < 0 || HOMECELLS <= i)
            throw invalid_move();

        if (j < 0 || GAMECELLS <= j)
            throw invalid_move();

        card c = hCells[i].top();

        if (gCells[j].isValid(c))
        {
            hCells[i].removeCard();
            gCells[j].addCard(c);
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

void gameboard::freeToGame(int i, int j)
{
    try
    {
        if (i < 0 || FREECELLS <= i)
            throw invalid_move();

        if (j < 0 || GAMECELLS <= j)
            throw invalid_move();

        card c = fCells[i].getC();

        if (gCells[j].isValid(c))
        {
            fCells[i].clear();
            gCells[j].addCard(c);
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

void gameboard::freeToHome(int i, int j)
{
    try
    {
        if (i < 0 || FREECELLS <= i)
            throw invalid_move();

        if (j < 0 || HOMECELLS <= j)
            throw invalid_move();

        card c = fCells[i].getC();

        if (hCells[j].isValid(c))
        {
            fCells[i].clear();
            hCells[j].addCard(c);
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

freecell gameboard::getFCells(int i)
{
    try
    {
        if (i < 0 || FREECELLS <= i)
            throw outside_bounds();
        return fCells[i];
    }
    catch (std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}

homecell gameboard::getHCells(int i)
{
    try
    {
        if (i < 0 || HOMECELLS <= i)
            throw outside_bounds();
        return hCells[i];
    }
    catch (std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}

gamecell gameboard::getGCells(int i)
{
    try
    {
        if (i < 0 || GAMECELLS <= i)
            throw outside_bounds();
        return gCells[i];
    }
    catch (std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}

void gameboard::addFCells(int i, card c)
{
    try
    {
        if (i < 0 || FREECELLS <= i)
            throw outside_bounds();
        fCells[i].setC(c);
    }
    catch (std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}

void gameboard::addHCells(int i, card c)
{
    try
    {
        if (i < 0 || HOMECELLS <= i)
            throw outside_bounds();
        hCells[i].addCard(c);
    }
    catch (std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}

void gameboard::addGCells(int i, card c)
{
    try
    {
        if (i < 0 || GAMECELLS <= i)
            throw outside_bounds();
        gCells[i].addCard(c);
    }
    catch (std::exception* e)
    {
        std::cout << e->what() << std::endl;
    }
}
