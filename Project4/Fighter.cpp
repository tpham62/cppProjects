#include "Fighter.hpp"
#include <vector>
#include <string>
#include <iostream>

/***********************************************
** Initializes items to false and counter to 0
***********************************************/
Fighter::Fighter()
{
    this->skull = false;
    this->crystal = false;
    this->wisp = false;
    this->alive = true;
    this->axe = false;
    this->flute = false;
    this->fist = false;
    this->soul = false;
    this->orcEnemy = false;
    this->counter = 0;
}

/****************************************
** Adds item to the vector
****************************************/
void Fighter::addItem(std::string stuff)
{
    this->bag.push_back(stuff);
    std::cout << "You have stored " << stuff << " in your bag." << std::endl;
}

/****************************************
** Set current space object
****************************************/
void Fighter::setcurSpace(Space* s)
{
    this->fighterSpace = s;
}

/*******************************
** Get current space object
*******************************/
Space* Fighter::getcurSpace()
{
    return this->fighterSpace;
}

/***********************************
** Sets axe variable
***********************************/
void Fighter::setAxe(bool a)
{
    this->axe = a;
}

/************************************
** Set flute variable
************************************/
void Fighter::setFlute(bool a)
{
    this->flute = a;
}

/**********************************
** Set fist variable
**********************************/
void Fighter::setFist(bool a)
{
    this->fist = a;
}

/***************************************
** Set crystal variable
***************************************/
void Fighter::setCrystal(bool a)
{
    this->crystal = a;
}

/*************************************
** Set wisp variable
*************************************/
void Fighter::setWisp(bool a)
{
    this->wisp = a;
}

/***********************************
** Set skull variable
***********************************/
void Fighter::setSkull(bool a)
{
    this->skull = a;
}

/********************************
** Set alive variable
********************************/
void Fighter::setAlive(bool a)
{
    this->alive = a;
}

/********************************
** Get axe variable
********************************/
bool Fighter::getAxe()
{
    return this->axe;
}

/*******************************
** Get flute variable
*******************************/
bool Fighter::getFlute()
{
    return this->flute;
}

/****************************
** Get fist variable
****************************/
bool Fighter::getFist()
{
    return this->fist;
}

/********************************
** Get Crystal variable
********************************/
bool Fighter::getCrystal()
{
    return this->crystal;
}

/********************************
** Get wisp variable
********************************/
bool Fighter::getWisp()
{
    return this->wisp;
}

/********************************
** Get skull variable
********************************/
bool Fighter::getSkull()
{
    return this->skull;
}

/*********************************
** Get alive variable
*********************************/
bool Fighter::getAlive()
{
    return this->alive;
}

/******************************
** Destructor
******************************/
Fighter::~Fighter()
{
}
