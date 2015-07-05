//
// Playmobil.cpp for Playmobil.cpp in /home/theoph_t/test
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 11:10:41 2015 Titouan Theophile
// Last update Sun Jan 18 05:50:04 2015 Alexandre Tea
//

#include "Playmobil.hh"

Playmobil::Playmobil() : Toy("Playmobil")
{
}

Playmobil::Playmobil(std::string const & title) : Toy(title)
{
}

Playmobil::Playmobil(Playmobil const& copy) : Toy(copy._title)
{
}

Playmobil::~Playmobil()
{
}

Playmobil*	Playmobil::clone() const
{
  return (new Playmobil(_title));
}

void Playmobil::isTaken() const
{
  std::cout << "playmobil, en avant les histoires !" << std::endl;
}



bool	Playmobil::getIsOpen() const
{
  return false;
}

bool Playmobil::wrapMeThat(Object *toy)
{
  (void) toy;
  return false;
}

Object	*Playmobil::openMe()
{
  return NULL;
}

bool	Playmobil::closeMe()
{
  return false;
}

bool	Playmobil::isEmpty() const
{
  return false;
}

Object	*Playmobil::getStock() const
{
  return NULL;
}

Playmobil&	Playmobil::operator=(Object& copy)
{
  this->_title = copy.getTitle();
  return *this;
}
