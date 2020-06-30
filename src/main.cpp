#include <climits> // variable max and mins
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
	std::cout << "Oh, look. A peasant. " << peasant.get_name() << " relationship: " << (int)peasant.get_relationship() << "\n";
	std::cout << "He appears non-hostile. Let's see what he has to say.\n";
	std::cout << peasant.talk() << "\n";
	std::cout << "Haha, you keep on, keepin' on. The peasant likes that you enjoyed his banter.\n";
	std::cout << peasant.get_name() << " relationship: " << (int)peasant.change_relationship(10) << "\n";
	std::cout << peasant.talk() << "\n";
	std::cout << "You give him a pity laugh at best. The peasant appears bothered.\n";
	std::cout << peasant.get_name() << " relationship: " << (int)peasant.change_relationship(-20) << "\n";
	std::cout << peasant.talk() << "\n";
	std::cout << "... What?\n";
	std::cout << peasant.get_name() << " relationship: " << (int)peasant.change_relationship(CHAR_MAX) << "\n";
	std::cout << peasant.talk() << "\n";
	std::cout << "This is getting out of hand. Better cave his skull in.\n";
	std::cout << peasant.get_name() << " relationship: " << (int)peasant.change_relationship(CHAR_MIN) << "\n";

	std::cout << "Starting fight. Peasant health: " << peasant.get_health_current() << "\n";
	while (peasant.get_health_current() > 0) {
		std::cout << "Peasant health: " << peasant.get_health_current() << "\n";
		peasant.attack(2, 2);
	}
}
