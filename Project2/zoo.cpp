#include <iostream>
#include "zoo.hpp"
#include "animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <cstdlib>

/********************************************************************
** Constructor that intializes this program
********************************************************************/
Zoo::Zoo()
{
    int bank = 100000;
    int tigerSize = 10;
    int penguinSize = 10;
    int turtleSize = 10;
    int start;
    int count;
    int event;
    int random;
    int checkTiger,
        checkPenguin,
        checkTurtle,
        endTiger,
        endPenguin,
        endTurtle;
    int tigAdult = 0;
    int tigBaby = 0;
    int penAdult = 0;
    int penBaby = 0;
    int turAdult = 0;
    int turBaby = 0;

    Animal animal1(3, 10000, 1, 50, 2000);
    Tiger tiger1;
    Penguin penguin1;
    Turtle turtle1;

    std::cout << "Welcome to the Zoo game.\n" << std::endl;
    std::cout << "Would you like to start the zoo game?" << std::endl; 

    /********************************************************
    ** Do while loop of the starting menu. It will continue
    ** if player chooses so if not it will print out
    ** a sentence and end
    ********************************************************/
    do
    {
        std::cout << "Please enter 1 to start or 2 to exit." << std::endl;
        std::cin >> start;
        std::cin.clear();
        std::cin.ignore(50, '\n');

        if (start == 2)
            std::cout << "Thank you for playing" << std::endl;

            
    }while (start != 1 && start != 2);

    /***********************************************************
    ** If statement that initiated if user chooses to. Do while
    ** loops are then initiated that ask user for inputs to be
    ** set using setfunctions.
    ***********************************************************/
    if (start == 1)
    {
        /****************************************************************************************
        ** Uses inherited class object to print out specific integers based on the animal
        ****************************************************************************************/
        std::cout << "\nTo be an adult a Tiger must be at least " << tiger1.getAge() << " years old." << std::endl;
        std::cout << "The cost of a Tiger is " << tiger1.getCost() << "." << std::endl;
        std::cout << "THe number of babies a Tiger can have as an adult is " << tiger1.getBabies() << "." << std::endl;
        std::cout << "The upkeep of having a Tiger is " << tiger1.getFoodCosts() << "." << std::endl;
        std::cout << "The amount of money you earn having a Tiger is " << tiger1.getPayOff() << " per Tiger.\n" << std::endl;

        /*******************************************************************
        ** Do while loop that takes in number of animals when the
        ** user buys them that also does input validation.
        *******************************************************************/
        do
        {
            std::cout << "Please enter 1 or 2 for the amount of tigers you would like to purchase." << std::endl;
            std::cin >> numTigers;
            std::cin.clear();
            std::cin.ignore(50, '\n');

        }while (numTigers != 1 && numTigers != 2);

        std::cout << "\nTo be an adult a Penguin must be at least " << penguin1.getAge() << " years old." << std::endl;
        std::cout << "The cost of a Penguin is " << penguin1.getCost() << "." << std::endl;
        std::cout << "THe number of babies a Penguin can have as an adult is " << penguin1.getBabies() << "." << std::endl;
        std::cout << "The upkeep of having a Penguin is " << penguin1.getFoodCosts() << "." << std::endl;
        std::cout << "The amount of money you earn having a Penguin is " << penguin1.getPayOff() << " per Penguin.\n" << std::endl;

        do
        {
            std::cout << "Please enter 1 or 2 for the amount of penguins you would like to purchase." << std::endl;
            std::cin >> numPenguins;
            std::cin.clear();
            std::cin.ignore(50, '\n');

        }while (numPenguins != 1 && numPenguins != 2);

        std::cout << "\nTo be an adult a Turtle must be at least " << turtle1.getAge() << " years old." << std::endl;
        std::cout << "The cost of a Turtle is " << turtle1.getCost() << "." << std::endl;
        std::cout << "THe number of babies a Turtle can have as an adult is " << turtle1.getBabies() << "." << std::endl;
        std::cout << "The upkeep of having a Turtle is " << turtle1.getFoodCosts() << "." << std::endl;
        std::cout << "The amount of money you earn having a Turtle is " << turtle1.getPayOff() << " per Turtle.\n" << std::endl;

        do
        {
            std::cout << "Please enter 1 or 2 for the amount of turtles you would like to purchase." << std::endl;
            std::cin >> numTurtles;
            std::cin.clear();
            std::cin.ignore(50, '\n');

        }while (numTurtles != 1 && numTurtles != 2);

        /**************************************************************
        ** Initiating dynamic array with the starting size of 10.
        **************************************************************/
        int *tigers = new int[tigerSize];
        int *penguins = new int[penguinSize];
        int *turtles = new int[turtleSize];

        /*******************************************************
        ** Initializes array with -1 to indicate an empty space
        *******************************************************/
        for (count = 0; count < tigerSize; count++)
        {
            tigers[count] = -1;
        }

        for (count = 0; count < penguinSize; count++)
        {
            penguins[count] = -1;
        }

        for (count = 0; count < turtleSize; count++)
        {
            turtles[count] = -1;
        }

        /*******************************************
        ** Places the animals bought into the array
        *******************************************/
        placeAnimals(tigers, penguins, turtles);

        /********************************************
        ** Subtracts the animals costs in the bank.
        ********************************************/
        animalCosts(bank);

        /********************************************************
        ** Do while loop to loop the main game that has events.
        ********************************************************/
        do
        {
            std::cout << "\nYou have " << bank << " left in your bank. \n" << std::endl;

            /************************************************************************
            ** Checks how many adults and babies there are with each given
            ** animal.
            ************************************************************************/
            checkTigerAge(numTigers, tigAdult, tigBaby, tigers);

            checkPenguinAge(numPenguins, penAdult, penBaby, penguins);

            checkTurtleAge(numTurtles, turAdult, turBaby, turtles);

            /******************************************
            ** Prints out adults and babies
            ******************************************/
            std::cout << "You have " << tigAdult << " adult tigers and " << tigBaby << " baby tigers." << std::endl;
            std::cout << "You have " << penAdult << " adult penguins and " << penBaby << " baby penguins." << std::endl;
            std::cout << "You have " << turAdult << " adult turtles and " << turBaby << " baby turtles.\n" << std::endl;

            /**********************************************************
            ** Ages each animal by 1 day
            **********************************************************/
            dayAge(tigers, penguins, turtles, numTigers, numPenguins, numTurtles);

            /***********************************************************
            ** Calculates food costs of each animal and subtracts
            ** it from the budget/bank
            ***********************************************************/
            foodCosts(bank, numTigers, numPenguins, numTurtles);

            /****************************************
            ** Rolls a random number.
            ****************************************/
            randomNumber(event);

            /*****************************************************************
            ** Based on number an event is intialized
            *****************************************************************/
            if (event == 1)
            {
                /****************************************************************
                ** Rolls another random animal to die becoming a -1 in the array
                ****************************************************************/
                sicknessAnimals(numTigers, numPenguins, numTurtles, tigers, penguins, turtles);
            }

            else if (event == 2)
            {
                /****************************************************
                ** Bonus money from the tiger is given to the player
                ****************************************************/
                boomAnimals(bank, numTigers);
            }

            else if (event == 3)
            {
                /***************************************************************
                ** Checks tiger array size and number of animals
                ***************************************************************/
                checkTiger = tigerSize - numTigers;
                checkPenguin = penguinSize - numPenguins;
                checkTurtle = turtleSize - numTurtles;

                /**************************************************
                ** Another random roll
                **************************************************/
                random = 1 + (rand() % 3);

                if (random == 1 && tigAdult > 0)
                {
                    if (checkTiger == 0)
                    {
                        /***********************************************
                        ** Resizes the array if not enough room and
                        ** then adds babies
                        ***********************************************/
                        reSizeTiger(tigerSize, tigers);
                        tigerBorn(numTigers, tigers);
                    }
                    else
                    {
                        /************************
                        ** Adds babies
                        ************************/
                        tigerBorn(numTigers, tigers);
                    }
                }

                else if (random == 2 && penAdult > 0)
                {
                    if (checkPenguin <= 5)
                    {
                        /*******************************************
                        ** Resizes the array if not enough room and
                        ** then adds babies
                        *******************************************/
                        reSizePenguin(penguinSize, penguins);
                        penguinBorn(numPenguins, penguins);
                    }
                    
                    else
                    {
                        /************************
                        ** Adds babies
                        ************************/
                        penguinBorn(numPenguins, penguins);
                    }
                }

                else if (random == 3 && turAdult > 0)
                {
                    if (checkTurtle <= 10)
                    {
                        /*******************************************
                        ** Resizes the array if not enough room and
                        ** then adds babies
                        *******************************************/
                        reSizeTurtle(turtleSize, turtles);
                        turtleBorn(numTurtles, turtles);
                    }

                    else
                    {
                        /************************
                        ** Adds babies
                        ************************/
                        turtleBorn(numTurtles, turtles);
                    }
                }
            }

            /***************************************************************
            ** Pays player based on number of animals and what type
            ***************************************************************/
            animalPayOff(bank, numTigers, numPenguins, numTurtles);

            /***************************************************************
            ** Another check is initiated to resize array if needed for the
            ** next purchase of animals.
            ***************************************************************/
            endTiger = tigerSize - numTigers;
            endPenguin = penguinSize - numPenguins;
            endTurtle = turtleSize - numTurtles;

            if (endTiger == 0)
                reSizeTiger(tigerSize, tigers);
            else if (endPenguin == 0)
                reSizePenguin(penguinSize, penguins);
            else if (endTurtle == 0)
                reSizeTurtle(turtleSize, turtles);

            /****************************************************
            ** Option to purchase an animal or not
            ****************************************************/
            endBuy(bank, tigerSize, penguinSize, turtleSize, numTigers, numPenguins, numTurtles, tigers, penguins, turtles);

            /*******************************************************
            ** Prints out bank and asks player if they want to
            ** continue or quit or if they ran out of money.
            ** Tell them they lose.
            *******************************************************/
            gameOver(bank, start);

        }while (start == 1);

    /****************************************
    ** Deallocates dynamic arrays
    ****************************************/
    delete [] tigers;
    delete [] penguins;
    delete [] turtles;

    }
    
}

/****************************************
** Deconstructor
****************************************/
Zoo::~Zoo()
{
}

/*******************************************************
** Checks for ages of tigers
*******************************************************/
void Zoo::checkTigerAge(int &numTigers, int &tigerAdult, int &tigerBaby, int *tigers)
{
    int count;

    for (count = 0; count < numTigers; count++)
    {
        tigers[count];

        if (tigers[count] < 3 && tigers[count] >= 0)
        {
            tigerBaby = tigerBaby + 1;
        }

        else if (tigers[count] >= 3)
        {
            tigerAdult = tigerAdult + 1;
        }
    }
}

/******************************************
** Checks for ages of penguins
******************************************/
void Zoo::checkPenguinAge(int &numPenguins, int &penguinAdult, int &penguinBaby, int *penguins)
{
    int count;

    for (count = 0; count < numPenguins; count++)
    {
        penguins[count];

        if (penguins[count] < 3 && penguins[count] >= 0)
        {
            penguinBaby = penguinBaby + 1;
        }

        else if (penguins[count] >= 3)
        {
            penguinAdult = penguinAdult + 1;
        }
    }
}

/********************************************
** Checks for ages of turtles
********************************************/
void Zoo:: checkTurtleAge(int &numTurtles, int &turtleAdult, int &turtleBaby, int *turtles)
{
    int count;

    for (count = 0; count < numTurtles; count++)
    {
        turtles[count];

        if (turtles[count] < 3 && turtles[count] >= 0)
        {
            turtleBaby = turtleBaby + 1;
        }

        else if (turtles[count] >= 3)
        {
            turtleAdult = turtleAdult + 1;
        }
    }
}

/*********************************************************
** Pays player based on animal type and number of animals
*********************************************************/
void Zoo::animalPayOff(int &bank, int &numTigers, int &numPenguins, int &numTurtles)
{
    int payTiger,
        payPenguin,
        payTurtle;

    payTiger = numTigers * 2000;
    payPenguin = numPenguins * 100;
    payTurtle = numTurtles * 5;

    bank = bank + payTiger;
    bank = bank + payPenguin;
    bank = bank + payTurtle;
}

/*******************************************
** Random number generator for event
*******************************************/
void Zoo::randomNumber(int &event)
{
    event = 1 + (rand() % 3);
}

/****************************************************
** Subtracts animal costs from money at the 
** beginning.
****************************************************/
void Zoo::animalCosts(int &bank)
{
    bank = bank - (10000 * numTigers);
    bank = bank - (1000 * numPenguins);
    bank = bank - (100 * numTurtles);
}

/********************************************
** Sickness event kills off an animal
** randomly
********************************************/
void Zoo::sicknessAnimals(int &numTigers, int &numPenguins, int &numTurtles, int *tigers, int *penguins, int *turtles)
{
    int death;

    std::cout << "A super virus occured in your zoo." << std::endl;

    death = 1 + rand() % 100;

        if (death < 101 && death > 66 && numTigers != 0)
        {
            tigers[numTigers-1] = -1;
            numTigers = numTigers - 1;
            std::cout << "A tiger died from the super virus." << std::endl;
        }

        else if (death < 67 && death > 33 && numPenguins != 0)
        {
            penguins[numPenguins-1] = -1;
            numPenguins = numPenguins - 1;
            std::cout << "A penguin died from the super virus." << std::endl;
        }

        else if (death > 0 && death < 34 && numTurtles != 0)
        {
            turtles[numTurtles-1] = -1;
            numTurtles = numTurtles - 1;
            std::cout << "A turtle died from the super virus." << std::endl;
        }

        else if (numTigers == 0 && numPenguins == 0 && numTurtles == 0)
        {
            std::cout << "Everything is dead.";
        }
}

/*************************************************************
** Gives bonus money to player based on number of tigers
*************************************************************/
void Zoo::boomAnimals(int &bank, int numTigers)
{
    int magicMoney;

    magicMoney = 250 + rand() % 500;
    magicMoney = magicMoney * numTigers;

    std::cout << "Congrats there was a money boom. You earned " << magicMoney << "." << std::endl;
    bank = bank + magicMoney;

    std::cout << "You now have " << bank << "." << std::endl;
}

/*****************************************************
** If there is an adult a baby tiger is born.
*****************************************************/
void Zoo::tigerBorn(int &numTigers, int *tigers)
{
    int count;

    for (count = 0; count < numTigers; count++)
    {
        tigers[count];

        if (tigers[count] > 2)
        {
            tigers[numTigers] = 0;

            numTigers = numTigers + 1;

            std::cout << "Congrats a new baby Tiger was born." << std::endl;

            break;
        }
    }

}

/**********************************************************************
** If there is an adult 5 baby penguins are born
**********************************************************************/
void Zoo::penguinBorn(int &numPenguins, int *penguins)
{
    int count,
        scount;

    for (count = 0; count < numPenguins; count++)
    {
        penguins[count];

        if (penguins[count] > 2)
        {
            for (scount = 0; scount < 5; scount++)
            {
                penguins[numPenguins + scount] = 0;
            }

            numPenguins = numPenguins + 5;

            std::cout << "Congrats 5 new baby Penguins were born." << std::endl;

            break;
        }
    }
}

/***************************************************************
** If there is an adult 10 baby turtles are born
***************************************************************/
void Zoo::turtleBorn(int &numTurtles, int *turtles)
{
    int count,
        dcount;

    for (count = 0; count < numTurtles; count++)
    {
        turtles[count];

        if (turtles[count] > 2)
        {
            for (dcount = 0; dcount < 10; dcount++)
            {
                turtles[numTurtles + dcount] = 0;
            }

            numTurtles = numTurtles + 10;
            
            std::cout <<"Congrats 10 new baby Turtles were born." << std::endl;

            break;
        }
    }
}

/*******************************************************
** Resizes the tiger array aka doubling the size
*******************************************************/
void Zoo::reSizeTiger(int &tigerSize, int *&tigers)
{
    int newTigerSize,
        count;

    newTigerSize = tigerSize * 2;

    int* newtigers = new int[newTigerSize];

    for (count = 0; count < newTigerSize; count++)
    {
        newtigers[count] = -1;
    }

    for (count = 0; count < tigerSize; count++)
    {
        newtigers[count] = tigers[count];
    }

    delete [] tigers;

    tigerSize = newTigerSize;
    tigers = newtigers;
}

/***********************************************************
** Resizes the penguin array doubling the size
***********************************************************/
void Zoo::reSizePenguin(int &penguinSize, int *&penguins)
{
    int newPenguinSize,
        count;

    newPenguinSize = penguinSize * 2;

    int* newpenguins = new int[newPenguinSize];

    for (count = 0; count < newPenguinSize; count ++)
    {
        newpenguins[count] = -1;
    }

    for (count = 0; count < penguinSize; count++)
    {
        newpenguins[count] = penguins[count];
    }

    delete [] penguins;

    penguinSize = newPenguinSize;
    penguins = newpenguins;
    
}

/************************************************************
** Resizes turtle array doubling the size
************************************************************/
void Zoo::reSizeTurtle(int &turtleSize, int *&turtles)
{
    int newTurtleSize,
        count;

    newTurtleSize = turtleSize * 2;

    int* newturtles = new int[newTurtleSize];

    for (count = 0; count < newTurtleSize; count ++)
    {
        newturtles[count] = -1;
    }

    for (count = 0; count < turtleSize; count++)
    {
        newturtles[count] = turtles[count];
    }

    delete [] turtles;

    turtleSize = newTurtleSize;
    turtles = newturtles;
    
}
 
/*******************************************************
** Ages each animal by 1
*******************************************************/
void Zoo::dayAge(int *tigers, int *penguins, int *turtles, int numTigers, int numPenguins, int numTurtles)
{
    int count;

    for (count = 0; count < numTigers; count++)
    {
            tigers[count] = tigers[count] + 1;
    }

    for (count = 0; count < numPenguins; count++)
    {
            penguins[count] = penguins[count] + 1;
    }

    for (count = 0; count < numTurtles; count++)
    {
            turtles[count] = turtles[count] + 1;
    }
}

/******************************************************
** calculates food costs of each animal per animal
** then deducts costs from bank
******************************************************/
void Zoo::foodCosts(int &bank, int &numTigers, int &numPenguins, int &numTurtles)
{
    int food = 10;
    
    int tigFood,
        penFood,
        turFood;

    tigFood = 5 * food;

    penFood = food;

    turFood = (1/2) * food;

    bank = bank - (tigFood * numTigers);

    bank = bank - (penFood * numPenguins);

    bank = bank - (turFood * numTurtles);


}

/*********************************************************
** Places initial animals in the array
*********************************************************/
void Zoo::placeAnimals(int *tigers, int *penguins, int *turtles)
{
    int count;

    for (count = 0; count < numTigers; count++)
    {
        tigers[count] = 1;
    }

    for (count = 0; count < numPenguins; count++)
    {
        penguins[count] = 1;
    }

    for (count = 0; count < numTurtles; count++)
    {
        turtles[count] = 1;
    }
}

/********************************************************************
** Asks and deducts money from the user for the animal they
** would like to purchase.
********************************************************************/
void Zoo::endBuy(int &bank, int &tigerSize, int &penguinSize, int &turtleSize, int &numTigers, int &numPenguins, int &numTurtles, int *tigers, int *penguins, int *turtles)
{
    int checkTiger,
        checkPenguin,
        checkTurtle;
    int newAdult,
        bankersTig,
        bankersPen,
        bankersTur;

    std::cout << "Would you like to buy an adult animal?" << std::endl;

    do
    {
        std::cout << "Press 1 for Tigers, press 2 for Penguins, press 3 for Turtles, press 4 for nothing." << std::endl;
        std::cin >> newAdult;
        std::cin.clear();
        std::cin.ignore(50, '\n');
    }while (newAdult != 1 && newAdult != 2 && newAdult != 3 && newAdult != 4);

    if (newAdult == 1)
    {
        bankersTig = bank - 10000;

        if (bankersTig > 0)
        {
            tigers[numTigers] = 3;
            numTigers = numTigers + 1;
            bank = bank - 10000;
        }

    }
    
    else if (newAdult == 2)
    {
        bankersPen = bank - 1000;

        if (bankersPen > 0)
        {
            penguins[numPenguins] = 3;
            numPenguins = numPenguins + 1;
            bank = bank - 1000;
        }

    }

    else if (newAdult == 3)
    {
        bankersTur = bank - 100;

        if (bankersTur > 0)
        {
            turtles[numTurtles] = 3;
            numTurtles = numTurtles + 1;
            bank = bank - 100;
        }
    }
}

/*****************************************************************
** If bank is not zero or under then asks player to quit or to 
** play again. If zero prints out game over and exits game.
*****************************************************************/
void Zoo::gameOver(int &bank, int &starting)
{
    if (bank > 0)
    {
        do
        {
            std::cout << "Press 1 to play again or Press 2 to exit." << std::endl;
            std::cin >> starting;
            std::cin.clear();
            std::cin.ignore(50, '\n');
        }while (starting != 1 && starting != 2);

        if (starting == 2)
            std::cout << "Game Over." << std::endl;
    }

    else if (bank < 0)
    {
        starting == 2;
        std::cout << "You ran out of money. Game Over." << std::endl;
    }
}


    





 
