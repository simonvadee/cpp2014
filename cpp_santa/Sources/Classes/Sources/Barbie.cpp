//
// Barbie.cpp for Barbie.cpp in /home/theoph_t/test
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 11:10:41 2015 Titouan Theophile
// Last update Sun Jan 18 05:50:48 2015 Alexandre Tea
//

#include "Barbie.hh"

Barbie::Barbie() : Toy("Barbie")
{
}

Barbie::Barbie(std::string const & title) : Toy(title)
{
}

Barbie::Barbie(Barbie const& copy) : Toy(copy._title)
{
}

Barbie::~Barbie()
{
}

Barbie*	Barbie::clone() const
{
  return (new Barbie(_title));
}

void Barbie::isTaken() const
{
  std::cout << "playmobil, en avant les histoires !" << std::endl;
}



bool	Barbie::getIsOpen() const
{
  return false;
}

bool Barbie::wrapMeThat(Object *toy)
{
  (void) toy;
  return false;
}

Object	*Barbie::openMe()
{
  return NULL;
}

bool	Barbie::closeMe()
{
  return false;
}

bool	Barbie::isEmpty() const
{
  return false;
}

Object	*Barbie::getStock() const
{
  return NULL;
}

Barbie&	Barbie::operator=(Object& copy)
{
  this->_title = copy.getTitle();
  return *this;
}
