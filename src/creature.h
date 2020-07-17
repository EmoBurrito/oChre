#ifndef CREATURE
#define CREATURE

#include <string>

class Creature {
	private:
		std::string name;
		
		//TODO What if every stat was a map of current,min,max.
		//Then we could just pass the map to the same increase/decrease function.
		//Or we could just pass all three variables each time, save me from importing the library.
		//Stats can be negative.
		short int health_current = 10;
		short int health_max = 10;
		short int mana_current = 0;
		short int mana_max = 0;
		
		char relationship = 50;
	public:
		const char RELATIONSHIP_MIN = 0;
		const char RELATIONSHIP_MAX = 100;

		Creature();
		Creature(std::string);
		
		short int get_health_current();
		short int get_health_max();
		short int get_mana_current();
		short int get_mana_max();
		
		void attack(short int attack, short int damage);
		std::string get_name();
		char get_relationship();
		char change_relationship(char adjustment);
		void attack();
		std::string talk();
};

#endif
