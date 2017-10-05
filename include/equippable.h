#ifndef EQUIPPABLE_H
#define EQUIPPABLE_H

#include <string>
#include "item.h"

///Abstract class for items that can be worn or held.
class Equippable: public Item
{
    private:

    protected:

    public:
//        Equippable();
};

///Instantiable head gear like helmets, hats, or crowns.
class Head: public Equippable
{
    private:

    protected:

    public:
        Head(std::string nameParam);
};

///Instantiable chest protection like (studded) leather or mail
class Torso : public Equippable
{
    private:

    protected:

    public:
        Torso();
};

///Instantiable gloves or gauntlets
class Hand: public Equippable
{
    private:

    protected:

    public:
        Hand(std::string nameParam);
};

///Instantiable rings to be worn on digits
class Ring: public Equippable
{
    private:

    protected:

    public:
        Ring();
};

///Instantiable leggings like (studded) leather or mail
class Legs: public Equippable
{
    private:

    protected:

    public:
        Legs();
};

///Instantiable footwear like boots
class Feet: public Equippable
{
    private:

    protected:

    public:
        Feet();
};

#endif //EQUIPPABLE_H
