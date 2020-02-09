#include <climits> // variable max and mins
#include <cstdlib> //random number generation
#include <iostream> //print and getting input
#include <map> //dictionaries
#include <string>

#include "creature.h"
#include "party.h"

std::map<std::string, std::string> GREETING{
	{"TEXT", "Hello World from C++!"},
	{"SOUNDFILE", "null.ogg"}
};

//TODO Find a way to drop unused languages from memory
//What if I returned the map itself and not the selection?
std::map<std::string, std::string> ENGLISH{
	{"GREETING", "Hello World from C++!"}
};

std::map<char, std::string> LANGUAGES{
	{'e', "Hello World from C++!"},
	{'f', "Bonjour le monde de C++!"},
	{'s', "Hola Mundo desde C++!"}
};

char determine_language() {
	std::string LANGUAGE_CHOICES [] = {"English", "Francais", "Espanol"};
	char language_selection = 'e';
	bool language_selection_valid = false;
	do{
		std::cout << "Language:\n";
		for(unsigned char i = 0; i < sizeof(LANGUAGE_CHOICES)/sizeof(LANGUAGE_CHOICES[0]); i++)
		{
			std::cout << i+1 << ": " << LANGUAGE_CHOICES[i] << "\n";
		}
		// TODO Prompt user for language
		language_selection = 'e';
		language_selection_valid = true;
	}while(!language_selection_valid);
	std::cout << "Your language is " << language_selection << "\n";
	return language_selection;
	//TODO Check if config file exists
	//TRUE: Read config
	//False: Prompt for language
};

int main()
{
	//char language_selection = determine_language();
	//std::cout << LANGUAGES[language_selection] << "\n";
	//std::cout << ENGLISH["GREETING"] << "\n";
	//std::cout << GREETING["TEXT"] << "\n";
	//std::cout << GREETING["SOUNDFILE"] << "\n";
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
}
