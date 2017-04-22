/**
	Hero class, hero.cpp
	Purpose: To server as the blueprint of a hero

	@author Nathan Smith
	@version 0.0.1 Feb 18, '17
*/

#include "hero.h"

//Can be accessed by anyone, from anywhere. 
//The constructor. A method automatically called when a new Hero is instantiated
Hero::Hero(std::string name, int health, int strength)
{
	this->name = name;
	this->health = health;
	this->strength = strength;
};

void Hero::attack(Hero &target)
{
	target.ouch(this->strength);
};

void Hero::ouch(int damage)
{
	health -= damage;
};

std::string Hero::getName()
{
	return name;
};

// std::ostream & operator<<(std::ostream & Str, Hero const & myHero) { 
//   // print something from v to str, e.g: Str << v.getX();
//   return Str;
// }

int Hero::getStrength()
{
	return this->strength;
};

int Hero::getHealth()
{
	return this->health;
};
