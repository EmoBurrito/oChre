#ifndef HUMAN_H
#define HUMAN_H
#include <string>
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
    const static vector< vector<string> > MALE_NAMES; /**< A vector of male names, with a sub-vector for spelling variations. */
    const static vector< vector<string> > FEMALE_NAMES; /**< A vector of female names, with a sub-vector for spelling variations. */
    const static vector< vector<string> > ANDROGYNOUS_NAMES; /**< A vector of androgynous names, with a sub-vector for spelling variations. */
    const static vector< vector<string> > FAMILY_NAMES; /**< A vector of family names, with a sub-vector for spelling variations. */

protected:
	string generateNameFirst(char sex='a') override;
	string generateNameLast() override;

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
};

#endif //HUMAN_H
