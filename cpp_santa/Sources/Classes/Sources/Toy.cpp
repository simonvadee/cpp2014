//
// Toy.cpp for Toy.cpp in /home/theoph_t/test
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 11:10:41 2015 Titouan Theophile
// Last update Sun Jan 18 06:25:20 2015 Titouan Theophile
//

#include "Toy.hh"

Toy::Toy(std::string const & title): Object(title)
{

}

objectType	Toy::getType() const
{
  return TOY;
}

Toy::~Toy()
{

}
