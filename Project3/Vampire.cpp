#include "Vampire.hpp"
#include "Characters.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/**********************************************
** Constructor that sets attack, defense,
** armor, strength and char type specific
** to vampire
** Also inherits character class
**********************************************/
Vampire::Vampire() : Characters()
{
    this->charAttack = 0;
    this->charDefense = 0;
    this->charArmor = 1;
    this->charStrength = 18;
    this->charType = "Vampire";
}

/***************************************
** Rolls attack damage for vampire
***************************************/
void Vampire::rollAttack()
{
    int attacks;

    attacks = 1 + rand() % 12;

    this->setAttack(attacks);
}

/**************************************
** Rolls defense for vampire
**************************************/
void Vampire::rollDefense()
{
    int defends;

    defends = 1 + rand() % 6;

    this->setDefense(defends);
}

/*****************************************************
** Uses polymorphism of chracters member function 
** that takes in the character object pointer and
** calculates damage dealt.
*****************************************************/
int Vampire::Attack(Characters* B)
{
    int attacks,
        damageDone;

    attacks = this->getAttack();

    damageDone = B->Defense(attacks);

    return damageDone;
}

/*************************************************************
** Calculates if someone is charmed and subtracts the attack
** roll from the defense roll and armor.
*************************************************************/
int Vampire::Defense(int damage)
{
    int charm,
        health,
        defends;

        defends = this->getDefense();
        charm = 1 + rand() % 2;

        damage = damage - (defends + 1);

        if (charm == 1)
        {
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
        else
        {
            std::cout << "Vampire casted charm! You do zero damage now." << std::endl;
            return 0;
        }

}

/******************************************************
** Vampire deconstructor
******************************************************/
Vampire::~Vampire()
{
}
        




