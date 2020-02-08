#ifndef PARTY
#define PARTY

#include "creature.h"
class Party {
	private:
		unsigned short int food = 6;
		unsigned int gold = 100;
		unsigned char members_count = 0;
		static const unsigned char MEMBERS_MIN = 1;
		static const unsigned char MEMBERS_MAX = 6;
	protected:
	public:
		Party();
		// Party(Creature *starting_member);

		//TODO Convert to private array, using add/remove functions
		Creature * member_first;
		Creature * member_second;
		Creature * member_third;
		Creature * member_fourth;
		Creature * member_fifth;
		Creature * member_sixth;

		std::string iterate_members();

		unsigned short int adjust_food(short int adjustment);
		unsigned int adjust_gold(int adjustment);

		unsigned char add_member(Creature *new_member);
		unsigned char remove_member(Creature *removed_member);
		unsigned char swap_member(unsigned char member_first, unsigned char member_second);
};

#endif
