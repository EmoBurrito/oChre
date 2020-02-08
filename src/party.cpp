#include <string.h>
#include "party.h"

Party::Party() {

}

std::string Party::iterate_members() {
	//strings are not the same as char arrays. Strings can be concatenated with + but char arrays cannot
	//However, char arrays can be concatenated to strings
	std::string header = "----------------\n| Party Status |\n----------------\n";
	std::string food_gold = "Food: " + std::to_string(this->food) + " | Gold: " + std::to_string(this->gold) + "\n";
	//TODO After converting party members to an array, loop over the members
	std::string first = this->member_first->get_name()
		+ " | HP: " + std::to_string(this->member_first->get_health_current()) + "/" + std::to_string(this->member_first->get_health_max()) + " | "
		+ "MP: " + std::to_string(this->member_first->get_mana_current()) + "/" + std::to_string(this->member_first->get_mana_max()) + "\n";

	return header + food_gold + first;
}
