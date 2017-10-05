#include <iostream>
#include "../include/party.h"

/**
 * Not sure if I want to instantiate then fill, or require characters to instantiate. Perhaps at least one?
 */
Party::Party()
{
    for (int denomination = 0; denomination < sizeof(this->purse)/sizeof(this->purse[0]))
    {
        this->purse[denomination] = 0;
    }
//    this->purse[0] = 0;
};

/**
 * TO BE IMPLEMENTED. Loots a target create.
 *
 * Creature must first be defeated.
 */
void Party::loot(Creature target) {
    //Check to see if creature has actually been defeated.
    //If they have, get some gold, chance at an item drop, then free from memory.
    //Look up "delete" command
}