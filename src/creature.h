#ifndef CREATURE
#define CREATURE

#include <string>

class Creature {
	private:
	protected:
		Creature();
		std::string name; /**< Creature's name */
		
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
		Creature(std::string name);
		const char RELATIONSHIP_MIN = 0;
		const char RELATIONSHIP_MAX = 100;
		
		short int get_health_current();
		short int get_health_max();
		short int get_mana_current();
		short int get_mana_max();
		
		/** Attacks this creature.

			TODO Add damage type.
			@param attack Attack roll, comes from the attacker. If equal to or greater than target's armour class, the attack succeeds and damages the target.
			@param damage Amount of damage the target takes.
		*/
		void attack(short int attack, short int damage);
		std::string get_name(); /**< Returns creature's name. */
		char get_relationship();
		char change_relationship(char adjustment);
		std::string talk();
};

#endif

#ifndef HUMAN
#define HUMAN
class Human: public Creature {
	public:
		Human(); /**< Human constructor, using generated name. */
		/** Human constructor, using given name.
			@param name Given name.
		*/
		Human(std::string name) : Creature(name) {};
};
#endif

#ifndef GOBLIN
#define GOBLIN
class Goblin: public Creature {
	public:
		Goblin(); /**< Goblin constructor, using generated name. */
		/** Goblin constructor, using given name.
			@param name Given name.
		*/
		Goblin(std::string name) : Creature(name) {};
};
#endif
