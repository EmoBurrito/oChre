/**
	Hero class, hero.cpp
	Purpose: To server as the blueprint of a hero
*/

#include "hero.h"
#include <vector>
#include <iostream> //Used for I/O
#include <cstdlib> //Used for random number generation
#include <ctime> //Used to access system time, helps random generation

using namespace std;

//The constructor. A method automatically called when a new Hero is instantiated
//Using some weird method of setting variables with the colon (Bucky E45)
//This was good for so you didn't have to make a new one before passing it in, you could make it there (E47)
Hero::Hero(string name,
		   int healthParam,
		   int manaParam,
		   int accuracyParam,
		   int strengthParam,
		   int speedParam,
		   int intellectParam,
		   int wisdomParam,
		   int luckParam)
: health(healthParam),
  mana(manaParam),
  strength(strengthParam),
  accuracy(accuracyParam),
  speed(speedParam),
  intellect(intellectParam),
  wisdom(wisdomParam),
  luck(luckParam)
{
	//If a name wasn't provided, generate one
	if (name=="")
	{
		this->name = Hero::generateName();
	}
	else
	{
		this->name = name;
	}

	//Not sure if necessary, begin them naked
	//TODO These will have to be changed to pointers
//	this->head = NULL;
//	this->torso = NULL;
//	this->lHand = NULL;
//	this->rHand = NULL;
};

/*!
 *	\brief Hero destructor
 *
 *	C++ destructors take no parameters and have no return type. Not even void.
 *	Cannot be overloaded.
 */
Hero::~Hero()
{
	cout << "Aww, " << this->name << " died\n";
}

//TODO & gets the address of, but "this" uses pointers... Consider reworking for consistency sake
void Hero::attack(Hero *targetPointer)
/**
 * This is a test brief.
 *
 * This is a test detailed description.
 * It spans multiple lines.
 * \dotfile attack.dot
 */
{
	//TODO Change srand to C++11 random library
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

void Hero::ouch(int damage)
{
	health -= damage;
};

string Hero::getName()
{
	return name;
};

int Hero::getStrength()
{
	return this->strength;
};

int Hero::getHealth()
{
	return this->health;
};

string Hero::generateName(char sex)
{
    /**
     * Returns a string of a randomly generated name.
     *
     * Used if a name is not supplied.
     */
    srand(time(0));
    std::string first;
    std::string last;
    if (rand()%2 == 0)
    {
        first = generateNameFirst(sex);
        last = generateNameLast();
    }
    else
    {
        first = generateNameFirst();
        last = generateNameCompound();
    }

	return first + " " + last;
}

string Hero::generateNameFirst(char sex) {
    /**
     * generateName helper method. Generates first name.
     *
     * TODO: Separate based on race.
     * TODO: Force sex to lower case.
     */
    if (sex == 'm')
    {
        std::vector<std::string> male_names = {
                "Andrew",
                "Alexander",
                "Baz",
                "Bedros",
                "Corneille",
                "Dennifer",
                "Harrison",
                "Reggie",
                "Roderick",
                "Sal",
                "Zoltan"
        };

        return male_names[rand()%male_names.size()];
    }
    else if (sex == 'f')
    {
        std::vector<std::string> female_names = {
                "Abigayle",
                "Alexis",
                "Anna",
                "Andrea",
                "Dove",
                "Ida",
                "Nel"
        };

        return female_names[rand()%female_names.size()];
    }
    else
    {
        std::vector<std::string> neutral_names = {
                "Adrian",
                "Ash",
                "Aubrey",
                "Ora"
        };

        return neutral_names[rand()%neutral_names.size()];
    }
}

string Hero::generateNameLast() {
    /**
     * generateName helper method. Generates last name.
     *
     * TODO: Separate based on race.
     */
    std::vector<std::string> last_names = {
            "Abbadelli",
            "Altoviti",
            "Berger",
            "Bosco",
            "Chaudhri",
            "Nelli",
            "Norris",
            "Sempers",
            "September",
            "Thomas",
            "Trask",
    };
    return last_names[rand()%last_names.size()];
}

string Hero::generateNameCompound() {
    /**
     * generateName helper method. Generates a compound last name.
     */

    std::vector<std::string> first = {
        "Chicken",
        "Light",
        "Falcon",
        "Finger",
        "Hawk",
        "Rock",
        "Stone"
    };
    std::vector<std::string> second = {
        "bringer",
        "foot",
        "fucker",
        "hand",
        "haver",
        "holder",
        "smasher"
    };

    return first[rand()%first.size()] + second[rand()%second.size()];
}