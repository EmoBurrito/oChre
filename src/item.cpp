/**

*/

#include "item.h"

std::string Item::getName()
{
  return name;
};

///////////////
// EQUIPABLE //
///////////////
Equipable::Equipable()
{

};

Hand::Hand(std::string nameParam)
{
  this->name = nameParam;
}

////////////////
// CONSUMABLE //
////////////////
Consumable::Consumable()
{

};