//
// main.cpp for abstractvm in /home/girard_r/rendu/cpp_abstractvm
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue Feb 24 15:43:45 2015 Aurélien GIRARDEAU
// Last update Thu Feb 26 17:13:04 2015 Aurélien GIRARDEAU
//

#include <stdint.h>
#include "Errors.hpp"
#include "pileMachine.hh"
#include "Operand.hh"

int		main(int ac, char **av)
{
  PileMachine	VM;
  char		*file;

  if (ac <= 2)
    {
      file = (ac == 1 ? NULL : av[1]);
      try
	{
	  VM.run(file);
	}
      catch (MainException e)
	{
	  std::cout << "Abstact VM report exception : " << e.what() << std::endl;
	  return 1;
	}
    }
  else
    std::cout << "USAGE: ./avm (filename)" << std::endl
	      << "If filename is not given, read from the standard input" << std::endl;
  return 0;
}
