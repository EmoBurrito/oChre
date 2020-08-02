#include <string>
#include "creature.h"

Creature::Creature() {
	this->name = "Creature";
}

Creature::Creature(std::string name) {
	this->name = name;
}

std::string Creature::get_name() {
	return this->name;
}

short int Creature::get_stat(char stat, bool is_permanent){
	return this->stats[stat][is_permanent];
};

// Takes either positive or negative number and adds to relationship
char Creature::change_relationship(char adjustment) {
	// If the adjustment would reduce below min, set to min instead
	if (adjustment < 0 && adjustment + stats[RELATIONSHIP][TEMPORARY] < RELATIONSHIP_MIN) {stats[RELATIONSHIP][TEMPORARY] = RELATIONSHIP_MIN;}
	// If the adjustment would improve relationship past max, set to max instead
	else if (adjustment > 0 && adjustment + stats[RELATIONSHIP][TEMPORARY] > RELATIONSHIP_MAX) {stats[RELATIONSHIP][TEMPORARY] = RELATIONSHIP_MAX;}
	// Otherwise, simply make the adjustment
	else {stats[RELATIONSHIP][TEMPORARY] = adjustment + stats[RELATIONSHIP][TEMPORARY];}
	return stats[RELATIONSHIP][TEMPORARY];
}

void Creature::attack(short int attack, short int damage) {
	// TODO Add attack roll
	if (true) {
		// TODO Add an attack type for resistances
		this->stats[HEALTH][TEMPORARY] = this->stats[HEALTH][TEMPORARY] - damage;
	}
}
	
std::string Creature::talk() {
	std::string sayings [] = {
		"I'm saving the best for last.",
		"I do what I'm told.",
		"Hey Reggie, is that rhinoceros around?",
		"Don't fake the funk on a nasty dunk.",
		"Twas the pride of the peaches.",
		"I was raised by a cup of coffee.",
		"Rightio! I think I can twice.",
		"I'm a song from the sixties.",
		"I'm a million ladies tall!",
		"I'm just in time for the murder mystery!",
		"I'm crying on the inside.",
		"You gotta get yours, I gotta get mine.",
		"I'm forever your girl!",
		"It's time for tasteball!"
	};
	return sayings[rand() % sizeof(sayings)/sizeof(*sayings)];
};

// TODO Generate names
Human::Human() {
	this->name = "Human";
}

Goblin::Goblin() {
	this->name = "Goblin";
}
