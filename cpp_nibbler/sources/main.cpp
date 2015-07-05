//
// main.cpp for nibbler in /home/roman/Documents/dev/cpp_nibbler
//
// Made by grout_r
// Login   <roman@epitech.net>
//
// Started on  Tue Mar 24 15:55:38 2015 grout_r
// Last update Thu Apr  2 13:21:39 2015 grout_r
//

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "Snake.hh"
#include "Map.hh"
#include "TLoader.hh"

void		loop(IGui *gui, unsigned int width, unsigned int height)
{
  e_way			ret;
  Map			map(width, height);
  Snake			snake(width, height, *gui);
  unsigned int		i = 0;
  bool			change_direction;

  map.addItem(GROW, *gui, snake.getQueue());
  while (snake.isAlive())
    {
      change_direction = false;
      if ((ret = gui->getEvent()))
	change_direction = snake.move(ret, map, *gui);
      if (ret == EXIT)
	break;
      else if (change_direction == false)
	{
	  if (i++ == 20)
	    {
	      snake.move(NOTHING, map, *gui);
	      i = 0;
	    }
	}
      usleep(snake.getSpeed());
    }
  gui->gameOver(snake.getQueue().size() - 4);
}

int		main(int ac, char **av)
{
  unsigned int		height;
  unsigned int		width;
  TLoader<IGui>		loader;
  IGui			*gui;

  if (ac != 4)
    {
      std::cerr << "Usage : >./nibbler width height lib_name.so" << std::endl;
      return (1);
    }
  srand(time(NULL));
  height = atoi(av[2]);
  width = atoi(av[1]);
  if ((gui = loader.getInstance(av[3])) == NULL)
    return (1);
  else if (!gui->initGui(width, height))
    {
     std::cerr << "Error while loading gui" << std::endl;
     return 1;
    }
  loop(gui, width, height);
  delete gui;
  return 0;
}
