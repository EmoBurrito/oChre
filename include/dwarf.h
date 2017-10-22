#ifndef DWARF_H
#define DWARF_H
#include <string>
#include "creature.h"

using namespace std;

///Instantiable Dwarf creature.
/**
 * \b Dwarves are short, stocky, strong as an ox but smarter than one too, and full of vigor.
 * It takes a lot of force to push a dwarf over.
 */
class Dwarf: public Humanoid {
private:
	//Internal methods
	//TODO Move these methods to humanoid class that draw from vectors in the children
	static string generateName(char sex='n');
	static string generateNameFirst(char sex='n');
	static string generateNameLast();
	static string generateNameCompound();

protected:

public:
	//Default values go in function prototypes only
	Dwarf(
		string name="",
		int=10,
		int=10,
		int=10,
		int=10,
		int=10,
		int=10,
		int=10,
		int=10
	); //Constructor - Bucky had a different constructor in 14
	~Dwarf();  //Destructor

	string sayCatchPhrase()
	{
		return "Preaching to the choir";
	}


};

#endif //DWARF_H
