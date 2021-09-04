#include <iostream> //print and getting input
#include <map> //dictionaries
#include <string>

#include "creature.hpp"
#include "party.hpp"

#if _WIN32 || _WIN64
	#define OCHRE_PLATFORM "Windows"
	#if _WIN64
		#define OCHRE_ARCH "x86_64"
	#elif _WIN32
		#define OCHRE_ARCH "i386"
	#endif
#elif __GNUC__
	#define OCHRE_PLATFORM "Linux"
	#if __x86_64__
		#define OCHRE_ARCH "x86_64"
	#elif __aarch64__
		#define OCHRE_ARCH "aarch64"
	#endif
#endif

#ifndef OCHRE_VERSION
	#define OCHRE_VERSION "UNDEFINED"
#endif
#ifndef OCHRE_PLATFORM
	#define OCHRE_PLATFORM "UNKNOWN"
#endif
#ifndef OCHRE_ARCH
	#define OCHRE_ARCH "UNKNOWN"
#endif

int main()
{
	std::string banner = "| Ochrewood Tribute v" + std::string(OCHRE_VERSION) + " for " + std::string(OCHRE_PLATFORM) + " on " + std::string(OCHRE_ARCH) + " |\n";
	std::string banner_header = std::string(banner.length()-1, '=') + '\n';
	std::cout << banner_header << banner << banner_header;

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
