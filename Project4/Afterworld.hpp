#ifndef AFTERWORLD_HPP
#define AFTERWORLD_HPP
#include "Space2.hpp"
#include "Fighter.hpp"

class Afterworld : public Space
{
    public:

        /****************************************
        ** Constor that initializes strings
        ** and counters
        ****************************************/
        Afterworld();

        /***********************************
        ** Destructor
        ***********************************/
        ~Afterworld();

        /***************************************
        ** Displays questions and prompts
        ***************************************/
        void fightMonster(Fighter*);

        /*******************************
        ** Counter variable
        *******************************/
        bool finAfter;
};
#endif
