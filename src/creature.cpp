#include <string>

#include "creature.h"

Creature::Creature() {
	this->name = "Dave";
}
	
Creature::Creature(std::string name_arg) {
	this->name = name_arg;
}
	
std::string Creature::get_name() {
	return this->name;
}

short int Creature::get_health_current(){
	return this->health_current;
};
short int Creature::get_health_max(){
	return this->health_max;
};
short int Creature::get_mana_current(){
	return this->mana_current;
};
short int Creature::get_mana_max(){
	return this->mana_max;
};
	
char Creature::get_relationship() {
	return this->relationship;
}
	
// Takes either positive or negative number and adds to relationship
char Creature::change_relationship(char adjustment) {
	//Reducing relationship
	if (adjustment < 0) {
		// If the adjustment would reduce below 0, set to 0 instead
		if (adjustment + relationship < RELATIONSHIP_MIN) {
			relationship = RELATIONSHIP_MIN;
		}
		else {
			relationship = adjustment + relationship;
		}
	}
	//Improving relationship
	else {
		// If the adjustment would improve relationship past 100, set to 100 instead
		if (adjustment + relationship > RELATIONSHIP_MAX) {
			relationship = RELATIONSHIP_MAX;
		}
		else {
			relationship = adjustment + relationship;
		}
	}
	return relationship;
}
	
void Creature::attack() {
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
