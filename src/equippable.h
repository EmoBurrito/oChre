#ifndef EQUIPPABLE_H
#define EQUIPPABLE_H

#include <string>
#include "item.h"

class Equippable: public Item
{
    private:

    protected:

    public:
//        Equippable();
};

class Head: public Equippable
{
    private:

    protected:

    public:
        Head(std::string nameParam);
};

class Torso : public Equippable
{
    private:

    protected:

    public:
        Torso();
};

class Hand: public Equippable
{
    private:

    protected:

    public:
        Hand(std::string nameParam);
};

class Ring: public Equippable
{
    private:

    protected:

    public:
        Ring();
};

class Legs: public Equippable
{
    private:

    protected:

    public:
        Legs();
};

class Feet: public Equippable
{
    private:

    protected:

    public:
        Feet();
};

#endif //EQUIPPABLE_H
