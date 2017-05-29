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
		Hero(std::string="", int=10, int=10); //Constructor - Bucky had a different constructor in 14
		void attack(Hero&); //Attempts to attack a target
		void ouch(int); //Takes damage

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
