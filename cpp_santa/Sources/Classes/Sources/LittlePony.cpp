//
// LittlePony.cpp for LittlePony.cpp in /home/theoph_t/test
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 11:10:41 2015 Titouan Theophile
// Last update Sun Jan 18 06:34:02 2015 Titouan Theophile
//

#include "LittlePony.hh"

LittlePony::LittlePony() : Toy("Little Pony")
{
}

LittlePony::LittlePony(std::string const & title) : Toy(title)
{
}

LittlePony::LittlePony(LittlePony const& copy) : Toy(copy._title)
{
}

LittlePony::~LittlePony()
{
}

LittlePony*	LittlePony::clone() const
{
  return (new LittlePony(_title));
}

void LittlePony::isTaken() const
{
  std::cout << "yo man" << std::endl;
}



bool	LittlePony::getIsOpen() const
{
  return false;
}

bool LittlePony::wrapMeThat(Object *toy)
{
  (void) toy;
  return false;
}

Object	*LittlePony::openMe()
{
  return NULL;
}

bool	LittlePony::closeMe()
{
  return false;
}

bool	LittlePony::isEmpty() const
{
  return false;
}

Object	*LittlePony::getStock() const
{
  return NULL;
}

LittlePony&	LittlePony::operator=(Object& copy)
{
  this->_title = copy.getTitle();
  return *this;
}
