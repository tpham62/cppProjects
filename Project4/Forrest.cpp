#include "Forrest.hpp"
#include "Space2.hpp"
#include "Fighter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/************************************************
** Initializes forrest string and sets counter
** if the traveler has been here or not
************************************************/
Forrest::Forrest() : Space()
{
    this->curSpace = "Forrest";
    this->curInfo = "You have entered the vast forrest. Land of the Orcs. An orc stands in your way. (Orc's are easily agitated)";
    this->finFor = false;
}

/**************************************************
** Function that displays forrest section and
** asks user a series of questions by an orc.
** Grants user a Crystal if answered correctly
** or die or leave with no items.
**************************************************/
void Forrest::fightMonster(Fighter* f)
{

    int userInput;
    int orcTest;

    std::cout << this->getSpace() << std::endl;

    /********************************************
    ** Checks counter for maount of steps
    ********************************************/
    if(f->counter < 10)
    {
        /*******************************************
        ** Checks if user has been here
        *******************************************/
        if (this->finFor == false)
        {

            /************************************
            ** Displays and starts orc questions
            ************************************/
            do
            {
                std::cout << this->getInfo() << std::endl;

                std::cout << "You have approached the Orc. The Orc asks, " << "What is your name traveler?" << std::endl;
                std::cout << "Options: Press 1. Tell him your name." << std::endl;
                std::cout << "Press 2. To lie." << std::endl;
                std::cin >> userInput; 
                std::cin.clear();
                std::cin.ignore(50, '\n');
            }while(userInput != 1 && userInput != 2);

            if (userInput == 1)
            {
                std::cout << "You have told the Orc your name was " << "Bob" << ". The Orc nods and asks you a riddle." << std::endl;
                std::cout << "If one was sleeping and became hungry and one knew that food was in their fridge. What is the first thing one opens?" << std::endl;

                do
                {
                    std::cout << "Options: Press 1. Tell the Orc that you are never hungry and that is a silly question." << std::endl;
                    std::cout << "Press 2. Tell the Orc that you open your eyes first." << std::endl;
                    std::cout << "Press 3. Tell the Orc that you open your fridge first." << std::endl;
                    std::cout << "Press 4. Tell the Orc that you open your mind first." << std::endl;
                    std::cout << "Press 5. Tell the Orc nothing and remain silent." << std::endl;
                    std::cout << "Press 6. Tell the Orc that he just needs to move out of your way." << std::endl;
                    std::cin >> orcTest;
                    std::cin.clear();
                    std::cin.ignore(50, '\n');
                }while(orcTest != 1 && orcTest != 2 && orcTest != 3 && orcTest != 4 && orcTest != 5 && orcTest != 6);

                if (orcTest == 1)
                {
                    std::cout << "The Orc snorts in disgusts. He says, \"Very well human. You can pass.\"" << std::endl;
                    std::cout << "You have survived the confrontation without any gifts or harm." << std::endl;
                }

                else if (orcTest == 2 || orcTest == 3 || orcTest == 4)
                {
                    std::cout << "The Orc chuckles. \"That indeed is......WRONG. But since you have told me the truth earlier I shall let you pass.\"" << std::endl;
                }

                else if (orcTest == 5)
                {
                    std::cout << "The Orc remained silent. \"Correct human. Since you have correctly answered I shall give you this magic crystal to help you along your journey.\"" << std::endl;
                    std::cout << "The Orc steps aside with a smirk. You pass by." << std::endl;

                    /******************************************
                    ** Adds item in bag and checks if
                    ** bag is full
                    ******************************************/
                    if (f->bag.size() < 3)
                    {
                        f->setCrystal(true);
                        f->addItem("Crystal");
                    }

                    else
                    {
                        std::cout << "You do not have any space to store the Crystal so you thank the Orc and go on your way." << std::endl;
                    }

                }

                else if (orcTest == 6)
                {
                    std::cout << "The Orc scoffs. \"You are indeed a foolish human.\" The Orc swings his giant club at you. You attempt to dodge but is hit by its full force. You are 1000 percent dead." << std::endl;
                    f->setAlive(false);
                }
            }

            /*************************************************
            ** Lie version of the questions
            *************************************************/
            else if (userInput == 2)
            {
                std::cout << "You lied and have told the Orc that your name was Dragonmonsterdestructocommando5." << std::endl;
                std::cout << "The Orc snorts. \"Answer this riddle human or suffer my wrath.\"." << std::endl;
                std::cout << "If one was sleeping and became hungry and one knew that food was in their fridge. What is the first thing one opens?" << std::endl;

                do
                {
                    std::cout << "Options: Press 1. Tell the Orc that you are never hungry and that is a silly question."<< std::endl;
                    std::cout << "Press 2. Tell the Orc that you open your eyes first." << std::endl;
                    std::cout << "Press 3. Tell the Orc that you open your fridge first." << std::endl;
                    std::cout << "Press 4. Tell the Orc that you open your mind first." << std::endl;
                    std::cout << "Press 5. Tell the Orc nothing and remain silent." << std::endl;
                    std::cout << "Press 6. Tell the Orc that he just needs to move out of your way." << std::endl;
                    std::cin >> orcTest;
                    std::cin.clear();
                    std::cin.ignore(50, '\n');
                }while(orcTest != 1 && orcTest != 2 && orcTest != 3 && orcTest != 4 && orcTest != 5 && orcTest != 6);

                if (orcTest == 1)
                {
                    std::cout << "The Orc snorts in disgusts. He says, \"Very well human. You can pass.\"" << std::endl;
                    std::cout << "You leave this confrontation with a eerie feeling." << std::endl;
                    this->orcEnemy = true;
                }

                else if (orcTest == 2 || orcTest == 3 || orcTest == 4)
                {
                    std::cout << "The Orc chuckles. \"That indeed is......WRONG. But you have lied to me earlier. Now die!!!!!\"" << std::endl;
                    std::cout << "The Orc gives you zero chance to react he clubs you so hard that you died instantaenously on impact. Your body is no where to be found." << std::endl;
                    f->setAlive(false);
                }

                else if (orcTest == 5)
                {
                    std::cout << "The Orc remained silent. \"Correct human.\"" << std::endl;
                    std::cout << "The Orc steps away and you pass." << std::endl;
                }

                else if (orcTest == 6)
                {
                    std::cout << "The Orc scoffs. \"You are indeed a foolish human.\" The Orc swings his giant club at you. You attempt to dodge but is hit by its full force. You are 1000 percent dead." << std::endl;
                    f->setAlive(false);
                }
            }

            if (f->getAlive() == false)
            {
                std::cout << "Traveler you have reached your end. The choices that you have made has been your downfall." << std::endl;
            }

            else
            {
                /*********************************************
                ** Moves character and adds counter
                *********************************************/
                this->movePlayer(f);
                this->finFor = true;
                f->counter = f->counter + 1;
            }
        }

        /***************************************************
        ** Displays string if user has been here before
        ** Adds counter and moves player.
        ***************************************************/
        else if (this->finFor == true)
        {
            std::cout << "As you pass through the Forrest you see a piece of paper that seemed to have fallen out of a book. You take a look at it and you see it filled with riddles. You notice one of the riddles has no answer. You throw the pieced of paper away and reach the end of the forrest." << std::endl;
            f->counter = f->counter + 1;
            this->movePlayer(f);
        }
    }

    /****************************************************
    ** Displays string if the user has exceeded steps
    ****************************************************/
    else
    {
        std::cout << "You have been without your soul for too long. You look at the leaves one last time as you fade away into nothingness." << std::endl;
        f->setAlive(false);
    }

}

Forrest::~Forrest()
{
}






