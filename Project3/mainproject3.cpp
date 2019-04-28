#include <iostream>
#include <string>
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

int main()
{
    int characterPick,
        playNum,
        temp,
        temp1,
        exit;
    exit = 1;

    std::cout << "Welcome to the Monster Fighter Game." << std::endl;

    /****************************************
    ** Do while loop for menu with input
    ** validation to pick a character
    ****************************************/
    do
    {
         std::cout <<"Please pick from the following 4 monsters by entering the appropriate number." << std::endl;
         std::cout << "1. Vampire" << std::endl;
         std::cout << "2. Barbarian" << std::endl;
         std::cout << "3. BlueMen" << std::endl;
         std::cout << "4. Medusa" << std::endl;
         std::cout << "5. HarryPotter" << std::endl;
         std::cout << "Press 6 to quit." << std::endl;
         std::cin >> characterPick;
         std::cin.clear();
         std::cin.ignore(50, '\n');
    }while(characterPick != 1 && characterPick != 2 && characterPick != 3 && characterPick != 4 && characterPick != 5 && characterPick != 6);

    /************************************************************
    ** Creates first character object pointer based on what
    ** the user inputs the object pointer will point to a
    ** specific class creating a new object of that class as well
    ************************************************************/
    Characters *character1;

    if (characterPick == 1)
    {
        character1 = new Vampire();
    }

    else if (characterPick == 2)
    {
        character1 = new Barbarian();
    }

    else if (characterPick == 3)
    {
        character1 = new BlueMen();
    }

    else if (characterPick == 4)
    {
        character1 = new Medusa();
    }

    else if (characterPick == 5)
    {
        character1 = new HarryPotter();
    }

    else if (characterPick == 6)
    {
        std::cout << "Thanks for playing." << std::endl;
    }

    if (characterPick != 6)
    {
        /***************************************************
        ** Do while loop to pick the second character
        ***************************************************/
        do
        {
             std::cout <<"Please pick another monster to fight." << std::endl;
             std::cout << "1. Vampire" << std::endl;
             std::cout << "2. Barbarian" << std::endl;
             std::cout << "3. BlueMen" << std::endl;
             std::cout << "4. Medusa" << std::endl;
             std::cout << "5. HarryPotter" << std::endl;
             std::cin >> characterPick;
             std::cin.clear();
             std::cin.ignore(50, '\n');
        }while(characterPick != 1 && characterPick != 2 && characterPick != 3 && characterPick != 4 && characterPick != 5);

        /*******************************************
        ** Second object pointer created
        *******************************************/
        Characters *character2;

        if (characterPick == 1)
        {
            character2 = new Vampire();
        }

        else if (characterPick == 2)
        {
            character2 = new Barbarian();
        }

        else if (characterPick == 3)
        {
            character2 = new BlueMen();
        }

        else if (characterPick == 4)
        {
            character2 = new Medusa();
        }

        else if (characterPick == 5)
        {
            character2 = new HarryPotter();
        }

        /*************************************************************************
        ** Do while loop that prints out attacker type, defender type, armor,
        ** strenght points. The attacks dice roll, the Defenders dice roll.
        ** as well as the total damage inflicted and remaining health points. As
        ** well as any special abilities.
        *************************************************************************/
        do
        {
            /*******************************************
            ** If statements to exit out of loop once
            ** someone loses
            *******************************************/
            if (character1->StrengthPoints() > 0)
            {
                std::cout << "------------------------------------------------------------" << std::endl;
                std::cout << "Attacker is " << character1->getType() << " A." << std::endl;
                std::cout << "Defender is " << character2->getType() << " B." << std::endl;
                std::cout << character2->getType() << " B has " << character2->Armor() << " armor." << std::endl;
                std::cout << character2->getType() << " B has " << character2->StrengthPoints() << " hit points." << std::endl;
                character1->rollAttack();
                if (playNum == 3)
                {
                    character1->setAttack(12);
                }
                character2->rollDefense();
                std::cout << character1->getType() << " A rolls a " << character1->getAttack() << " attack roll." << std::endl;
                std::cout << character2->getType() <<" B rolls a " << character2->getDefense() << " defense roll." << std::endl;
                std::cout << "Damage dealt to " << character2->getType() << " B is " << character1->Attack(character2) << " points." << std::endl;
                std::cout << "Remaining hit points of " << character2->getType() <<" B is " << character2->StrengthPoints() << "." << std::endl;
            }

            if (character2->StrengthPoints() > 0)
            {
                std::cout << "------------------------------------------------------------" << std::endl;
                std::cout << "Attacker is " << character2->getType() << " B." << std::endl;
                std::cout << "Defender is " << character1->getType() << " A." << std::endl;
                std::cout << character1->getType() << " A has " << character1->Armor() << " armor." << std::endl;
                std::cout << character1->getType() << " A has " << character1->StrengthPoints() << " hit points." << std::endl;
                character2->rollAttack();
                if (playNum == 3)
                {
                    character2->setAttack(12);
                }
                character1->rollDefense();
                std::cout << character2->getType() << " B rolls a " << character2->getAttack() << " attack roll." << std::endl;
                std::cout << character1->getType() <<" A rolls a " << character1->getDefense() << " defense roll." << std::endl;
                std::cout << "Damage dealt to " << character1->getType() << " A is " << character2->Attack(character1) << " points." << std::endl;
                std::cout << "Remaining hit points of " << character1->getType() << " A is " << character1->StrengthPoints() << "." << std::endl;
            }

            /*******************************************
            ** Loop to either quit or continue playing
            *******************************************/
            if (character1->StrengthPoints() > 0 && character2->StrengthPoints() > 0)
            {
                do
                {
                    std::cout << "------------------------------------------------------------" << std::endl;
                    std::cout << "Press 1 to play again or press 2 to exit." << std::endl;
                    std::cout << "EXTRA: Press 3 to set all character attack rolls to 12 to test out Medusa's special ability." << std::endl;
                    std::cin >> playNum;
                    std::cin.clear();
                    std::cin.ignore(50, '\n');
                }while (playNum != 1 && playNum != 2 && playNum != 3);

                if (playNum == 2)
                {
                    exit = 0;
                }
            }

        }while(character1->StrengthPoints() > 0 && character2->StrengthPoints() > 0 && exit != 0);

        /***********************************************************************
        ** If and else statements to print out if someone has died and prints
        ** Out thanks for playing
        ***********************************************************************/
        if (character2->StrengthPoints() <= 0 && character1->StrengthPoints() <= 0)
        {
            std::cout << "Both " << character1->getType() << " A is dead and " << character2->getType() << " is dead." << std::endl;
        }

        else if (character1->StrengthPoints() <= 0)
        {
            std::cout << character1->getType() << " A is dead. " << character2->getType() << " B won!"<< std::endl;
        }

        else if (character2->StrengthPoints() <= 0)
        {
            std::cout << character2->getType() << " B is dead. " << character1->getType() << " A won!" << std::endl;
        }
        
        else
        {
            std::cout << "Thanks for playing." << std::endl;
        }

        /**************************************************
        ** Deletes object pointers
        **************************************************/
        delete character2;

        delete character1;
    }


    return 0;
}
