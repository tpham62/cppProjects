#include "Graveyard.hpp"
#include "Space2.hpp"
#include "Fighter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/************************************************************
** Constructor that sets string for graveyard and sets
** counter if character has been here or not.
************************************************************/
Graveyard::Graveyard() : Space()
{
    this->curSpace = "Graveyard";
    this->curInfo = "You approach a strange graveyard covered in fog. In the midst of the graveyard there is an Animated Skeleton. The skeleton has a malicious look in its eyes.";
    this->finGrave = false;
}

/**************************************************************************
** Function that displays graveyard questions and can give player an item
** or they die or leave with nothing
**************************************************************************/
void Graveyard::fightMonster(Fighter* f)
{
    int userInput;
    int skeletonTest;

    std::cout << this->getSpace() << std::endl;

    /***********************************************
    ** Checks if steps exceed counter
    ***********************************************/
    if (f->counter < 10)
    {
        /***************************************
        ** Checks to see if user has been
        ** here before
        ***************************************/
        if (this->finGrave == false)
        {
            do
            {
                std::cout << this->getInfo() << std::endl;

                std::cout << "Options: Press 1. Sneakily pass the skeleton." << std::endl;
                std::cout << "Press 2. Approach the skeleton." << std::endl;
                std::cin >> userInput;
                std::cin.clear();
                std::cin.ignore(50, '\n');
            }while(userInput != 1 && userInput != 2);

            if (userInput == 1)
            {
                std::cout << "You snuck pass the skeleton and you sprint through the graveyard." << std::endl;
            }

            else if (userInput == 2)
            {
                std::cout << "You approach the skeleton as you approach the Skeleton notices you. It screams in fears and it's head falls off." << std::endl;

                do
                {
                    std::cout << "Options: Press 1. To grab the skull and keep it for some reason." << std::endl;
                    std::cout << "Press 2. To throw it." << std::endl;
                    std::cout << "Press 3. To leave it along and go along your way like nothing happened." << std::endl;
                    std::cin >> skeletonTest;
                    std::cin.clear();
                    std::cin.ignore(50, '\n');
                }while(skeletonTest != 1 && skeletonTest != 2 && skeletonTest != 3);

                if (skeletonTest == 1)
                {
                    std::cout << "You grab the skull and stuff it in your backpack." << std::endl;
                    if (f->bag.size() < 3)
                    {
                        f->setSkull(true);
                        f->addItem("Skull");
                    }

                    else
                    {
                        std::cout << "You do not have any space to store the Skull so you just leave it there." << std::endl;
                    }

                }

                else if (skeletonTest == 2)
                {
                    std::cout << "After you throw the skull you notice the ground start to rumble." << std::endl;
                    std::cout << "Skeletons start to arise from the ground holding weapons." << std::endl;
                    std::cout << "As they come out they start going towards you swinging their swords." << std::endl;

                    if (f->getWisp() == true)
                    {
                        std::cout << "The wisp in your backpack starts to rumble. As you pull it out the entire bottle starts to shake violently. The bottle then explodes with white light while inside the bottle." << std::endl;
                        std::cout << "As your eyes adjust from the brightness. You notice all of the Skeletons are on the ground and not moving." << std::endl;
                    }

                    else
                    {
                        std::cout << "You get surrounded by the skeletons and they kill you. You now rest within the graveyard." << std::endl;
                        f->setAlive(false);
                    }
                }
            }

            /**********************************************
            ** Checks if user is alive and moves player
            ** and sets counter to be true that user
            ** has been here and adds step counters
            **********************************************/
            if (f->getAlive() == false)
            {
                std::cout << "You have met your end in a graveyard. How ironic. Rest in peace." << std::endl;
            }

            else
            {
               this->movePlayer(f);
               this->finGrave = true;
               f->counter = f->counter + 1;
            }

        }

        else if (this->finGrave == true)
        {
            std::cout << "You reach the graveyard. There are nothing in the field except for a skull on the floor." << std::endl;

            if (f->bag.size() < 3)
            {
                if (f->getSkull() == false)
                {
                    std::cout << "You pick up the skull and store it in your bag." << std::endl;
                    f->setSkull(true);
                    f->addItem("Skull");
                }

                else
                {
                    std::cout << "You walk through the graveyard and reach the end." << std::endl;
                }
            }

            else
            {
                std::cout << "Your bag is full and cannot hold any more items." << std::endl;
            }

            f->counter = f->counter = 1;
        }

    }

    else
    {
        std::cout << "Without your soul your journey has come to an end. Rest in peace." << std::endl;
        f->setAlive(false);
    }


}

Graveyard::~Graveyard()
{
}

