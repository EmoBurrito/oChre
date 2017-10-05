#include <iostream>
#include <string>
#include "../include/party.h"
#include "../include/human.h"
#include "../include/rat.h"
#include "../include/equippable.h"

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
	string humanName; //Declare the name variable
	cin >> humanName; //Prompt user for name, which is then stored in the variable. Doesn't seem to take empty string?
	//TODO Allow user to enter spaces. Look into getLine()

	//Make sure the user gave us a name. Doesn't seem to even take empty string, so this isn't necessary
	// while (humanName.length() == 0) {
	// 	cout << "Give us something to work with here, buddy\n";
	// 	cin >> humanName; //Make them try again
	// }

	Human my_protagonist(humanName, 15, 12); //Makes new human with our input name
	Human my_antagonist("", 12, 6); //Let's make someone to fight

	cout << "Our human's name is " << my_protagonist.getName() << " with " << my_protagonist.getHealth() << " health.\n";

    Rat rat;
    cout << "Oh, gross! A " << rat.getName() << "! Get it!!\n";
//    delete rat;  //Not only does this not work, I don't think it's the best way to go about this
//    while (rat.getHealth() > 0) {
//		my_protagonist.attack(&rat);
//	}
	Rat *rat_pointer = &rat;
	rat_pointer = NULL;

    GiantRat giantRat;
    cout << "Jeez, look at that " << giantRat.getName() << "! They sure grow large around here...\n";
    //TODO Wail on it 'til it dies too.

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
	cout << "Human: " << sizeof(Human) << "\n";
    //cout << "Consumable: " << sizeof(Consumable) << "\n";
    cout << "Equippable: " << sizeof(Hand) << "\n";
}

//::tuna like super? E29

void printParty()
{
    // TODO Move this to Party
    cout << "===";
    cout << "TIME | Money | Food";  //TODO Replace time with an actual timestamp
    cout << "===";
}