#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Characters.hpp"
#include <string>

class BlueMen : public Characters
{
    public:

        /*************************************
        ** Constructor that sets variables
        *************************************/
        BlueMen();

        /***********************************
        ** Deconstructor
        ***********************************/
        ~BlueMen();

        /****************************************
        ** Rolls attack damage for bluemen
        ****************************************/
        void rollAttack();

        /*************************************
        ** Rolls defense for bluemen
        *************************************/
        void rollDefense();

        /*************************************
        ** Rolls and Calculates attack
        ** from the character object pointer
        *************************************/
        int Attack(Characters*);

        /************************************
        ** Calculates damage dealt and
        ** subtracts the health of the
        ** defender
        ************************************/
        int Defense(int);
};
#endif
