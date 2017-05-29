#ifndef PARTY_H
#define PARTY_H
#include <string>

class Party
{
	private:
		Hero members[6]; //Maximum six party members at a time
		//C++ requires sizeOfs to be passed with array, just like C
		//C++ also supports multi-dimensional arrays but I'd personally prefer nested ones. More memory efficient.

	protected:

	public:
		Party();

		//Money
		void moneyIncrease(unsigned int value);
		bool moneyDecrease(unsigned int value);

		//Food
		void foodIncrease(unsigned int value);
		bool foodDecrease(unsigned int value);

		void rest(); //Heal the party, decrement food, pass time

		//Reputation/Fame

		//Don't know what I want to do for time management though...
};

#endif //PARTY_H
