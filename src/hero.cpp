/*!
	\class Hero
*/

#include "hero.h"
#include <iostream> //Used for I/O
#include <cstdlib> //Used for random number generation
#include <ctime> //Used to access system time, helps random generation

using namespace std;

//The constructor. A method automatically called when a new Hero is instantiated
Hero::Hero(string name, int health, int strength)
{
	this->name = name;
	this->health = health;
	this->strength = strength;
};

//TODO & gets the address of, but "this" uses pointers... Consider reworking for consistency sake
void Hero::attack(Hero &target)
{
	//Roll 0 or 1. If 1, hit. Else, miss (do nothing)
	srand(time(0)); //Seeds the random generation with the current system time
	if (rand()%2 == 1)
	{
		target.ouch(this->getStrength());
		cout << this->getName() << " hit " << target.getName() << " for " << this->getStrength() << "\n";
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

string generateName(char sex)
{
	string name;
	srand(time(0));

	//TODO Force sex to lower case
	if (sex == 'm')
	{
		switch (rand()%6) //Mod number of male names
		{
			case 0: name="Reggie"; break;
			case 1: name="Harrison"; break;
			case 2: name="Sal"; break;
			case 3: name="Baz"; break;
			case 4: name="Bedros"; break;
			case 5: name="Corneille"; break;
			default: name="Masculine";
		}
	}
	else if (sex == 'f')
	{
		switch (rand()%4) //Mod number of female names
		{
			case 0: name="Nel"; break;
			case 1: name="Abigayle"; break;
			case 2: name="Anna"; break;
			case 3: name="Ida"; break;
			default: name="Femme";
		}
	}
	else
	{
		switch (rand()%1) //Mod number of male names
		{
			case 0: name="Ora"; break;
			default: name="Neutral";
		}
	}

	//Append last name
	switch (rand()%11) //Mod number of male names
	{
		case 0: name=" September"; break;
		case 1: name=" Berger"; break;
		case 2: name=" Trask"; break;
		case 3: name=" Bosco"; break;
		case 4: name=" Chaudhri"; break;
		case 5: name=" Norris"; break;
		case 6: name=" Sempers"; break;
		case 7: name=" Altoviti"; break;
		case 8: name=" Abbadelli"; break;
		case 9: name=" Thomas"; break;
		case 10: name=" Nelli"; break;
		default: name=" Name";
	}

	return name;
}
