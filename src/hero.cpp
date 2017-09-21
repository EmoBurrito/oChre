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
    string first;
    string last;
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
     * generateName helper method. Generates first name. If you have contributed, feel free to add your name.
     *
     * The names are sorted first into genders, then into spellings of. This is to prevent multiple spellings of one
     * name to become increasingly popular. For example, supposed we had Aubrey, Aubry, John, and Tom. This would mean
     * that half of the given population would be named some form of Aubrey. By doing it this way, we are making it so
     * that 1/3rd of the population is named Aubrey and then half of all Aubreys are spelled one way. while the other
     * half are spelled the other.
     *
     * Spellings of names alphabetically, and then vectors are sorted alphabetically based on sub-vectors first bucket.
     *
     * TODO: Separate based on race.
     * TODO: Force sex to lower case.
     */
    if (sex == 'm')
    {
        vector<vector<string>> male_names = {
                vector<string> {"Adrian"},
                vector<string> {"Andrew"},
                vector<string> {"Alexander"},
                vector<string> {"Baz"},
                vector<string> {"Bedros"},
                vector<string> {"Corneille"},
                vector<string> {"Dennifer"},
                vector<string> {"Harrison"},
                vector<string> {"Reggie"},
                vector<string> {"Roderick"},
                vector<string> {"Sal"},
                vector<string> {"Zoltan"}
        };

        //Get Sub-vector
        vector<string> sub_vector = male_names[rand()%male_names.size()];
        //Get name from sub-vector
        return sub_vector[rand()%sub_vector.size()];
    }
    else if (sex == 'f')
    {
        vector<vector<string>> female_names = {
                vector<string> {"Abigayle"},
                vector<string> {"Adrianne"},
                vector<string> {"Alexis"},
                vector<string> {"Anna"},
                vector<string> {"Andrea"},
                vector<string> {"Dove"},
                vector<string> {"Ida"},
                vector<string> {"Nel"}
        };

        vector<string> sub_vector = female_names[rand()%female_names.size()];
        return sub_vector[rand()%sub_vector.size()];
    }
    else
    {
        vector<vector<string>> neutral_names = {
                vector<string> {"Alberic"},
                vector<string> {"Ash"},
                vector<string> {"Aubrey", "Aubry"},
                vector<string> {"Ora"}
        };

        vector<string> sub_vector = neutral_names[rand()%neutral_names.size()];
        return sub_vector[rand()%sub_vector.size()];
    }
}

string Hero::generateNameLast() {
    /**
     * generateName helper method. Generates last name.
     *
     * TODO: Separate based on race.
     */
    vector<vector<string>> last_names = {
            vector<string> {"Abbadelli"},
            vector<string> {"Altoviti"},
            vector<string> {"Berger"},
            vector<string> {"Bosco"},
            vector<string> {"Chaudhri"},
            vector<string> {"Nelli"},
            vector<string> {"Norris"},
            vector<string> {"Sempers"},
            vector<string> {"September"},
            vector<string> {"Thomas"},
            vector<string> {"Trask"},
    };
    vector<string> sub_vector = last_names[rand()%last_names.size()];
    return sub_vector[rand()%sub_vector.size()];
}

string Hero::generateNameCompound() {
    /**
     * generateName helper method. Generates a compound last name.
     */

    vector<vector<string>> first = {
        vector<string> {"Chicken"},
        vector<string> {"Light"},
        vector<string> {"Falcon"},
        vector<string> {"Finger"},
        vector<string> {"Hawk"},
        vector<string> {"Mc"},
        vector<string> {"Mac"},
        vector<string> {"Nerf"},
        vector<string> {"O'"},
        vector<string> {"Pig"},
        vector<string> {"Rock"},
        vector<string> {"Stone"}
    };
    vector<vector<string>> second = {
        vector<string> {"bringer"},
        vector<string> {"fists"},
        vector<string> {"foot"},
        vector<string> {"fucker"},
        vector<string> {"hand"},
        vector<string> {"haver"},
        vector<string> {"herder"},
        vector<string> {"holder"},
        vector<string> {"licker"},
        vector<string> {"smasher"}
    };

    vector<string> sub_first = first[rand()%first.size()];
    vector<string> sub_second = second[rand()%second.size()];
    return sub_first[rand()%sub_first.size()] + sub_second[rand()%sub_second.size()];
}