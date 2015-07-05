//
// Teddy.cpp for Teddy.cpp in /home/theoph_t/test
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 11:10:41 2015 Titouan Theophile
//

#include "Teddy.hh"

Teddy::Teddy() : Toy("Teddy")
{
}

Teddy::Teddy(std::string const & title) : Toy(title)
{
}

Teddy::Teddy(Teddy& copy) : Toy(copy._title)
{
}

Teddy::~Teddy()
{
}

Teddy     *Teddy::clone() const
{
  return (new Teddy(_title));
}

void Teddy::isTaken() const
{
  std::cout << "gra hu" << std::endl;
}

bool	Teddy::getIsOpen() const
{
  return false;
}

bool Teddy::wrapMeThat(Object *toy)
{
  (void) toy;
  return false;
}

Object	*Teddy::openMe()
{
  return NULL;
}

bool	Teddy::closeMe()
{
  return false;
}

bool	Teddy::isEmpty() const
{
  return false;
}

Object	*Teddy::getStock() const
{
  return NULL;
}

Teddy&	Teddy::operator=(Object& copy)
{
  this->_title = copy.getTitle();
  return *this;
}
