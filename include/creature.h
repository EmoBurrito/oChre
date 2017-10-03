#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include "thing.h"
#include "equippable.h"

class Creature: public Thing
{
    private:
    protected:
    public:
        void attack(Creature *targetPointer); //Attempts to attack a target. If we don't pass a pointer, it passes by value instead of reference
        void ouch(int damageInflicted); //Takes damage. //TODO Why is this public?

        //Getters
        string getName();
        int getStrength();
        int getHealth();
};

class Humanoid: public Creature
{
    private:
    protected:
        //Equipment
        Head * head; /**< Hat, helmet, crown, or tiara. */
        Torso * torso; /**< (Studded) leather, chain mail, split mail, plate mail. */
        Hand * lHand; /**< Gloves or gauntles will be sold as pairs from merchants and often be found as pairs while adventuring.
                      /**< However, this doesn't mean that players can't mix and match. */
        Hand * rHand; /**< Same idea as the left hand, but this one is the right. */
        //Ring rings [20] = {}; /**< A ring for every finger and toe, because why not? */
        Legs * legs; /**< Pants. Similar idea to torso but for those long dangly arms coming out of your hips. */
        Feet * feet; /**< Boots, shoes. */
    public:
};

class Rodent: public Creature
{
    private:
    protected:
    public:
};

class Canine: public Creature
{
    private:
    protected:
    public:
};

class Feline: public Creature
{
    private:
    protected:
    public:
};

class Reptile: public Creature
{
    private:
    protected:
    public:
};

class Undead: public Creature
{
    private:
    protected:
    public:
};

#endif //CREATURE_H
