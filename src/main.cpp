#include <cstdlib> //random number generation
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

	Human peasant("Peasant");
	std::cout << "Starting fight. Peasant health: " << peasant.get_health_current() << "\n";
	while (peasant.get_health_current() > 0) {
		std::cout << "Peasant health: " << peasant.get_health_current() << "\n";
		peasant.attack(2, 2);
	}
}
