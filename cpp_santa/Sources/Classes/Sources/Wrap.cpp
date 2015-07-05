//
// Wrap.cpp for Wrap in /home/theoph_t/test
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 15:13:04 2015 Titouan Theophile
// Last update Sun Jan 18 06:25:14 2015 Titouan Theophile
//

#include "Wrap.hh"

Wrap::Wrap(std::string const & title) : Object(title), _isEmpty(true), _stock(NULL)
{
}

Wrap::~Wrap()
{
}

bool	       Wrap::isEmpty() const
{
  return (_isEmpty);
}

Object	       *Wrap::getStock() const
{
  return (_stock);
}
