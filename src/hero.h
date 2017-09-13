#ifndef HERO_H
#define HERO_H
#include <string>
#include "item.h"

class Hero
{
	private:
		std::string name;
		int health;
		int mana;
		int accuracy;
		int strength;
		int speed;
		int intellect;
		int wisdom;
		int luck;

		//Equipment
		Head * head;
		Torso * torso;
		Hand * lHand;
		Hand * rHand;
		//Ring rings [20] = {}; //TODO Figure out initializing array to empty values
		Legs * legs;
		Feet * feet;

		//Internal methods
		static std::string generateName(char sex='n');
		static std::string generateNameFirst(char sex='n');
		static std::string generateNameLast();
        static std::string generateNameCompound();

	protected:

	public:
		//Default values go in function prototypes only
		Hero(
			std::string name="",
			int=10,
			int=10,
			int=10,
			int=10,
			int=10,
			int=10,
			int=10,
			int=10
		); //Constructor - Bucky had a different constructor in 14
		~Hero();
		void attack(Hero *targetPointer); //Attempts to attack a target. If we don't pass a pointer, it passes by value instead of reference
		void ouch(int damageInflicted); //Takes damage

		//Getters
		std::string getName();
		int getStrength();
		int getHealth();

		std::string sayCatchPhrase()
		{
			return "Preaching to the choir";
		}
};

#endif //HERO_H
