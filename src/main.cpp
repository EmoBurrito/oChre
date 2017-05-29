#include <iostream>
#include <string>
#include "party.h"
#include "hero.h"
#include "item.h"
#include "equipable.h"

using namespace std;

//Function prototypes - They are so the compiler knows ABOUT the function before use
void sizeCheck();

int main()
{
	//Opening
	cout << "================================\n";
	cout << "= WELCOME TO OCHREWOOD TRIBUTE =\n";
	cout << "================================\n";
	sizeCheck();
	cout << "\n";

	cout << "What shall be the champion's name?\n";
	string heroName; //Declare the name variable
	cin >> heroName; //Prompt user for name, which is then stored in the variable. Doesn't seem to take empty string?
	//TODO Allow user to enter spaces. Look into getLine()

	//Make sure the user gave us a name. Doesn't seem to even take empty string, so this isn't necessary
	// while (heroName.length() == 0) {
	// 	cout << "Give us something to work with here, buddy\n";
	// 	cin >> heroName; //Make them try again
	// }

	Hero jeff(heroName, 15, 12); //Makes new hero with our input name
	Hero todd("", 12, 6); //Let's make someone to fight

	cout << "Our hero's name is " << todd.getName() << " with " << todd.getHealth() << " health.\n";
	cout << jeff.getName() << " doesn't like " << todd.getName() << "\n";
	cout << jeff.getName() << "'s strength is " << jeff.getStrength() << "\n";
	jeff.attack(&todd); //Pass the address, essentially creating a pointer. Look out, Todd!
	//todd.ouch(12); //TODO shouldn't need to do this, the attack should do it on it's own
	cout << jeff.getName() << " has " << jeff.getHealth() << " remaining. Poor Jeff.\n";
	cout << todd.getName() << " has " << todd.getHealth() << " remaining. Poor Tood.\n";
	//cout << "Test of toString: " << *jeff

	//Messing around with items
	Item mySword();
	cout << "Hey, look! A " << mySword.getName();
}

void sizeCheck()
{
	cout << "Party: " << sizeof(Party) << "\n";
	cout << "Hero: " << sizeof(Hero) << "\n";
}

//::tuna like super? E29
