#include <iostream>
#include <string>
#include "Characters.hpp"

/*******************************************
** Empty constructor
*******************************************/
Characters::Characters()
{
}

/**********************************************
** Virtual attack function that takes in
** character object pointer
**********************************************/
int Characters::Attack(Characters* B)
{
}

/**************************************************
** Virtual defense function that takes in damage
** from the attack parameter from attack function
**************************************************/
int Characters::Defense(int damage)
{
}

void Characters::rollAttack()
{
}

void Characters::rollDefense()
{
}

/**************************************************
** Sets attack variable
**************************************************/
void Characters::setAttack(int attacks)
{
    this->charAttack = attacks;
}

/***********************************************
** Sets defense variable
***********************************************/
void Characters::setDefense(int defenses)
{
    this->charDefense = defenses;
}

/**************************************************
** Sets strengthpoints aka hit points variable
**************************************************/
void Characters::setStrength(int strength)
{
    this->charStrength = strength;
}

/*****************************************
** Gets attack damage roll
*****************************************/
int Characters::getAttack()
{
    return this->charAttack;
}

/*********************************************
** Gets defense roll
*********************************************/
int Characters::getDefense()
{
    return this->charDefense;
}

/*******************************************
** Gets armor number
*******************************************/
int Characters::Armor()
{
    return this->charArmor;
}

/********************************************
** Gets Strength points
********************************************/
int Characters::StrengthPoints()
{
    return this->charStrength;
}

/*******************************************
** Gets type of object pointer
*******************************************/
std::string Characters::getType()
{
    return this->charType;
}

/**********************************
** Character deconstructor
**********************************/
Characters::~Characters()
{
}

