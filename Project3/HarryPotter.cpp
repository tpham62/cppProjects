#include <iostream>
#include "HarryPotter.hpp"
#include "Characters.hpp"
#include <string>
#include <cstdlib>

/**************************************************************
** Constructor that sets attack, defense, strength,
** type, and counter for how many times harry potter has died.
** inherits character class
**************************************************************/
HarryPotter::HarryPotter() : Characters()
{
    this->charAttack = 0;
    this->charDefense = 0;
    this->charStrength = 10;
    this->charType = "HarryPotter";
    this->Counter = 0;
}

/*************************************************
** Rolls attack damage for Harry potter
*************************************************/
void HarryPotter::rollAttack()
{
    int attacks;

    attacks = 1 + rand() % 6;

    attacks = attacks + (1 + rand() % 6);

    this->setAttack(attacks);
}

/********************************************
** Rolls defense for Harry Potter
********************************************/
void HarryPotter::rollDefense()
{
    int defends;

    defends = 1 + rand() % 6;

    defends = defends + (1 + rand() % 6);

    this->setDefense(defends);
}

/*********************************************************
** Takes in character object pointer and calculates 
** damage done
*********************************************************/
int HarryPotter::Attack(Characters* B)
{
    int attacks,
        damageDone;

    attacks = this->getAttack();

    damageDone = B->Defense(attacks);

    return damageDone;
}

/*************************************************************
** Calculates how
** much damage is dealt to the defender by subtracting defense
** and armor by the damage. If harry potter dies he is revived
** and counter is increased by 1. While increasing his life
** by 20
*************************************************************/
int HarryPotter::Defense(int damage)
{
    int health,
        defends;

    defends = this->getDefense();

    damage = damage - (defends + 0);

    if (damage > 0)
    {
        health = this->StrengthPoints() - damage;

        this->setStrength(health);

        if (health <= 0 && Counter != 1)
        {
            this->Counter = 1;
            health = 20;

            this->setStrength(health);
            std::cout << "Harry Potter died but casted Hogwarts to save himself." << std::endl;
            std::cout << "He now has 20 hit points after damage is dealt." << std::endl;
            return damage;
        }

        else 
        {
            return damage;
        }

    }

    else
    {
        return 0;
    }
}

/************************************************
** Harry Potter deconstructor
************************************************/
HarryPotter::~HarryPotter()
{
}
