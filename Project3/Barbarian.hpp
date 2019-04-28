#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Characters.hpp"
#include <string>

class Barbarian : public Characters
{
    public:
        /************************************
        ** Constructor that sets variables
        ************************************/
        Barbarian();

        /************************************
        ** Deconstructor
        ************************************/
        ~Barbarian();

        /******************************
        ** Rolls attack for Barbarian
        ******************************/
        void rollAttack();

        /******************************
        ** Rolls defense for barbarian
        ******************************/
        void rollDefense();

        /***********************************
        ** Function that calculates attack
        ** damage
        ***********************************/
        int Attack(Characters*);

        /**********************************
        ** Function that calculates defense
        ** and calculates damage dealt
        **********************************/
        int Defense(int);
};
#endif
