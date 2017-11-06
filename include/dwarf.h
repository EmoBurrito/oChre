#ifndef DWARF_H
#define DWARF_H
#include <string>
#include <vector>
#include "creature.h"

using namespace std;

///Instantiable Dwarf creature.
/**
 * \b Dwarves are short, stocky, strong as an ox but smarter than one too, and full of vigor.
 * It takes a lot of force to push a dwarf over.
 */
class Dwarf: public Humanoid {
private:
	const static vector<string> MALE_NAMES; /**< A vector of male names */
	const static vector<string> FEMALE_NAMES; /**< A vector of female names */
	const static vector<string> ANDROGYNOUS_NAMES; /**< A vector of androgynous names */
	const static vector<string> FAMILY_NAMES1; /**< A vector of starter family names. To be compounded with a closing family name. */
	const static vector<string> FAMILY_NAMES2; /**< A vector of closing family names. To be compounded with a starter family name. */

protected:
	string generateNameFirst(char sex='a') override;
	string generateNameLast() override;

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
};

#endif //DWARF_H
