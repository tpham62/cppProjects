#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Characters.hpp"
#include <string>

class Vampire : public Characters
{
    public:

        /******************************************
        ** Constructor that sets variables
        ******************************************/
        Vampire();

        /********************************************
        ** Deconstructor
        ********************************************/
        ~Vampire();

        /*************************************
        ** Rolls atack damage for vampire
        *************************************/
        void rollAttack();

        /*************************************
        ** Rolls defense for vampire
        *************************************/
        void rollDefense();

        /*******************************************
        ** Calculates attack damage and sets
        ** attack damage
        *******************************************/
        int Attack(Characters*);

        /*******************************************
        ** Calculates defense and calculates how
        ** much damage is dealt and how much 
        ** health is lost
        *******************************************/
        int Defense(int);
};
#endif
