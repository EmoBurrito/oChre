#ifndef DRACONIC_H
#define DRACONIC_H
#include <string>
#include "creature.h"

using namespace std;

///Instantiable Draconic creature.
/**
 * \b Draconics are half dragon. Extreme unarmed damage, no equipment. Split into elements?
 */
class Draconic: public Humanoid {
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
	Draconic(
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
	~Draconic();  //Destructor

	string sayCatchPhrase()
	{
		return "Preaching to the choir";
	}


};

#endif //DRACONIC_H
