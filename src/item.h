#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
	private:

	protected:
		std::string name;
		unsigned int value;
		unsigned int condition; //TODO Consider maybe float?
		unsigned int weight;

	public:
		std::string getName();
};

class Equipable : public Item
{
private:

protected:

public:
	Equipable();
};

class Head : public Equipable
{
private:

protected:

public:
	Head(std::string nameParam);
};

class Torso : public Equipable
{
private:

protected:

public:
	Torso();
};

class Hand : public Equipable
{
private:

protected:

public:
	Hand(std::string nameParam);
};

class Ring : public Equipable
{
private:

protected:

public:
	Ring();
};

class Legs : public Equipable
{
private:

protected:

public:
	Legs();
};

class Feet : public Equipable
{
private:

protected:

public:
	Feet();
};

////////////////
// CONSUMABLE //
////////////////
class Consumable
{
private:

protected:

public:
	Consumable();
};

#endif //ITEM_H