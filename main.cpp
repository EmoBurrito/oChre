#include <iostream>
#include <string>
//#include "hero.h"

/**
	The Hero class. 
 */
class Hero
{
	private: //We don't want people changing these willy nilly
		std::string name;
		int health;
		int strength;

	public: //Can be accessed by anyone, from anywhere. 
		//The constructor. A method automatically called when a new Hero is instantiated
		Hero(std::string name, int health, int strength)
		{
			this->name = name;
			this->health = health;
			this->strength = strength;
		};

		void attack(Hero target)
		{
			target.ouch(this->strength);
		};

		void ouch(int damage)
		{
			health -= damage;
		};

		std::string getName()
		{
			return name;
		};

		int getStrength()
		{
			return this->strength;
		};

		int getHealth()
		{
			return this->health;
		};
};

int main()
{
	Hero todd("Todd", 12, 6); //Instantiate a new hero

	Hero jeff("Jeff", 15, 12);

	std::cout << "Our hero's name is " << todd.getName() << " with " << todd.getHealth() << " health.\n";
	std::cout << jeff.getName() << " doesn't like " << todd.getName() << "\n";
	std::cout << jeff.getName() << "'s strength is " << jeff.getStrength() << "\n";
	jeff.attack(todd); //Look out, Todd!
	todd.ouch(12); //TODO shouldn't need to do this, the attack should do it on it's own
	std::cout << todd.getName() << " has " << todd.getHealth() << " remaining. Poor Tood.\n";
}