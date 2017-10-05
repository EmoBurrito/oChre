#ifndef ORC_H
#define ORC_H
#include <string>
#include "creature.h"

using namespace std;

///Instantiable Orc creature.
/**
 * \b Orcs are quite similar to humans but are often physically stronger and, as such, solve more problems in this manner.
 */
class Orc: public Humanoid {
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
	Orc(
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
	~Orc();  //Destructor

	string sayCatchPhrase()
	{
		return "Preaching to the choir";
	}


};

#endif //ORC_H
