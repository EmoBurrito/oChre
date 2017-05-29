#ifndef HERO_H
#define HERO_H
#include <string>

class Hero
{
	private:
		std::string name;
		int health;
		int strength;
		static std::string generateName(char sex='n');

	protected:

	public:
		//Default values go in function prototypes only
		Hero(std::string name="", int=10, int=10); //Constructor - Bucky had a different constructor in 14
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
