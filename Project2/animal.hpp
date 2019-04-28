#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
    public:
        int age,
            cost,
            babies,
            food,
            pay;

        /*******************************
        ** Constructor
        *******************************/
        Animal(int, int, int, int, int);
        
        /*****************************
        ** Function that gets age
        *****************************/
        int getAge();

        /*******************************
        ** Function that gets age
        *******************************/
        int getCost();

        /*********************************
        ** Function that gets babies
        *********************************/
        int getBabies();

        /*********************************
        ** Function that gets food costs
        *********************************/
        int getFoodCosts();

        /*********************************
        ** Function that gets payoff
        *********************************/
        int getPayOff();
};

#endif
