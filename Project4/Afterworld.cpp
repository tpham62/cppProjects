#include "Afterworld.hpp"
#include "Space2.hpp"
#include "Fighter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/***********************************************************
** Initiates name of place and sets counter to check
** if the traveler has been here.
***********************************************************/
Afterworld::Afterworld() : Space()
{
    this->curSpace = "Afterworld";
    this->curInfo = "The Afterworld... after all this time you have finally came to rest.";
    this->finAfter = false;
}

/************************************************************************
** Function that displays info and checks if user has collected
** a certain amount of items to display the full ending or the lesser
** endings.
************************************************************************/
void Afterworld::fightMonster(Fighter* f)
{
    int userInput;
    int yourselfTest;

    std::cout << this->getSpace() << std::endl;

    std::cout << this->getInfo() << std::endl;
    
    std::cout << "You see yourself in the midst of things. It looks straight at you." <<std::endl;

    /**********************************************
    ** Checks if user has acquired said items
    **********************************************/
    if (f->getSkull() == true && f->getWisp() == true && f->getCrystal() == true)
    {
        std::cout << "The image of yourself points to your bag. You pull out all your items." << std::endl;
        std::cout << "The skull glows, shining brighter and brighter until you see. The image of yourself. You realize that skull was yours. You passed away in a field that is now a graveyard. The wisp flows into the skull as the crystal shines. In one big explosion you disappear within the light." << std::endl;
        std::cout << "You realize that you are now complete. You have found your soul, spirit and body, you can now lay at rest once and for all." << std::endl;
        f->setAlive(false);
    }

    else if(f->getSkull() == false && f->getWisp() == true && f->getCrystal() == true)
    {
        std::cout << "The image of yourself gets closer and your crystal glows in your bag. The closer the image of you gets brighter the crystal glows. As your image approaches you. You notice the wisp has disappeared. Your image smiles at you as the crystal disappears. You have found your soul and spirit. You fade away in a warm light." << std::endl;
        f->setAlive(false);
    }

    else if (f->getSkull() == true && f->getWisp() == true && f->getCrystal() == false)
    {
        std::cout << "The image of yourself looks at you and smiles. The wisp flies into the skull as your skull eyes start to shine. The skull turns into an image of yourself as the image you were looking at disappear. You notice you are fading as your soul and body start to disappear together. You smile as your journey ends." << std::endl;
        f->setAlive(false);
    }

}

/************************************
** Destructor
************************************/
Afterworld::~Afterworld()
{
}

