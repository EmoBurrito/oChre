#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include "thing.h"

class Creature: public Thing
{
    private:
    protected:
    public:
        void attack(Creature *targetPointer); //Attempts to attack a target. If we don't pass a pointer, it passes by value instead of reference
        void ouch(int damageInflicted); //Takes damage

        //Getters
        string getName();
        int getStrength();
        int getHealth();
};



#endif //CREATURE_H
