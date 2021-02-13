#include <string.h>
#include "party.hpp"

Party::Party() {

}

Creature * Party::add_member(Creature * new_member) {
	bool empty_slot_found = false;
	unsigned char free_slot;
	for (free_slot = 0; free_slot < this->MEMBERS_MAX; free_slot++) {
		if (this->members[free_slot] == NULL) {
			empty_slot_found = true;
			break;
		}
	}
	//TODO Raise an error if no slot found?
	if (empty_slot_found) {
		return this->add_member(new_member, free_slot);
	}
	else {
		return NULL;
	}
}

Creature * Party::add_member(Creature * new_member, unsigned char slot) {
	Creature * previous_member = this->members[slot];
	this->members[slot] = new_member;
	return previous_member;
}

Creature * Party::remove_member(unsigned char slot) {
	Creature * to_return = this->members[slot];
	this->members[slot] = NULL;
	return to_return;
}

void Party::swap_members(unsigned char member_first, unsigned char member_second) {
	Creature * temp = this->members[member_first];
	this->members[member_first] = this->members[member_second];
	this->members[member_second] = temp;
}

std::string Party::iterate_members() {
	//strings are not the same as char arrays. Strings can be concatenated with + but char arrays cannot
	//However, char arrays can be concatenated to strings
	std::string to_return = "----------------\n| Party Status |\n----------------\n";
	to_return += "Food: " + std::to_string(this->food) + " | Gold: " + std::to_string(this->gold) + "\n";
	for (Creature * current_member : this->members){
		if (current_member != NULL) {
			to_return += current_member->get_name()
				+ " | HP: " + std::to_string(current_member->get_statistic(current_member->HEALTH, current_member->TEMPORARY)) + "/" + std::to_string(current_member->get_statistic(current_member->HEALTH, current_member->PERMANENT)) + " | "
				+ "MP: " + std::to_string(current_member->get_statistic(current_member->MANA, current_member->TEMPORARY)) + "/" + std::to_string(current_member->get_statistic(current_member->MANA, current_member->TEMPORARY)) + "\n";
		}
		else {
			to_return += "---\n";
		}
	}

	return to_return;
}

// TODO Check for min/max before adjustment
unsigned short int Party::adjust_food(short int adjustment) {
	this->food = this->food + adjustment;
	return this->food;
};
unsigned int Party::adjust_gold(int adjustment) {
	this->gold = this->gold + adjustment;
	return this->gold;
};
