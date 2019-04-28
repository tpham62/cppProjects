#include <iostream>
#include <string>
#include <cstdlib>
#include "Barbarian.hpp"
#include "Characters.hpp"

/**********************************************
** Constructor that sets attack, defense,
** armor, strength and char type specific
** to barbarian. Also inherits character class
**********************************************/
Barbarian::Barbarian() : Characters()
{
    this->charAttack = 0;
    this->charDefense = 0;
    this->charArmor = 0;
    this->charStrength = 12;
    this->charType = "Barbarian";
}

/***************************************
** Rolls attack damage for Barbarian
***************************************/
void Barbarian::rollAttack()
{
    int attacks;

    attacks = 1 + rand() % 6;

    attacks = attacks + (1 + rand() % 6);

    this->setAttack(attacks);
}

/*************************************
** Rolls defense for barbarian
*************************************/
void Barbarian::rollDefense()
{
    int defends;

    defends = 1 + rand() % 6;

    defends = defends + (1 + rand() % 6);

    this->setDefense(defends);
}

/******************************************************************
** Function that takes in character object pointer that points to
** another monster. Sends damage
** to defense function to calculate how much health will be 
** taken away.
******************************************************************/
int Barbarian::Attack(Characters* B)
{
    int attacks,
        damageDone;

    attacks = this->getAttack();

    damageDone = B->Defense(attacks);

    return damageDone;
}

/***************************************************************
** Function that takes in attack damage from previous function
** subtracts the health of the attacked monster object based on
** the defense dice rolled and armor of the monster defending
***************************************************************/
int Barbarian::Defense(int damage)
{

    int health,
        defends;

    defends = this->getDefense();

    damage = damage - (defends + 0);

    if (damage > 0)
    {
        health = this->StrengthPoints() - damage;

        this->setStrength(health);

        return damage;
    }

    else
    {
        return 0;
    }
}

/*********************************************************
** Barbarian Deconstructor
*********************************************************/
Barbarian::~Barbarian()
{
}
