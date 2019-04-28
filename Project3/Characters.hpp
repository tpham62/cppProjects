#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP
#include <iostream>
#include <string>

class Characters
{
    public:

        /*****************************
        ** Constructor
        *****************************/
        Characters();

        /********************************
        ** Deconstructor
        ********************************/
        ~Characters();

        /***************************************
        ** Virtual attack function that
        ** calculates attack damage
        ***************************************/
        virtual int Attack(Characters*);

        /***************************************
        ** Virtual defense function that
        ** calculates damage dealt
        ** and remaining health
        **************************************/
        virtual int Defense(int);

        /***********************************
        ** Sets attack
        ***********************************/
        void setAttack(int);

        /***********************************
        ** Sets defense
        ***********************************/
        void setDefense(int);

        /***********************************
        ** Sets strength
        ***********************************/
        void setStrength(int);

        virtual void rollAttack();

        virtual void rollDefense();

        /*********************************
        ** Gets attack
        *********************************/
        int getAttack();

        /***********************************
        ** Gets defense
        ***********************************/
        int getDefense();

        /*******************************
        ** Gets armor
        *******************************/
        int Armor();

        /********************************
        ** Gets hit points or strength
        ** points
        ********************************/
        int StrengthPoints();

        /********************************
        ** Gets type aka name
        ********************************/
        std::string getType();

    /********************************************
    ** Variables that are manipulated by
    ** each inherited class's constructor
    ********************************************/
    protected:
        int charAttack;
        int charDefense;
        int charArmor;
        int charStrength;
        std::string charType;
        int Counter;
};
#endif
