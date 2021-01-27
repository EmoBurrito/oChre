#ifndef CREATURE
#define CREATURE

#include <climits>
#include <random>
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

        std::random_device rng_seed; /**< Seed for random number generators. TODO Make static? */

	public:
		/** Constructor

			@param name Creature's name
		*/
		Creature(std::string name);
		const static char HEALTH; /**< Health stat array offset. */
		const static char MANA; /**< Mana stat array offset. */
		const static char  RELATIONSHIP; /**< Relationship stat array offset. */
		const static char  DEXTERITY; /**< Dexterity stat array offset. */
		const static char  STRENGTH; /**< Strength stat array offset. */
		const static char  SPEED; /**< Speed stat array offset. */
		const static char  CONSTITUTION; /**< Constitution stat array offset. */
		const static char  CHARISMA; /**< Charisma stat array offset. */
		const static char  LUCK; /**< Luck stat array offset. */

		const static bool TEMPORARY; /**< Current stat value, such as if someone has lost some health or spent some mana. */
		const static bool PERMANENT; /**< Value of an otherwise healthy creature. It is not a ceiling as it can be exceeded with boons. */

		const static short int STATISTIC_MIN; /**< Stat floor. */
		const static short int STATISTIC_MAX; /**< Stat ceiling. */
		const static char RELATIONSHIP_MIN; /**< Relationship floor. Creature will attack player on sight. */
		const static char RELATIONSHIP_MAX; /**< Relationship ceiling. Complete adoration. */
		
		/** Returns a stat.

			@param stat The stat to return. Use the defined constants.
			@param is_permanent Whether you want the temporary or permanent value.
		*/
		short int get_statistic(char statistic, bool is_permanent);

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
        short int change_statistic(char statistic, bool is_permanent, short int adjustment);
		char change_relationship(char adjustment);
		std::string talk(); /**< Talks to creature. */

        float get_luck();
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
