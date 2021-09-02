#include <iostream> //print and getting input
#include <map> //dictionaries
#include <string>

#include "creature.hpp"
#include "party.hpp"

int main()
{
	std::string banner = "Ochrewood Tribute";
	std::string banner_header = std::string(banner.length()+4, '=') + '\n';
	std::cout << banner_header << "| " << banner << " |\n" << banner_header;

	Human human1;
	Human human2("Todd");
	Goblin goblin1;
	Goblin goblin2("Klurr");

	Party my_party;
	my_party.add_member(&human1);
	my_party.add_member(&human2);
	my_party.add_member(&goblin1, 3);
	my_party.add_member(&goblin2, 2);
	std::cout << my_party.iterate_members();

    //Boost strength by 5
    my_party.members[0]->change_statistic(my_party.members[0]->STRENGTH, my_party.members[0]->TEMPORARY, 5);

    std::cout << "" << my_party.members[0]->get_name() << "'s strength: " << my_party.members[0]->get_statistic(my_party.members[0]->STRENGTH, my_party.members[0]->TEMPORARY) << "\n";

	Human peasant("Peasant");
	std::cout << "Starting fight. Peasant health: " << peasant.get_statistic(peasant.HEALTH, peasant.TEMPORARY) << "\n";
}
