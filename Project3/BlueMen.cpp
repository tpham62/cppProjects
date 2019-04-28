#include <iostream>
#include <cstdlib>
#include "BlueMen.hpp"
#include "Characters.hpp"

/*******************************************************
** Constructor that sets attack, defense, armor,
** strength, and type of the BlueMen object.
** Inherits the character class
*******************************************************/
BlueMen::BlueMen() : Characters()
{
    this->charAttack = 0;
    this->charDefense = 0;
    this->charArmor = 3;
    this->charStrength = 12;
    this->charType = "BlueMen";
}

/***************************************
** Rolls attack damage for bluemen
***************************************/
void BlueMen::rollAttack()
{
    int attacks;

    attacks = 1 + rand() % 10;

    attacks = attacks + (1 + rand() % 10);

    this->setAttack(attacks);
}

/******************************************
** Rolls defense for bluemen based
** on strength points
******************************************/
void BlueMen::rollDefense()
{
    int defends;

    /***********************************************
    ** Rolls one dice if strength points is equal
    ** to or less than 4
    ***********************************************/
    if (this->StrengthPoints() <= 4)
    {
        defends = 1 + rand() % 6;

        this->setDefense(defends);
    }

    /*************************************************************
    ** Rolls 2 dice if health is lower or equal to 8
    *************************************************************/
    else if (this->StrengthPoints() <= 8)
    {
        defends = 1 + rand() % 6;

        defends = defends + (1 + rand() % 6);

        this->setDefense(defends);
    }

    /*********************************************************
    ** Sets to roll 3 dice for defense if health is equal to
    ** or less than 12;
    *********************************************************/
    else if (this->StrengthPoints() <= 12)
    {
        defends = 1 + rand() % 6;

        defends = defends + (1 + rand() % 6);

        defends = defends + (1 + rand() % 6);

        this->setDefense(defends);
    }
}


/*****************************************************
** Takes in character object pointer that calculates
** damage dealt.
*****************************************************/
int BlueMen::Attack(Characters* B)
{
    int attacks,
        damageDone;

    attacks = this->getAttack();

    damageDone = B->Defense(attacks);

    return damageDone;

}

/**********************************************************
** Calculates how much damage is dealt to the bluemen
** by calculating defense and subtracting the attack by
** the armor and defense rolled.
**********************************************************/
int BlueMen::Defense(int damage)
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

/*******************************************************
** BlueMen Deconstructor
*******************************************************/
BlueMen::~BlueMen()
{
}
