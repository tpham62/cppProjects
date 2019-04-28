#include <iostream>
#include <string>
#include <cmath>
#include "Space2.hpp"

/****************************************
** Constructor intializes direction
** pointers
****************************************/
Space::Space()
{
    this->North = NULL;
    this->South = NULL;
    this->East = NULL;
    this->West = NULL;
}

/*************************************
** Get space string
*************************************/
std::string Space::getSpace()
{
    return this->curSpace;
}

/*************************************
** Set space string
*************************************/
void Space::setSpace(std::string space)
{
    this->curSpace = space;
}

/****************************************
** Get info string
****************************************/
std::string Space::getInfo()
{
    return this->curInfo;
}

/******************************************
** Virtual void function that displays
** questions and prompts
******************************************/
void Space::fightMonster(Fighter* f)
{
}

/*************************************
** Set directions depending
** on where the location is
*************************************/
void Space::setDirection(Space* n, Space* s, Space* e, Space* w)
{
    this->North = n;
    this->South = s;
    this->East = e;
    this->West = w;
}

/************************************************
** Displays questions for user to move
** through spaces and sets the current space
** user is in
************************************************/
void Space::movePlayer(Fighter* l)
{
    Space* nSpace;
    int userDirection;

    /************************************************
    ** If statements to check where the player
    ** is located to prompt the user appropriately
    ************************************************/
    if (this->North != NULL && this->South != NULL && this->East != NULL && this->West != NULL)
    {
        do
        {
            std::cout << "Where would you like to travel to? (Available directions)" << std::endl;
            std::cout << "Options: Press 1. To travel north to the Forrest." << std::endl;
            std::cout << "Press 2. To travel south to the Underworld(Try to collect items before going here)." << std::endl;
            std::cout << "Press 3. To travel to the east to the Graveyard." << std::endl;
            std::cout << "Press 4. To travel to the west to the Mountains." << std::endl;
            std::cin >> userDirection;
            std::cin.clear();
            std::cin.ignore(50, '\n');
        }while(userDirection != 1 && userDirection != 2 && userDirection != 3 && userDirection != 4);

        if (userDirection == 1)
        {
            nSpace = this->North;

            l->setcurSpace(nSpace);
        }

        else if (userDirection == 2)
        {
            nSpace = this->South;

            l->setcurSpace(nSpace);
        }

        else if (userDirection == 3)
        {
            nSpace = this->East;

            l->setcurSpace(nSpace);
        }

        else if (userDirection == 4)
        {
            nSpace = this->West;

            l->setcurSpace(nSpace);
        }
    }

    else if (this->North != NULL && this->South == NULL && this->East != NULL && this->West == NULL)
    {
        do
        {
            std::cout << "Where would you like to travel to? (Available directions)" << std::endl;
            std::cout << "Options: Press 1. To travel north to the Graveyard." << std::endl;
            std::cout << "Press 2. To travel east to the Purgatory." << std::endl;
            std::cin >> userDirection;
            std::cin.clear();
            std::cin.ignore(50, '\n');
        }while(userDirection != 1 && userDirection != 2);

        if (userDirection == 1)
        {
            nSpace = this->North;

            l->setcurSpace(nSpace);
        }

        else if (userDirection == 2)
        {
            nSpace = this->East;

            l->setcurSpace(nSpace);
        }

    }

    else if (this->North == NULL && this->South != NULL && this->East != NULL && this->West != NULL)
    {
         do
        {
            std::cout << "Where would you like to travel to? (Available directions)" << std::endl;
            std::cout << "Options: Press 1. To travel south to the Purgatory." << std::endl;
            std::cout << "Press 2. To travel east to the Forrest." << std::endl;
            std::cout << "Press 3. To travel west to the Graveyard." << std::endl;
            std::cin >> userDirection;
            std::cin.clear();
            std::cin.ignore(50, '\n');
        }while(userDirection != 1 && userDirection != 2 && userDirection != 3);

        if (userDirection == 1)
        {
            nSpace = this->South;

            l->setcurSpace(nSpace);
        }

        else if (userDirection == 2)
        {
            nSpace = this->East;

            l->setcurSpace(nSpace);
        }

        else if (userDirection == 3)
        {
            nSpace = this->West;

            l->setcurSpace(nSpace);
        }
       
    }

    else if (this->North == NULL && this->South != NULL && this->East == NULL && this->West != NULL)
    {
        do
        {
            std::cout << "Where would you like to travel to? (Available directions)" << std::endl;
            std::cout << "Options: Press 1. To travel south to the Forrest." << std::endl;
            std::cout << "Press 2. To travel west to the Mountain." << std::endl;
            std::cin >> userDirection;
            std::cin.clear();
            std::cin.ignore(50, '\n');
        }while(userDirection != 1 && userDirection != 2);

        if (userDirection == 1)
        {
            nSpace = this->South;

            l->setcurSpace(nSpace);
        }

        else if (userDirection == 2)
        {
            nSpace = this->West;

            l->setcurSpace(nSpace);
        }


    }

    else if (this->North != NULL && this->South == NULL && this->East == NULL && this->West == NULL)
    {
        do
        {
            std::cout << "Where would you like to travel to? (Available directions)" << std::endl;
            std::cout << "Options: Press 1. To travel north to the Afterworld." << std::endl;
            std::cin >> userDirection;
            std::cin.clear();
            std::cin.ignore(50, '\n');
        }while(userDirection != 1);

        if (userDirection == 1)
        {
            nSpace = this->North;

            l->setcurSpace(nSpace);
        }

    }
}

/***********************************
** Destructor
***********************************/
Space::~Space()
{
}

    
