//
// Created by roman on 25/03/15.
//

# include <utility>
# include "Item.hh"

Item::Item(e_itemType type, unsigned x , unsigned y) : _type(type)
{
  this->_pos = std::make_pair(x, y);
}

Item::~Item()
{

}

std::pair<unsigned, unsigned>		Item::getPos() const
{
  return this->_pos;
}

e_itemType				Item::getType() const
{
  return _type;
}
