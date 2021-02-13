#ifndef PARTY
#define PARTY

#include "creature.hpp"
class Party {
	private:
		unsigned short int food = 6;
		unsigned int gold = 100;
		unsigned char members_count = 0;
	protected:
	public:
		//plublic for testing
		static const unsigned char MEMBERS_MIN = 1;
		static const unsigned char MEMBERS_MAX = 6;
		Party();
		// Party(Creature *starting_member);

		//TODO Convert to private array, using add/remove functions
		Creature * members[MEMBERS_MAX] = {NULL, NULL, NULL, NULL, NULL, NULL};

		Creature * add_member(Creature * new_member);
		Creature * add_member(Creature * new_member, unsigned char slot);
		Creature * remove_member(unsigned char slot);
		void swap_members(unsigned char member_first, unsigned char member_second);
		std::string iterate_members();

		unsigned short int adjust_food(short int adjustment);
		unsigned int adjust_gold(int adjustment);
};

#endif
