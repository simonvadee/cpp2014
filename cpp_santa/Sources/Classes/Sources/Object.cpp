//
// Object.cpp for santa in /home/theoph_t/test
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 17:28:12 2015 Titouan Theophile
// Last update Sun Jan 18 03:57:44 2015 Titouan Theophile
//

#include "Object.hh"

Object::Object(std::string const & title) : _title(title)
{
}

Object::~Object()
{
}

std::string const&	Object::getTitle() const
{
  return _title;
}
