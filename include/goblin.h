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
	const static vector<char> CONSONANTS;
	const static vector<char> VOWELS;
	const static int TOTAL_CONSONANTS = 21;
	const static int TOTAL_VOWELS = 6;

protected:
	string generateNameFirst(char sex='a') override ;
	string generateNameLast() override ;

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
};

#endif //GOBLIN_H
