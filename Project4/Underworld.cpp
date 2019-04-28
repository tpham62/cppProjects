#include "Underworld.hpp"
#include "Space2.hpp"
#include "Fighter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/*********************************************************
** Constructor that sets strings and sets counter if
** person has been here or not
*********************************************************/
Underworld::Underworld() : Space()
{
    this->curSpace = "Underworld";
    this->curInfo = "You reach the gates of the underworld. As you enter you see the demon. The demon you have been looking for this entire time. Time to face your fears.";
    this->finUnder = false;
}

/*****************************************************************
** Function lets user either leave with nothing and ends the game
** or they have a wisp and go to the afterworld or the user
** gets killed
*****************************************************************/
void Underworld::fightMonster(Fighter* f)
{
    int userInput;
    int demonTest;

    std::cout << this->getSpace() << std::endl;

    if (f->orcEnemy == true)
    {
        std::cout << this->getInfo() << std::endl;
        std::cout << "The Orc whom you pissed off earlier shows up at the door and kills you on the spot before you could enter the underworld." << std::endl;
        f->setAlive(false);
    }

    else
    {
        std::cout << this->getInfo() << std::endl;

        do
        {
            std::cout << "Options: Press 1. Ready up to fight for your life." << std::endl;
            std::cout << "Press 2. Greet the Demon." << std::endl;
            std::cin >> userInput;
            std::cin.clear();
            std::cin.ignore(50, '\n');
        }while(userInput != 1 && userInput != 2);

        if (userInput == 1)
        {
            if(f->getAxe() == true)
            {
                std::cout << "You ready up your axe and get disintergrated instantly by the demon." << std::endl;
                f->setAlive(false);
            }

            else
            {
                std::cout << "You ready up with no weapons and get disintergrated instantly by the demon." << std::endl;
                f->setAlive(false);
            }
        }

        else if (userInput == 2)
        {
            do
            {
                std::cout << "The demon growls, \"What do you want human?\"" << std::endl;
                std::cout << "Options: Press 1. To tell the demon that you want him to release your soul." << std::endl;
                std::cout << "Press 2. To tell the demon that you are here to kill him." << std::endl;
                std::cout << "Press 3. To tell him you made a mistake and were on your way out." << std::endl;
                std::cin >> demonTest;
                std::cin.clear();
                std::cin.ignore(50, '\n');
            }while(demonTest != 1 && demonTest != 2 && demonTest!= 3);

            if (demonTest == 1)
            {
                if (f->getWisp() == true)
                {
                    std::cout << "You show the demon the wisp. The demon smirks as he returns your soul." << std::endl;
                    this->finUnder = true;
                }

                else
                {
                    std::cout << "The demon roars \"You do not have what I want you will die for asking for such a deal without something of value in exchange.\" You die instantly from his fire breath." << std::endl;
                    f->setAlive(false);
                }
            }

            else if (demonTest == 2)
            {
                std::cout << "You die instantaneously from the wrath of the demon." << std::endl;
                f->setAlive(false);
            }

            else
            {
                std::cout << "The demon looks at you and nod. You leave as nothing happened and you did not complete your mission. You live the rest of your life in sadness and when you die well its not pretty cause you have no soul." << std::endl;
                f->setAlive(false);
                this->finUnder = true;
            }
        }
    }

    /**********************************************
    ** Checks if user is alive or not if they are
    ** it will give the user a chance to go to the
    ** afterworld for an ending
    **********************************************/
    if (f->getAlive() == false)
    {
        std::cout << "You have met your end traveler." << std::endl;
    }

    else
    {
        this->movePlayer(f);
    }
}

Underworld::~Underworld()
{
}
