#include "human.h"
#include <vector>
#include <iostream> //Used for I/O
#include <cstdlib> //Used for random number generation
#include <ctime> //Used to access system time, helps random generation

using namespace std;

/**
 * Human constructor.
 *
 * We are abandoning the setting of default variables via the colon method becuase that has issues with inheritance.
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
 * Returns a string of a randomly generated name.
 *
 * Used if a name is not supplied.
 */
string Human::generateName(char sex)
{
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
string Human::generateNameFirst(char sex) {
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
            vector<string> {"Dick", "Richard"},
		    vector<string> {"Gil", "Gillian"},
            vector<string> {"Harrison"},
            vector<string> {"Reggie"},
            vector<string> {"Roderick"},
            vector<string> {"Sal", "Salazar"},
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
		    vector<string> {"Jill", "Jilian"},
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
/**
 * generateName helper method. Generates last name.
 *
 * TODO: Separate based on race.
 */
string Human::generateNameLast() {
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

/**
 * generateName helper method. Generates a compound last name.
 */
string Human::generateNameCompound() {
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
