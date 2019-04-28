#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Characters.hpp"
#include <string>

class Medusa : public Characters
{
    public:

        /*****************************************************
        ** Constructor that sets variables
        *****************************************************/
        Medusa();

        /***************************************
        ** Deconstructor
        ***************************************/
        ~Medusa();

        /***************************************
        ** Rolls attack damage for medusa
        ***************************************/
        void rollAttack();

        /******************************************
        ** Rolls defense for medusa
        ******************************************/
        void rollDefense();

        /***************************************
        ** Calculates attack damage and sets
        ** attack damage
        ***************************************/
        int Attack(Characters*);

        /*******************************************************
        ** calculates defense and how much damage is dealt
        ** and subtracts how much health is lost
        *******************************************************/
        int Defense(int);
};
#endif
