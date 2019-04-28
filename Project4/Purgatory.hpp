#ifndef PURGATORY_HPP
#define PURGATORY_HPP
#include "Space2.hpp"
#include "Fighter.hpp"

class Purgatory : public Space
{
    public:
        /*****************************
        ** Constructor initializes
        ** string and counter
        *****************************/
        Purgatory();

        /**************************
        ** Destructor
        **************************/
        ~Purgatory();
        
        /***************************
        ** Displays questions
        ***************************/
        void fightMonster(Fighter*);

        /**************************
        ** Counter variable
        **************************/
        bool finPurg;

        /*************************
        ** Step counter
        *************************/
        int purgCount;
};
#endif
