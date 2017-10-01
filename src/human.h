#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include "creature.h"

using namespace std;

///Human class. Instantiable.
/**
 * \b Humans make up more than a strong majority of the population, and as such craft the most plentiful equipment.
 *  They are able to use most equipment and are a fine balance amongst all stats.
 */
class Human: public Humanoid {
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
	Human(
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
	~Human();  //Destructor

	string sayCatchPhrase()
	{
		return "Preaching to the choir";
	}


};

#endif //HUMAN_H
