#include <iostream>
#include <string>
#include "hero.h"

using namespace std;

int main()
{
	Hero todd("Todd", 12, 6); //Instantiate a new hero

	Hero jeff("Jeff", 15, 12);

	cout << "Our hero's name is " << todd.getName() << " with " << todd.getHealth() << " health.\n";
	cout << jeff.getName() << " doesn't like " << todd.getName() << "\n";
	cout << jeff.getName() << "'s strength is " << jeff.getStrength() << "\n";
	jeff.attack(todd); //Look out, Todd!
	//todd.ouch(12); //TODO shouldn't need to do this, the attack should do it on it's own
	cout << jeff.getName() << " has " << jeff.getHealth() << " remaining. Poor Jeff.\n";
	cout << todd.getName() << " has " << todd.getHealth() << " remaining. Poor Tood.\n";
	//cout << "Test of toString: " << *jeff
}
