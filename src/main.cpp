#include <iostream>
#include <string>
#include "hero.h"

using namespace std;

//Function prototypes - They are so the compiler knows ABOUT the function before use
void someFunction();

int main()
{
	cout << "What shall be the champion's name?\n";
	string heroName; //Declare the name variable
	cin >> heroName; //Prompt user for name, which is then stored in the variable. Doesn't seem to take empty string?
	//TODO Allow user to enter spaces

	//Make sure the user gave us a name. Doesn't seem to even take empty string, so this isn't necessary
	// while (heroName.length() == 0) {
	// 	cout << "Give us something to work with here, buddy\n";
	// 	cin >> heroName; //Make them try again
	// }

	Hero jeff(heroName, 15, 12); //Makes new hero with our input name
	Hero todd("Todd", 12, 6); //Let's make someone to fight

	cout << "Our hero's name is " << todd.getName() << " with " << todd.getHealth() << " health.\n";
	cout << jeff.getName() << " doesn't like " << todd.getName() << "\n";
	cout << jeff.getName() << "'s strength is " << jeff.getStrength() << "\n";
	jeff.attack(todd); //Look out, Todd!
	//todd.ouch(12); //TODO shouldn't need to do this, the attack should do it on it's own
	cout << jeff.getName() << " has " << jeff.getHealth() << " remaining. Poor Jeff.\n";
	cout << todd.getName() << " has " << todd.getHealth() << " remaining. Poor Tood.\n";
	//cout << "Test of toString: " << *jeff
}

void someFunction()
{
	cout << "I'm a function! :D" << '\n';
}
