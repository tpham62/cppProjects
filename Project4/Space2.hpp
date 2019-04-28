#ifndef SPACE_HPP
#define SPACE_HPP
#include "Fighter.hpp"
#include <string>

class Fighter;

class Space
{
    protected:

        /***************************************
        ** Variables and space objects
        ***************************************/
        std::string curSpace;
        std::string curInfo;
        Space* North;
        Space* South;
        Space* East;
        Space* West;
        bool orcEnemy;

    public:

        /*********************************
        ** Constructor intializes 
        ** directions
        *********************************/
        Space();

        /*********************************
        ** Destructor
        *********************************/
        ~Space();

        /**********************************
        ** Sets direction according to
        ** space
        **********************************/
        void setDirection(Space*, Space*, Space*, Space*);
        
        /*************************************
        ** Get space string
        *************************************/
        std::string getSpace();

        /***********************************
        ** Get info string
        ***********************************/
        std::string getInfo();

        /**************************************
        ** Set space variable
        **************************************/
        void setSpace(std::string);

        /*************************************
        ** Moves player using direction 
        ** according to space
        *************************************/
        void movePlayer(Fighter*);

        /**************************************
        ** Virtual void function that
        ** prompts questions and prompts
        **************************************/
        virtual void fightMonster(Fighter*);
};
#endif
