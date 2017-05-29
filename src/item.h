#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
	private:
		std::string name;
		unsigned int value;
		unsigned int condition; //TODO Consider maybe float?
		unsigned int weight;

	protected:

	public:
		Item(std::string nameParam);
		std::string getName();
};

#endif //ITEM_H
