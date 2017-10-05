#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "thing.h"

using namespace std;

///Abstract class representing inanimate objects.
class Item: public Thing
{
private:

protected:
	string name;
	unsigned int value;
	unsigned int condition; //TODO Consider maybe float?
	unsigned int weight;

public:
	string getName();
};

#endif //ITEM_H