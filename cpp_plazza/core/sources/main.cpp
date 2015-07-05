//
// main.cpp for test in /home/girard_r/Documents/plazza/tp
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Thu Apr 16 16:26:13 2015 Aurélien GIRARDEAU
// Last update Thu Apr 23 12:10:38 2015 Aurélien GIRARDEAU
//

#include <cstdlib>
// #include <X11/Xlib.h>
#include "Thread.hh"
#include "ScopedLock.hh"
#include "Mutex.hh"
#include "Reception.hh"

int		main(int ac, char **av)
{
  if (ac != 4)
    {
      printf("usage : ./plazza mult nb_cook refill\n");
      return (1);
    }
  Reception	reception(std::atof(av[1]), std::atoi(av[2]), std::atoi(av[3]));

  reception.run();
  return (0);
}
