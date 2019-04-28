#ifndef UNDERWORLD_HPP
#define UNDERWORLDJ_HPP
#include "Space2.hpp"
#include "Fighter.hpp"

class Underworld : public Space
{
    public:
        
        /********************************
        ** Constructor that initializes
        ** strings and counter
        ********************************/
        Underworld();

        /********************************
         ** Destructor
         *******************************/
        ~Underworld();

        /****************************************
        ** Displays questions and prompts
        ****************************************/
        void fightMonster(Fighter*);

        /********************************
        ** Counter variable
        ********************************/
        bool finUnder;
};
#endif
