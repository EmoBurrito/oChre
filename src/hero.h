#ifndef HERO_H
#define HERO_H
#include <string>
#include "creature.h"
#include "equippable.h"

using namespace std;

class Hero: public Creature {
	private:
		//Equipment
		Head * head;
		Torso * torso;
		Hand * lHand;
		Hand * rHand;
		//Ring rings [20] = {}; //TODO Figure out initializing array to empty values
		Legs * legs;
		Feet * feet;

		//Internal methods
		static string generateName(char sex='n');
		static string generateNameFirst(char sex='n');
		static string generateNameLast();
        static string generateNameCompound();

	protected:

	public:
		//Default values go in function prototypes only
		Hero(
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
		~Hero();  //Destructor

		string sayCatchPhrase()
		{
			return "Preaching to the choir";
		}
};

#endif //HERO_H
