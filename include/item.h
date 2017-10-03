#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "thing.h"

class Item: public Thing
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

#endif //ITEM_H