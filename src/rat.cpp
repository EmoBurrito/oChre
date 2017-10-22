#include <iostream>
#include "../include/rat.h"

using namespace std;

/**
 * Rat constructor.
 */
Rat::Rat(
        int health,
        int mana,
        int accuracy,
        int strength,
        int speed,
        int intellect,
        int wisdom,
        int luck) {
    this->health = health;
    this->mana = mana;
    this->accuracy = accuracy;
    this->strength = strength;
    this->speed = speed;
    this->intellect = intellect;
    this->wisdom = wisdom;
    this->luck = luck;

    this->name = "Rat"; //TODO Could we set this statically for all rats to save memory?
}

Rat::~Rat() {
    cout << "The " << getName() << " has been looted!\n";
}

/**
 * Giant Rat constructor.
 */
GiantRat::GiantRat(
        int health,
        int mana,
        int accuracy,
        int strength,
        int speed,
        int intellect,
        int wisdom,
        int luck) {
    this->health = health;
    this->mana = mana;
    this->accuracy = accuracy;
    this->strength = strength;
    this->speed = speed;
    this->intellect = intellect;
    this->wisdom = wisdom;
    this->luck = luck;

    this->name = "Giant Rat";
}


GiantRat::~GiantRat() {
    cout << "The " << getName() << " has been looted!\n";
}