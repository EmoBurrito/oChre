#ifndef GNOME_H
#define GNOME_H
#include <string>
#include "creature.h"

using namespace std;

///Instantiable Gnome creature.
/**
 * \b Gnomes are much like dark elves but different role play and harder to hit.
 */
class Gnome: public Humanoid {
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
	Gnome(
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
	~Gnome();  //Destructor

	string sayCatchPhrase()
	{
		return "Preaching to the choir";
	}
};

#endif //GNOME_H
