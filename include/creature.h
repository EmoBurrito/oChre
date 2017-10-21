#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <map>
#include <vector>
#include "thing.h"
#include "equippable.h"

using namespace std;

///Abstract parent class to abstract creature types.
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

///Abstract class for bipedal, two-armed creatures.
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

///Abstract Rodent. Consider combining into quadruped.
class Rodent: public Creature
{
private:
protected:
public:
};

///Abstract Canine. Consider combining into quadruped.
class Canine: public Creature
{
private:
protected:
public:
};

///Abstract Feline. Consider combining into quadruped.
class Feline: public Creature
{
private:
protected:
public:
};

///Abstract Reptile. Consider combining into quadruped.
class Reptile: public Creature
{
private:
protected:
public:
};

///Abstract Undead. Consider making a type like "Undead Human" or "Undead Goblin", etc.
class Undead: public Creature
{
private:
protected:
public:
};

#endif //CREATURE_H
