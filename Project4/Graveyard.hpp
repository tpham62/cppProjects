#ifndef GRAVEYARD_HPP
#define GRAVEYARD_HPP
#include "Space2.hpp"
#include "Fighter.hpp"

class Graveyard : public Space
{
    public:

        /*******************************
        ** Constructor intializes
        ** strings and counters
        *******************************/
        Graveyard();

        /******************************
        ** Destructor
        ******************************/
        ~Graveyard();

        /*************************************
        ** Displays questions and prompt
        *************************************/
        void fightMonster(Fighter*);

        /*********************************
        ** Counter var8iable
        *********************************/
        bool finGrave;
};
#endif
