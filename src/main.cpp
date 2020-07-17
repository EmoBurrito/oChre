#include <cstdlib> //random number generation
#include <iostream> //print and getting input
#include <map> //dictionaries
#include <string>

#include "creature.h"
#include "party.h"

int main()
{
	std::cout << "=================\noChrewood Tribute\n=================\n";
	Creature first;  //No bracket invoke because no arguments passed. Compiler confuses with declaring function, like in a header file.
	Creature second("Terrance");
	Party my_party;
	my_party.members[0] = &first;
	my_party.members[1] = &second;
	std::cout << my_party.iterate_members();
	Creature peasant("Peasant");

	std::cout << "Starting fight. Peasant health: " << peasant.get_health_current() << "\n";
	while (peasant.get_health_current() > 0) {
		std::cout << "Peasant health: " << peasant.get_health_current() << "\n";
		peasant.attack(2, 2);
	}
}
