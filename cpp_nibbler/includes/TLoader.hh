//
// TLoader.hh for nibbler in /home/girard_r/rendu/cpp_nibbler/sources
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Wed Mar 25 19:54:15 2015 Aurélien GIRARDEAU
// Last update Wed Mar 25 21:52:51 2015 Aurélien GIRARDEAU
//

#ifndef GLOADER_HH_
# define GLOADER_HH_

# include <iostream>
# include "IGui.hh"

template <typename T>
class				TLoader
{
public :
  TLoader();
  ~TLoader();
  T*				getInstance(char* gui);
};

template class			TLoader<IGui>;

#include "TLoader.cpp"

#endif /* !GLOADER_HH_ */
