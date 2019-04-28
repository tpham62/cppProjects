#ifndef ZOO_HPP
#define ZOO_HPP

class Zoo
{
    public:
        int numTigers,
            numPenguins,
            numTurtles,
            tigerSize,
            penguinSize,
            turtleSize,
            bank;

        /*******************************
        ** Constructor
        *******************************/
        Zoo();
        
        /*****************************
        ** Deconstructor
        *****************************/
        ~Zoo();

        /******************************************
        ** Function that checks tiger age
        ******************************************/
        void checkTigerAge(int&, int&, int&, int*);

        /*********************************************
        ** Function that checks penguin age
        *********************************************/
        void checkPenguinAge(int&, int&, int&, int*);

        /********************************************
        ** Function that checks turtle age
        ********************************************/
        void checkTurtleAge(int&, int&, int&, int*);

        /********************************************
        ** Function that pays player per animal
        ********************************************/
        void animalPayOff(int&, int&, int&, int&);

        /***************************************************
        ** function of a random number generated for event
        ***************************************************/
        void randomNumber(int&);

        /*********************************************
        ** Function that deducts animal costs intially
        *********************************************/
        void animalCosts(int&);

        /*******************************************************
        ** Function that kills off an animal
        *******************************************************/
        void sicknessAnimals(int&, int&, int&, int*, int*, int*);

        /******************************************************
        ** Funciton that pays player based on tigers owned
        ******************************************************/
        void boomAnimals(int&, int);

        /******************************************************
        ** Function that adds a baby tiger
        ******************************************************/
        void tigerBorn(int&, int*);

        /***********************************************************
        ** Function that adds 5 baby penguins.
        ***********************************************************/
        void penguinBorn(int&, int*);

        /**********************************************************
        ** Function that adds 10 baby turtles
        **********************************************************/
        void turtleBorn(int&, int*);

        /**********************************************
        ** Function that resizes tiger array
        **********************************************/
        void reSizeTiger(int&, int*&);

        /************************************************
        ** Function that resizes penguin array
        ************************************************/
        void reSizePenguin(int&, int*&);

        /**********************************************
        ** Function that resizes turtle array
        **********************************************/
        void reSizeTurtle(int&, int*&);
        
        /*******************************************
        ** Function that ages animals
        *******************************************/
        void dayAge(int*, int*, int*, int, int, int);

        /************************************************
        ** Function that deducts food costs from player
        ************************************************/
        void foodCosts(int&, int&, int&, int&);

        /*******************************************
        ** Places animals in array
        *******************************************/
        void placeAnimals(int*, int*, int*);

        /*************************************************
        ** Asks and deducts money from player depending
        ** on what animal they choose to buy
        *************************************************/
        void endBuy(int&, int&, int&, int&, int&, int&, int&, int*, int*, int*);

        /****************************************************
        ** Function that asks if player wants to quit
        ** start again or tell them they are out of money
        ****************************************************/
        void gameOver(int&, int&);
        
};
#endif
