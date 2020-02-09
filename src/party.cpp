#include <string.h>
#include "party.h"

Party::Party() {

}

std::string Party::iterate_members() {
	//strings are not the same as char arrays. Strings can be concatenated with + but char arrays cannot
	//However, char arrays can be concatenated to strings
	std::string to_return = "----------------\n| Party Status |\n----------------\n";
	to_return += "Food: " + std::to_string(this->food) + " | Gold: " + std::to_string(this->gold) + "\n";
	for (Creature * current_member : this->members){
		if (current_member != NULL) {
			to_return += current_member->get_name()
				+ " | HP: " + std::to_string(current_member->get_health_current()) + "/" + std::to_string(current_member->get_health_max()) + " | "
				+ "MP: " + std::to_string(current_member->get_mana_current()) + "/" + std::to_string(current_member->get_mana_max()) + "\n";
		}
		else {
			to_return += "---\n";
		}
	}

	return to_return;
}
