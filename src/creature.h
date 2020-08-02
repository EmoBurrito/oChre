#ifndef CREATURE
#define CREATURE

#include <climits>
#include <string>

/** Parent class to playable races. TODO Make abstract.
*/
class Creature {
	private:
	protected:
		Creature();
		std::string name; /**< Creature's name */

		/** Statistics determine the creature's abilities.

			Two dimensional array, see public defined offsets for meanings.

			Relationship could be an unsigned char and save some memory but then it wouldn't fit into the stats array
			and require other functions that would claim that any memory we would save. Generics may work but that could 
			overcomplicate things.
		*/
		short int stats[10][2] = {
			{10, 10},
			{5, 5},
			{50, RELATIONSHIP_MAX},
			{10, 10},
			{10, 10},
			{10, 10},
			{10, 10},
			{10, 10},
			{10, 10}
		};

	public:
		/** Constructor

			@param name Creature's name
		*/
		Creature(std::string name);
		// TODO Should these be static?
		const char HEALTH = 0; /**< Health stat array offset. */
		const char MANA = 1; /**< Mana stat array offset. */
		const char  RELATIONSHIP = 2; /**< Relationship stat array offset. */
		const char  DEXTERITY = 3; /**< Dexterity stat array offset. */
		const char  STRENGTH = 4; /**< Strength stat array offset. */
		const char  SPEED = 5; /**< Speed stat array offset. */
		const char  CONSTITUTION = 6; /**< Constitution stat array offset. */
		const char  CHARISMA = 7; /**< Charisma stat array offset. */
		const char  LUCK = 8; /**< Luck stat array offset. */

		const bool TEMPORARY = 0; /**< Current stat value, such as if someone has lost some health or spent some mana. */
		const bool PERMANENT = 1; /**< Value of an otherwise healthy creature. It is not a ceiling as it can be exceeded with boons. */

		const short int STATS_MIN = SHRT_MIN; /**< Stat floor. */
		const char RELATIONSHIP_MIN = 0; /**< Relationship floor. Creature will attack player on sight. */
		const char RELATIONSHIP_MAX = 100; /**< Relationship ceiling. Complete adoration. */
		
		/** Returns a stat.

			@param stat The stat to return. Use the defined constants.
			@param is_permanent Whether you want the temporary or permanent value.
		*/
		short int get_stat(char stat, bool is_permanent);

		/** Attacks this creature.

			TODO Add damage type.
			@param attack Attack roll, comes from the attacker. If equal to or greater than target's armour class, the attack succeeds and damages the target.
			@param damage Amount of damage the target takes.
		*/
		void attack(short int attack, short int damage);
		std::string get_name(); /**< Returns creature's name. */

		/** Changes/checks the relationship.

			@param adjustment The amount that the relationship improves or deteriorates. Set 0 to check current relationship.
		*/
		char change_relationship(char adjustment);
		std::string talk(); /**< Talks to creature. */
};

#endif

#ifndef HUMAN
#define HUMAN
/** Generic, simple creature.
*/
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
/** Less resilient but quicker than humans.
*/
class Goblin: public Creature {
	public:
		Goblin(); /**< Goblin constructor, using generated name. */
		/** Goblin constructor, using given name.
			@param name Given name.
		*/
		Goblin(std::string name) : Creature(name) {};
};
#endif
