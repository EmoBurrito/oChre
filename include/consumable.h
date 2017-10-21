#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <string>
#include "item.h"

///Abstract class for "one time use" items, such as potions or berries
class Consumable: public Item
{
private:

protected:

public:
    Consumable();  //To Be removed once extended. Here simply for testing in the mean time.
};

#endif //CONSUMABLE_H
