#ifndef TROLL_H
#define TROLL_H
#include <string>
#include "creature.h"

using namespace std;

///Instantiable Troll creature.
/**
 * \b Trolls more extreme half orc. Limited in equipment
 */
class Troll: public Humanoid {
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
	Troll(
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
	~Troll();  //Destructor

	string sayCatchPhrase()
	{
		return "Preaching to the choir";
	}


};

#endif //TROLL_H
