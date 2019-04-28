#include <iostream>
#include "menu.hpp"

int main()
{
    int choice;

    std::cout << "Welcome to the Langton's Ant simulation." << std::endl;

    /*****************************************
    ** Do while loop that starts to go into
    ** menu function
    *****************************************/
    do
    {
        std::cout << "Please press 1 to start the simulation or 2 to quit." << std::endl;
        std::cin >> choice;

        if (choice != 1 && choice != 2)
            std::cout << "Please enter 1 or 2 in order to start or stop the simulation." << std::endl;

    }while (choice != 1 && choice !=2);

    if (choice == 1)
         menu();

    else{
        std::cout << "Thanks for playing." << std::endl;}

    return 0;

}


