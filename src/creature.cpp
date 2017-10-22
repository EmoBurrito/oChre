#include <string>
#include "../include/creature.h"

using namespace std;

//TODO & gets the address of, but "this" uses pointers... Consider reworking for consistency sake
void Creature::attack(Creature *targetPointer)
/**
 * This is a test brief.
 *
 * This is a test detailed description.
 * It spans multiple lines.
 * \dotfile attack.dot
 */
{
    //TODO Change srand to C++11 random library
    //TODO Base off target's speed rather than flipping a coin
    //Roll 0 or 1. If 1, hit. Else, miss (do nothing)
    srand(time(0)); //Seeds the random generation with the current system time
    if (rand()%2 == 1)
    {
        targetPointer->ouch(this->getStrength());
        cout << this->getName() << " hit " << targetPointer->getName() << " for " << this->getStrength() << "\n";
    } else
    {
        cout << this->getName() << " missed " << targetPointer->getName() << "!\n";
    }
};

void Creature::ouch(int damage)
{
    health -= damage;
};

string Creature::getName()
{
    return name;
};

int Creature::getStrength()
{
    return strength;
};

int Creature::getHealth()
{
    return health;
};




/**
 * Returns a string of a randomly generated name.
 *
 * Used if a name is not supplied.
 */
string Humanoid::generateName(char sex)
{
    return generateNameFirst(sex) + " " + generateNameLast();
}