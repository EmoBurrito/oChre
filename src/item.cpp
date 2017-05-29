/**

*/

#include "item.h"
#include "equipable.h"

Item::Item(std::string nameParam)
:name(nameParam)
{
};

std::string Item::getName()
{
  return "sword";
};
