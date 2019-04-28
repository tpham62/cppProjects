#include <iostream>
#include <string>
#include "Space2.hpp"
#include "Fighter.hpp"
#include "Mountain.hpp"
#include "Graveyard.hpp"
#include "Forrest.hpp"
#include "Underworld.hpp"
#include "Purgatory.hpp"
#include "Afterworld.hpp"

int main()
{
    /*****************************************
    ** Initializes integers and class objects
    *****************************************/
    int startGame;
    Space* purg = new Purgatory();
    Space* forr = new Forrest();
    Space* mount = new Mountain();
    Space* grave = new Graveyard();
    Space* under = new Underworld();
    Space* after = new Afterworld();
    Fighter* fighter1;

    fighter1 = new Fighter();

    std::cout << "Welcome to the choice adventure fantastical game. You are a traveler who is looking for his soul. You must go on an adventure to find your soul. Hopefully on your way you make the right choices and find your soul, spirit and body or you will just disppear with something missing." << std::endl;

    /***************************************************
    ** Do while loop to start game or exit
    ***************************************************/
    do
    {
        std::cout << "Press 1 to start the game or press 2 to exit." << std::endl;
        std::cin >> startGame;
        std::cin.clear();
        std::cin.ignore(50, '\n');
    }while(startGame != 1 && startGame != 2);

    if (startGame == 1)
    {
        /***********************************************************
        ** Sets direction of each place for user to transverse
        ***********************************************************/
        purg->setDirection(forr, under, grave, mount);
        forr->setDirection(grave, NULL, purg, NULL);
        mount->setDirection(NULL, purg, forr, grave);
        grave->setDirection(NULL, forr, NULL, mount);
        under->setDirection(after, NULL, NULL, NULL);
        after->setDirection(NULL, NULL, NULL, NULL);

        /******************************************
        ** Starts user in purgatory
        ******************************************/
        purg->fightMonster(fighter1);

        /*******************************************
        ** While loop that will keep moving player
        ** as they choose until they die or
        ** win the game or run out of steps
        *******************************************/
        while (fighter1->getAlive() == true)
        {

            fighter1->getcurSpace()->fightMonster(fighter1);
        }


    }

    else
    {
        std::cout << "Thanks for playing the game." << std::endl;
    }

    /**************************************************
    ** Clears memory
    **************************************************/
    delete purg;
    delete forr;
    delete mount;
    delete grave;
    delete under;
    delete after;
    delete fighter1;

    return 0;
}
