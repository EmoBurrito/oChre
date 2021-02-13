#include <string>
#include "creature.hpp"

// I don't understand why static variables need to be declared in .hpp
// and defined here with the "Creature::" and no "static" keyword
// but value can be in either file
const char Creature::HEALTH = 0;
const char Creature::MANA = 1;
const char Creature::RELATIONSHIP = 2;
const char Creature::DEXTERITY = 3;
const char Creature::STRENGTH = 4;
const char Creature::SPEED = 5;
const char Creature::CONSTITUTION = 6;
const char Creature::CHARISMA = 7;
const char Creature::LUCK = 8;

const bool Creature::TEMPORARY = 0;
const bool Creature::PERMANENT = 1;

const short int Creature::STATISTIC_MIN = SHRT_MIN;
const short int Creature::STATISTIC_MAX = SHRT_MAX;
const char Creature::RELATIONSHIP_MIN = 0;
const char Creature::RELATIONSHIP_MAX = 100;

Creature::Creature() {
	this->name = "Creature";
}

Creature::Creature(std::string name) {
	this->name = name;
}

std::string Creature::get_name() {
	return this->name;
}

short int Creature::get_statistic(char statistic, bool is_permanent){
	return this->stats[statistic][is_permanent];
};

//DO NOT use to change relationship. TODO Find safer way to implement this
short int Creature::change_statistic(char statistic, bool is_permanent, short int adjustment){
    this->stats[statistic][is_permanent] = this->stats[statistic][is_permanent] + adjustment;
    return this->stats[statistic][is_permanent];
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

//TODO add guarunteed flag to skip attack roll
void Creature::attack(short int attack, short int damage) {
    //TODO Replace with armour class once it's implemented
	if (attack > this->stats[DEXTERITY][TEMPORARY]) {
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

float Creature::get_luck() {
    // This might make luck stacking a de facto build
    std::uniform_real_distribution<float> gen(this->stats[LUCK][TEMPORARY] * 0.09, this->stats[LUCK][TEMPORARY] * 0.11);
    return gen(this->rng_seed);
}

// TODO Generate names
Human::Human() {
	this->name = "Human";
}

Goblin::Goblin() {
	this->name = "Goblin";
}
