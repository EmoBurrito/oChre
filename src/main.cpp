#include <iostream>
#include <string>
#include "party.h"
#include "hero.h"
#include "item.h"

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

    Party myParty();
	cout << "What shall be the champion's name?\n>";
	string heroName; //Declare the name variable
	cin >> heroName; //Prompt user for name, which is then stored in the variable. Doesn't seem to take empty string?
	//TODO Allow user to enter spaces. Look into getLine()

	//Make sure the user gave us a name. Doesn't seem to even take empty string, so this isn't necessary
	// while (heroName.length() == 0) {
	// 	cout << "Give us something to work with here, buddy\n";
	// 	cin >> heroName; //Make them try again
	// }

	Hero my_protagonist(heroName, 15, 12); //Makes new hero with our input name
	Hero my_antagonist("", 12, 6); //Let's make someone to fight

	cout << "Our hero's name is " << my_protagonist.getName() << " with " << my_protagonist.getHealth() << " health.\n";
	cout << my_antagonist.getName() << " doesn't like " << my_protagonist.getName() << ".\n";
	cout << my_antagonist.getName() << "'s strength is " <<  my_antagonist.getStrength() << ".\n";
	my_antagonist.attack(&my_protagonist); //Pass the address, essentially creating a pointer. Look out, Todd!
	//my_protagonist.ouch(12); //TODO shouldn't need to do this, the attack should do it on it's own
	cout << my_protagonist.getName() << " has " << my_protagonist.getHealth() << " health. remaining. Poor " << my_protagonist.getName() << ".\n";
	cout << my_antagonist.getName() << " has " << my_antagonist.getHealth() << " health remaining. Poor " << my_antagonist.getName() << ".\n";
	//cout << "Test of toString: " << *my_protagonist

	//Messing around with items
	Hand myItem("sword");
	cout << "Hey, look! A " << myItem.getName() << "! Get 'em, " << my_protagonist.getName() << "!\n";
	//Equip the sword, which should modify the attack values
	my_protagonist.attack(&my_antagonist);
}

void sizeCheck()
{
	cout << "Memory sizes in bytes:\n";
	cout << "Party: " << sizeof(Party) << "\n";
	cout << "Hero: " << sizeof(Hero) << "\n";
}

//::tuna like super? E29

void printParty()
{
    // TODO Move this to Party
    cout << "===";
    cout << "TIME | Money | Food";
    cout << "===";
}