#include "../include/dwarf.h"
#include <vector>
#include <iostream> //Used for I/O
#include <cstdlib> //Used for random number generation
#include <ctime> //Used to access system time, helps random generation

using namespace std;

const vector<string> Dwarf::MALE_NAMES = {
        "Imadwarflol"
};

const vector<string> Dwarf::FEMALE_NAMES = {
        "Imadwarflol"
};

const vector<string> Dwarf::ANDROGYNOUS_NAMES = {
        "Imadwarflol"
};

const vector<string> Dwarf::FAMILY_NAMES1 = {
		"Chicken",
        "Light",
        "Falcon",
        "Finger",
        "Hawk",
        "Mc",
        "Mac",
        "Nerf",
        "O'",
        "Pig",
        "Rock",
        "Stone"
};

const vector<string> Dwarf::FAMILY_NAMES2 = {
		"bringer",
        "fists",
        "foot",
        "fucker",
        "hand",
        "haver",
        "herder",
        "holder",
        "licker",
        "smasher"
};

/**
 * Dwarf constructor.
 *
 * We are abandoning the setting of default variables via the colon method because that has issues with inheritance.
 * TODO Move this up to Humanoid or even Creature or hell, even Thing
 */
Dwarf::Dwarf(string name,
		   int health,
		   int mana,
		   int accuracy,
		   int strength,
		   int speed,
		   int intellect,
		   int wisdom,
		   int luck) {
	this->health = health;
	this->mana = mana;
	this->accuracy = accuracy;
	this->strength = strength;
	this->speed = speed;
	this->intellect = intellect;
	this->wisdom = wisdom;
	this->luck = luck;
	//If a name wasn't provided, generate one
	if (name=="")
	{
		//TODO Do I need to specify the class, since it's in Humanoid?
		this->name = Dwarf::generateName();
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

/**
 *	Dwarf destructor
 *
 *	C++ destructors take no parameters and have no return type. Not even void.
 *	Cannot be overloaded.
 */
Dwarf::~Dwarf()
{
	cout << "Aww, " << name << " died\n";
}



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
 * TODO: Force sex to lower case.
 */
string Dwarf::generateNameFirst(char sex) {
    srand(time(0));
    if (sex == 'm')
    {
        return MALE_NAMES[rand()%MALE_NAMES.size()];
    }
    else if (sex == 'f')
    {
        return FEMALE_NAMES[rand()%FEMALE_NAMES.size()];
    }
    else
    {
        return ANDROGYNOUS_NAMES[rand()%ANDROGYNOUS_NAMES.size()];
    }
}
/**
 * generateName helper method. Generates last name.
 *
 * Overrides virtual method in parent.
 */
string Dwarf::generateNameLast() {
    return FAMILY_NAMES1[rand()%FAMILY_NAMES1.size()] + FAMILY_NAMES2[rand()%FAMILY_NAMES2.size()];
}

//    vector<string> sub_first = first[rand()%first.size()];
//    vector<string> sub_second = second[rand()%second.size()];
//    return sub_first[rand()%sub_first.size()] + sub_second[rand()%sub_second.size()];
//}
