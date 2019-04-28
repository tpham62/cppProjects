#ifndef FIGHTER_HPP
#define FIGHTER_HPP
#include "Space2.hpp"
#include <vector>
#include <string>

class Space;

class Fighter
{
    public:

        /*****************************************
        ** Initializes variables and vector
        *****************************************/
        bool alive;
        bool axe;
        bool flute;
        bool fist;
        bool soul;
        bool crystal;
        bool wisp;
        bool skull;
        bool orcEnemy;
        int counter;
        std::vector<std::string> bag;
        Space* fighterSpace;

        /******************************************
        ** Constructor that sets variables
        ******************************************/
        Fighter();

        /********************************************
        ** Deconstructor
        ********************************************/
        ~Fighter();

        /*************************************
        ** Sets axe variable
        *************************************/
        void setAxe(bool);

        /*********************************
        ** Sets flute variable
        *********************************/
        void setFlute(bool);

        /****************************
        ** Set fist variable
        ****************************/
        void setFist(bool);

        /*****************************
        ** Set crystal variable
        *****************************/
        void setCrystal(bool);

        /***************************
        ** Set wisp variable
        ***************************/
        void setWisp(bool);

        /****************************
        ** Set Skull variable
        ****************************/
        void setSkull(bool);

        /**************************
        ** Set alive variable
        **************************/
        void setAlive(bool);

        /***************************
        ** Get axe variable
        ***************************/
        bool getAxe();

        /***************************
        ** Get fist variable
        ***************************/
        bool getFist();

        /*************************
        ** Get flute variable
        *************************/
        bool getFlute();

        /**************************
        ** Get Crystal variable
        **************************/
        bool getCrystal();

        /**************************
        ** Get wisp variable
        **************************/
        bool getWisp();

        /***************************
        ** Get skull variable
        ***************************/
        bool getSkull();

        /************************
        ** Get alive variable
        ************************/
        bool getAlive();

        /******************************
        ** Set Space object
        ******************************/
        void setcurSpace(Space*);

        /******************************
        ** Get space object
        ******************************/
        Space* getcurSpace();

        /*********************************
        ** Add item to vector
        *********************************/
        void addItem(std::string);

};
#endif
