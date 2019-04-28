#include "Purgatory.hpp"
#include "Space2.hpp"
#include "Fighter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/**************************************************
** Constructor sets name, counter for steps,
** and counter if the traveler has been there or
** not
**************************************************/
Purgatory::Purgatory() : Space()
{
    this->curSpace = "Purgatory";
    this->curInfo = "Purgatory land of the lost.... You have been here for a long time. You do not remember how long you have been here but you know you are missing something. Your soul...";
    this->finPurg = false;
    this->purgCount = 0;
}

/***************************************************************
** Displays prompt for user to collect a starting item or
** not and starts the user on their journey.
***************************************************************/
void Purgatory::fightMonster(Fighter* f)
{
    int userInput;
    int ghostTest;
    int pleaseInput;


    std::cout << this->getSpace() << std::endl;

    /************************************
    ** Checks if user has used 10 steps
    ** or not
    ************************************/
    if (f->counter < 10)
    {
        /********************************************
        ** checks to see if person has been here
        ** or not
        ********************************************/
        if (this->finPurg == false)
        {
            std::cout << this->getInfo() << std::endl;

            std::cout << "A ghost approaches you with two items. She carries them with grace and with kindness." << std::endl;
            std::cout << "She says, \"Choose your item on this journey. Choose wisely as it will affect everything you do." << std::endl;
            std::cout << "Keep in mind you can have only a maximum of 3 items. You may not exchange any items nor drop any items. Any items that you accept is permanently in your bag for the rest of the game." << std::endl;

            /***********************************************
            ** Give user a chance to grab an item or not
            ***********************************************/
            do
            {
                std::cout << "Options: Press 1. An axe. Practical in fights." << std::endl;
                std::cout << "Press 2. A flute. Not pratical in fights." << std::endl;
                std::cout << "Press 3. You choose nothing cause you are ballsy." << std::endl; 
                std::cin >> userInput;
                std::cin.clear();
                std::cin.ignore(50, '\n');
            }while(userInput != 1 && userInput != 2 && userInput != 3);

            if (userInput == 1)
            {
                std::cout << "You have chosen the axe. That is a warrior's choice. Too bad you weren't one in your past life." << std::endl;
                f->setAxe(true);
                f->addItem("Axe");
            }

            else if (userInput == 2)
            {
                std::cout << "You have chosen the flute. That is a bard's choice. You were once a bard." << std::endl;
                f->setFlute(true);
                f->addItem("Flute");
            }

            else if (userInput == 3)
            {
                std::cout << "Ah are you sure traveler?" << std::endl;

                do
                {
                    std::cout << "Options: Press 1. To say never mind I will take the axe." << std::endl;
                    std::cout << "Press 2. Ahhh let me take that flute instead then." << std::endl;
                    std::cout << "Press 3. I don't want anything." << std::endl;
                    std::cin >> ghostTest;
                    std::cin.clear();
                    std::cin.ignore(50, '\n');
                }while(ghostTest != 1 && ghostTest != 2 && ghostTest != 3);

                if (ghostTest == 1)
                {
                    std::cout << "You have chosen the axe. That is a warrior's choice. Too bad you weren't one in your past life." << std::endl;
                    f->setAxe(true);
                    f->addItem("Axe");
                }

                else if (ghostTest == 2)
                {
                    std::cout << "You have chosen the flute. That is a bard's choice. You were once a bard." << std::endl;
                    f->setFlute(true);
                    f->addItem("Flute");
                }

                else
                {
                    std::cout << "Alright traveler you shall go on your journey without any items." << std::endl;
                    f->setFist(true);
                }
            }

            this->finPurg = true;
            f->counter = f->counter + 1;
        }

        else if (this->finPurg == true)
        {
            /***********************************************
            ** Checks if user has been here once
            ***********************************************/
            if (this->purgCount != 1)
            {
                std::cout << "Standing in the middle of the midst is the ghost that you have met before." << std::endl;
                std::cout << "Hello again, traveler. How may I help you?" << std::endl;
                
                do
                {
                    std::cout << "Options: Press 1. Can you help me out?" << std::endl;
                    std::cout << "Press 2. I am okay, thank you." << std::endl;
                    std::cin >> pleaseInput;
                    std::cin.clear();
                    std::cin.ignore(50, '\n');
                }while(pleaseInput != 1 && pleaseInput != 2);

                if (pleaseInput == 1)
                {
                    std::cout << "Each area contains an item that can be gained. Gather all 3 items and approach the Underworld with confidence." << std::endl;
                    std::cout << "Good luck traveler." << std::endl;
                    this->purgCount = 1;
                }

                else
                {
                    std::cout << "Alright traveler. Be on your way." << std::endl;
                    this->purgCount = 1;
                }
            }

            else if (this->purgCount == 1)
            {
                std::cout << "Hello again, traveler." << std::endl;
            }

            f->counter = f->counter + 1;
        }

        /************************************************
        ** Asks user for directions and moves cuser
        ************************************************/
        this->movePlayer(f);
    }

    /******************************************************************
    ** Displays string if user has exceeded the amount of steps
    ******************************************************************/
    else
    {
        std::cout << "Since your soul has been away for so long you begin to disappear and you pass away." << std::endl;
        f->setAlive(false);
    }

}

Purgatory::~Purgatory()
{
}



