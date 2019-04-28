#include <iostream>
#include "Medusa.hpp"
#include <string>
#include <cstdlib>
#include "Characters.hpp"

/*************************************************************
** Constructor that sets attack, defense, armor, strength,
** and type while inheriting the character class
*************************************************************/
Medusa::Medusa() : Characters()
{
    this->charAttack = 0;
    this->charDefense = 0;
    this->charArmor = 3;
    this->charStrength = 8;
    this->charType = "Medusa";
}

/***********************************************
** Rolls attack damage for medusa
***********************************************/
void Medusa::rollAttack()
{
    int attacks;

    attacks = 1 + rand() % 6;

    attacks = attacks + (1 + rand() % 6);

    this->setAttack(attacks);
}

/********************************************
** Rolls defense for medusa
********************************************/
void Medusa::rollDefense()
{
    int defends;

    defends = 1 + rand() % 6;

    this->setDefense(defends);
}

/******************************************************
** If roll is a perfect 12 medusa will
** cast an attack that does 99 damage effectively
** killing anyone in one hit. Calculates damage dealt.
******************************************************/
int Medusa::Attack(Characters* B)
{
    int attacks,
        damageDone;

    attacks = this->getAttack();

    if (attacks == 12)
    {
        attacks = 99;

        damageDone = B->Defense(attacks);

        std::cout << "Medusa casted Glare! The opponent is turned into stone." << std::endl;

        return damageDone;
    }

    else
    {
        damageDone = B->Defense(attacks);

        return damageDone;
    }

}

/****************************************************************
** Calculates how much damage is dealt after
** adding up the defense rolled and armor from the attack damage
** roll from the previous function
*****************************************************************/
int Medusa::Defense(int damage)
{
    int health,
        defends;

    defends = this->getDefense();

    damage = damage - (defends + 3);

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

/******************************************
** Medusa deconstructor
******************************************/
Medusa::~Medusa()
{
}

