//
// Box.cpp for Santa in /home/theoph_t/test
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 15:58:04 2015 Titouan Theophile
// Last update Sun Jan 18 06:37:36 2015 Titouan Theophile
//

#include "Box.hh"
#include "Teddy.hh"
#include "LittlePony.hh"

Box::Box() : Wrap("Box"), _isOpen(true)
{
}

Box::Box(Box& copy) : Wrap(copy), _isOpen(copy._isOpen)
{

}

objectType            Box::getType() const
{
  return (BOX);
}


Box     *Box::clone() const
{
  return (new Box());
}


bool	Box::getIsOpen() const
{
  return _isOpen;
}

bool Box::wrapMeThat(Object *toy)
{
  if (_isOpen == false || _stock != NULL)
    return false;
  _stock = toy;
  _isEmpty = false;
  return true;
}

Object	*Box::openMe()
{
  Object *tmp = _stock;
  _isOpen = true;
  _isEmpty = true;
  _stock = NULL;
  return tmp;
}

bool	Box::closeMe()
{
  if (_isOpen == false)
    return false;
  _isOpen = false;
  return true;
}

Box&          Box::operator=(Box const& copy)
{
  _title = copy._title;
  _isOpen = copy._isOpen;
  _isEmpty = copy._isEmpty;
  _stock = copy._stock->clone();
  return *this;
}

void	Box::isTaken() const
{
  std::cout << "Look how big is my stomach ! how empty tho..." << std::endl;
}

Box::~Box()
{
   std::cout << "The box bounces away like a boss" << std::endl;
}
