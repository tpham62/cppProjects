#ifndef MOUNTAIN_HPP
#define MOUNTAIN_HPP
#include "Space2.hpp"
#include "Fighter.hpp"

class Mountain : public Space
{
    public:

        /***************************
        ** Constructor initializes
        ** strings and counter
        ***************************/
        Mountain();

        /***************************
        ** Destructor
        ***************************/
        ~Mountain();

        /*********************************
        ** Displays questions and prompts
        *********************************/
        void fightMonster(Fighter*);

        /*******************************
        ** Counter variable
        *******************************/
        bool finMount;
};
#endif
