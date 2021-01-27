#include <iostream> //print and getting input
#include <map> //dictionaries
#include <string>

#include "creature.h"
#include "party.h"

int main()
{
	std::cout << "=================\noChrewood Tribute\n=================\n";
	Human human1;
	Human human2("Todd");
	Goblin goblin1;
	Goblin goblin2("Klurr");

	Party my_party;
	my_party.members[0] = &human1;
	my_party.members[1] = &human2;
	my_party.members[2] = &goblin1;
	my_party.members[3] = &goblin2;
	std::cout << my_party.iterate_members();

    //Boost strength by 5
    my_party.members[0]->change_statistic(my_party.members[0]->STRENGTH, my_party.members[0]->TEMPORARY, 5);

    std::cout << "" << my_party.members[0]->get_name() << "'s strength: " << my_party.members[0]->get_statistic(my_party.members[0]->STRENGTH, my_party.members[0]->TEMPORARY) << "\n";

	Human peasant("Peasant");
	std::cout << "Starting fight. Peasant health: " << peasant.get_statistic(peasant.HEALTH, peasant.TEMPORARY) << "\n";
}
