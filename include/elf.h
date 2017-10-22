#ifndef ELF_H
#define ELF_H
#include <string>
#include "creature.h"

using namespace std;

///Instantiable Elf creature.
/**
 * \b Elves are ever so slightly smaller than humans, but a bit quicker and more dexterous.
 * Their belief is that the best way to withstand a hit is to not let it connect.
 * Their size difference from humans is not great enough to warrant separate sizing.
 *
 * High Elves spend much of their time studying the arcane arts to keep their opponents at bay. If you can defeat them from a distance or use spells to assist yourself, there is little reason to deal with them up close.
 * Dark Elves prefer to stick to the shadows, and rely on their speed and accuracy to help them land their blows. If they can't hit it with an arrow before it sees them, get in close and slide it apart before it has a chance to even react.
 */
class Elf: public Humanoid {
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
	Elf(
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
	~Elf();  //Destructor

	string sayCatchPhrase()
	{
		return "Preaching to the choir";
	}


};

#endif //ELF_H
