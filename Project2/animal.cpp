#include <iostream>
#include "animal.hpp"

/*****************************************
** Constructor that intializes data
*****************************************/
Animal::Animal(int sAge, int sCost, int sBabies, int sFood, int sPay)
{
    this->age = sAge;
    this->cost = sCost;
    this->babies = sBabies;
    this->food = sFood;
    this->pay = sPay;

}

/*********************************
** Function that gets age
*********************************/
int Animal::getAge()
{
    return age;
}

/***************************************
** Function that gets cost
***************************************/
int Animal::getCost()
{
    return cost;
}

/***************************************
** Funciton that gets babies
***************************************/
int Animal::getBabies()
{
    return babies;
}

/***********************************
** Function that gets food cost
***********************************/
int Animal::getFoodCosts()
{
    return food;
}

/***************************************
** Function that gets pay off
***************************************/
int Animal::getPayOff()
{
    return pay;
}

        
        

    
