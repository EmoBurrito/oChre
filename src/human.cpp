#include "../include/human.h"
#include <vector>
#include <iostream> //Used for I/O
#include <cstdlib> //Used for random number generation
#include <ctime> //Used to access system time, helps random generation

using namespace std;

const vector<vector<string>> Human::MALE_NAMES = {
        vector<string> {"Adrian"},
        vector<string> {"Andrew"},
        vector<string> {"Alexander"},
        vector<string> {"Baz"},
        vector<string> {"Bedros"},
        vector<string> {"Corneille"},
        vector<string> {"Dennifer"},
        vector<string> {"Dick", "Richard"},
        vector<string> {"Gil", "Gillian"},
        vector<string> {"Harrison"},
        vector<string> {"Reggie"},
        vector<string> {"Roderick"},
        vector<string> {"Sal", "Salazar"},
        vector<string> {"Zoltan"}
};

const vector<vector<string>> Human::FEMALE_NAMES = {
        vector<string> {"Abigayle"},
        vector<string> {"Adrianne"},
        vector<string> {"Alexis"},
        vector<string> {"Anna"},
        vector<string> {"Andrea"},
        vector<string> {"Dove"},
        vector<string> {"Ida"},
        vector<string> {"Jill", "Jilian"},
        vector<string> {"Nel"}
};

const vector<vector<string>> Human::ANDROGYNOUS_NAMES = {
        vector<string> {"Alberic"},
        vector<string> {"Ash", "Ashley", "Ashleigh"},
        vector<string> {"Aubrey", "Aubry"},
        vector<string> {"Ora"}
};

const vector<vector<string>> Human::FAMILY_NAMES = {
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

/**
 * Human constructor.
 *
 * We are abandoning the setting of default variables via the colon method because that has issues with inheritance.
 * TODO Move this up to Humanoid or even Creature or hell, even Thing
 */
Human::Human(string name,
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
		this->name = Human::generateName();
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
 *	Human destructor
 *
 *	C++ destructors take no parameters and have no return type. Not even void.
 *	Cannot be overloaded.
 */
Human::~Human()
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
string Human::generateNameFirst(char sex) {
    if (sex == 'm')
    {
        //Get Sub-vector
        vector<string> sub_vector = MALE_NAMES[rand()%MALE_NAMES.size()];
        //Get name from sub-vector
        return sub_vector[rand()%sub_vector.size()];
    }
    else if (sex == 'f')
    {
        vector<string> sub_vector = FEMALE_NAMES[rand()%FEMALE_NAMES.size()];
        return sub_vector[rand()%sub_vector.size()];
    }
    else
    {
        vector<string> sub_vector = ANDROGYNOUS_NAMES[rand()%ANDROGYNOUS_NAMES.size()];
        return sub_vector[rand()%sub_vector.size()];
    }
}
/**
 * generateName helper method. Generates last name.
 *
 * Overrides virtual method in parent.
 */
string Human::generateNameLast() {
    vector<string> sub_vector = FAMILY_NAMES[rand()%FAMILY_NAMES.size()];
    return sub_vector[rand()%sub_vector.size()];
}
