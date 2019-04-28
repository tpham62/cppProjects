#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Characters.hpp"
#include <string>

class HarryPotter : public Characters
{
    public:

        /***********************************************
        ** Constructor that sets variables
        ***********************************************/
        HarryPotter();

        /*********************************************
        ** Deconstructor
        *********************************************/
        ~HarryPotter();

        /****************************************
        ** Rolls Attack damage for harry potter
        ****************************************/
        void rollAttack();

        /******************************************
        ** Rolls Defense for harry potter
        ******************************************/
        void rollDefense();

        /*********************************************
        ** Calculates attack damage and sets attack
        ** damage
        *********************************************/
        int Attack(Characters*);

        /**********************************************
        ** Calculates damage dealt and subtracts
        ** health based on damage that was dealt
        **********************************************/
        int Defense(int);
};
#endif
