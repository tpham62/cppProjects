#ifndef FORREST_HPP
#define FORREST_HPP
#include "Space2.hpp"
#include "Fighter.hpp"

class Forrest : public Space
{
    public:

        /*********************************
        ** Constructor that initializes
        ** string and counter
        *********************************/
        Forrest();

        /**********************************
        ** Destructor
        **********************************/
        ~Forrest();

        /*********************************
        ** Displays questions and prompts
        *********************************/
        void fightMonster(Fighter*);

        /*********************************
        ** Counter variable
        *********************************/
        bool finFor;
};
#endif
