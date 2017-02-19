#include <iostream>
#include <string>
#include "hero.h"

int main()
{
	Hero todd("Todd", 12, 6); //Instantiate a new hero

	Hero jeff("Jeff", 15, 12);

	std::cout << "Our hero's name is " << todd.getName() << " with " << todd.getHealth() << " health.\n";
	std::cout << jeff.getName() << " doesn't like " << todd.getName() << "\n";
	std::cout << jeff.getName() << "'s strength is " << jeff.getStrength() << "\n";
	jeff.attack(todd); //Look out, Todd!
	//todd.ouch(12); //TODO shouldn't need to do this, the attack should do it on it's own
	std::cout << jeff.getName() << " has " << jeff.getHealth() << " remaining. Poor Jeff.\n";
	std::cout << todd.getName() << " has " << todd.getHealth() << " remaining. Poor Tood.\n";
}