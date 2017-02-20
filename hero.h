#ifndef HERO_H
#define HERO_H
#include <string>

class Hero
{
	private :
		std::string name;
		int health;
		int strength;
		
	public:
		Hero(std::string, int, int);
		void attack(Hero&);
		void ouch(int);
		std::string getName();
		int getStrength();
		int getHealth();
};

#endif
