#ifndef GOBLIN_H
#define GOBLIN_H
#include <string>
#include "creature.h"

using namespace std;

///Instantiable Goblin creature.
/**
 * \b Goblins are a worse version of orc. Plentiful, seen as infestation. Cheap to recruit.
 */
class Goblin: public Humanoid {
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
	Goblin(
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
	~Goblin();  //Destructor

	string sayCatchPhrase()
	{
		return "Preaching to the choir";
	}


};

#endif //GOBLIN_H
