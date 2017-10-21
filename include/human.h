#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include <map>
#include <vector>
#include "creature.h"

using namespace std;

///Instantiable Human creature.
/**
 * \b Humans make up more than a strong majority of the population, and as such craft the most plentiful equipment.
 *  They are a fine balance amongst all stats.
 */
class Human: public Humanoid {
private:
    //TODO Make vector of vectors for alternate spellings
	const static map<char, vector<string>> GIVEN_NAMES; /**< Given names, sorted by sex. Values are for given names, with a sub-vector for spelling variations. */
    const static vector<vector<string>> FAMILY_NAMES; /**< A vector of family names, with a sub-vector for spelling variations. */

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
