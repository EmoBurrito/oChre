#ifndef PARTY_H
#define PARTY_H
#include <string>
#include "creature.h"

class Party
{
	private:
		//Time
		const unsigned int MINUTE = 1; /** 1 minute per minute. Not sure if necessary, more for future proofing if we decide to do something with seconds*/
		const unsigned int HOUR = 60; /** 60 minutes per hour */
		const unsigned int DAY = 24; /** 24 hours per day */
		const unsigned int WEEK = 7; /** 7 days per week
		/** What do for month? */
		/** Do I care about leap years? Is this Earth? Do we even need the Gregorian calendar? */


        //Party inventory
        unsigned int purse[4]; //Four denominations, each worth 100 of the last. Gems, gold, silver, copper. Consider notes for large amounts.
        unsigned int food; //Days worth of rations for the party. Consider float and having different races eat different amounts.
		Humanoid members[6]; //Maximum six party members at a time //TODO Consider dynamic sizing
		//C++ requires sizeOfs to be passed with array, just like C
		//C++ also supports multi-dimensional arrays but I'd personally prefer nested ones. More memory efficient.

	protected:

	public:
		Party();
		void printInventory();

		//Money
		bool moneyIncrease(unsigned int value[4]);
		bool moneyDecrease(unsigned int value[4]);
        unsigned int* getPurse(); //Returns an array of 4 unsigned ints

		//Food
		bool foodIncrease(unsigned int value);
		bool foodDecrease(unsigned int value);
        unsigned int getFood();

		void rest(); //Heal the party, decrement food, pass time

		//Reputation/Fame

		//Don't know what I want to do for time management though...
};

#endif //PARTY_H
