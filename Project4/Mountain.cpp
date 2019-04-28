#include "Mountain.hpp"
#include "Space2.hpp"
#include "Fighter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/***********************************************
** Constructor that sets strings for mountain
** and sets counter if a person has
** been here before or not
***********************************************/
Mountain::Mountain() : Space()
{
    this->curSpace = "Mountain";
    this->curInfo = "You approach the mountain. Standing in your way is a 12 feet tall Troll. He seems to have a goofy demeaner to his face. He chuckles as you approach.";
    this->finMount = false;
}

/*******************************************************************
** Function that starts troll questions. User can die, get a wisp
** that is necessary to pass the underworld, or not get anything
*******************************************************************/
void Mountain::fightMonster(Fighter* f)
{
    int userInput;
    int trollTest;
    int random;

    std::cout << this->getSpace() << std::endl;

    /*************************************************
    ** Counter for steps
    *************************************************/
    if (f->counter < 10)
    {
        /******************************************************
        ** Checks if user has been here or not
        ******************************************************/
        if (this->finMount == false)
        {
            std::cout << this->getInfo() << std::endl;
            std::cout << "\"Hello traveler, what do you want?\" says the Troll." << std::endl;

            do
            {
                std::cout << "Options: Press 1. Tell the Troll that you are just passing by." << std::endl;
                std::cout << "Press 2. Tell the Troll you want to be friends." << std::endl;
                std::cout << "Press 3. Tell the Troll you hate him and ready for batte."<< std::endl;
                std::cout << "Press 4. Tell the Troll you want to tell him a joke so maybe he can like you and he will let you pass." << std::endl;
                std::cout << "Press 5. Tell the Troll nothing and try to run pass him." << std::endl;
                std::cin >> trollTest;
                std::cin.clear();
                std::cin.ignore(50, '\n');
            }while(trollTest != 1 && trollTest != 2 && trollTest != 3 && trollTest != 4 && trollTest != 5);

            if (trollTest == 1)
            {
                std::cout << "\"You may pass traveler\" groans the Troll. \"Only if you show me something that is unique\" says the Troll." << std::endl;

                if (f->getCrystal() == true)
                {
                    std::cout << "You give the Troll the crystal. His eyes glistens. He smiles and lets you pass." << std::endl;
                }

                else if (f->getCrystal() == false && f->getSkull() == true)
                {
                    std::cout << "You show the Troll the skull. He screams in fear. Tosses you the head of the skull and runs away." << std::endl;
                }

                else if (f->getCrystal() == false && f->getSkull() == false)
                {
                    std::cout << "You do not have anything to give the Troll. He roars in anger. You ready up to fight." << std::endl;

                    if (f->getFlute() == true)
                    {
                        std::cout << "You pull out your flute and play a tune. The Troll smiles at the amusement and roars in laughter \"You may pass traveler your courage entices me but first take this for amusing me\". He hands you a wisp in a bottle." << std::endl;
                        f->setWisp(true);

                        /*************************************
                        ** Adds item to bag
                        *************************************/
                        if (f->bag.size() < 3)
                        {
                            f->setWisp(true);
                            f->addItem("Wisp");
                        }

                        else
                        {
                            std::cout << "You do not have any space to store the wisp so you tell the Troll thank you and go on your way." << std::endl;
                        }
                    }

                    else if (f->getAxe() == true)
                    {
                        std::cout << "You pull out your axe. Though your axe is small you ready up to throw your axe." << std::endl;

                        random = 1 + rand() % 2;

                        if (random == 1)
                        {
                            std::cout << "Being a chump you miss your axe. The Troll roars with laughter. \"You pathetic human you may pass for you will not survive." << std::endl;
                        }

                        else if (random == 2)
                        {
                            std::cout << "You hit the Troll square in the head but being such a small axe compared to the axe, it just bounces off. The Troll infuriated charges you and kicks you once. You.... did not survive unfortunately." << std::endl;
                            f->setAlive(false);
                        }
                    }

                    else if (f->getFist() == true)
                    {
                        std::cout << "You ready up your fists as you do the Troll looks at you in puzzlement. He giggles and says \"Why are you readying up puny human? You may pass I was just mad you didn't have anything. I was not going to hurt you or anything\"." << std::endl;
                    }
                }

            }

            else if(trollTest == 2)
            {
                std::cout << "The Troll looks at you in confusion. He laughs and simply says \"No thank you. Be on your way\". You leave the Troll be." << std::endl;
            }

            else if (trollTest == 3)
            {
                std::cout << "The Troll's mood instantly changes to hostility. He immediately punches you in the face killing you faster than you can react. RIP" << std::endl;
                f->setAlive(false);
            }

            else if (trollTest == 4)
            {
                std::cout << "You tell him an inappropriate joke about his mom for some reason. It is met with a blank stare and then he roars with laughter. \"That was clever human. Here is a wisp as a present for showing me such a joke. You may pass." << std::endl;

                /***********************************************
                ** Adds item to bag
                ***********************************************/
                if (f->bag.size() < 3)
                {
                    f->setWisp(true);
                    f->addItem("Wisp");
                }

                else
                {
                    std::cout << "You do not have any space to store the wisp so you tell the Troll thank you and go on your way." << std::endl;
                }
            }

            else if (trollTest == 5)
            {
                std::cout << "The Troll just stares at you but does nothing. You walk pass him with no repercussions." << std::endl;
            }

            if (f->getAlive() == false)
            {
               std::cout << "Traveler you have reached your end. The choices that you have made has been your downfall." << std::endl;
            }

            else
            {
               /****************************************************
               ** Moves player and adds counter
               ****************************************************/
               this->movePlayer(f);
               this->finMount = true;
               f->counter = f->counter + 1;
            }
        }

        /***********************************************
        ** Adds counter and moves player checks
        ** if usedr has been here or not
        ***********************************************/
        else if (this->finMount == true)
        {
            std::cout << "You approach the mountain. Nothing stands in your way this time. The Troll seems to have gone somewhere. What you do hear though is the sound of music in the distance as well as roaring laughter. You pass right through the forrest and the sound gets fainter and fainter." << std::endl;
            this->movePlayer(f);
            f->counter = f->counter + 1;

        }


    }

    else
    {
        std::cout << "Your soul has been out of your body for too long and with that you begin to disappear into nothingness." << std::endl;
        f->setAlive(false);
    }
    

}

Mountain::~Mountain()
{
}

