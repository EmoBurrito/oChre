#include <string>
#include "equippable.h"

Equippable::Equippable()
{
    equipped = false;
};

Equippable::equipItem(bool equipItem)
{
    equipped = equipItem;
}

Hand::Hand(std::string nameParam)
{
    this->name = nameParam;
}   