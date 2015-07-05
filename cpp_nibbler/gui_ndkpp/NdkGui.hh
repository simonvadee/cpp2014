//
// NdkGui.hh for libndknib in /home/girard_r/rendu/cpp_nibbler/gui_ndkpp
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Sat Mar 28 15:48:39 2015 Aurélien GIRARDEAU
// Last update Mon Mar 30 15:37:57 2015 Aurélien GIRARDEAU
//

#ifndef LIBNDK_HH_
# define LIBNDK_HH_

# include <unistd.h>
# include <sys/ioctl.h>
# include <sstream>
# include <iostream>
# include <string>
# include <cstdlib>
# include <map>
# include "IGui.hh"
# include "ncurses.h"

class				NdkGui : public IGui
{
private :
  int				_maxheight;
  int				_maxwidth;
  char				_snakechar;
  char				_border;
  char				_empty;
  std::map<int, e_way>		_which;
  std::map<e_itemType, char>	_items;

public :
  NdkGui();
  ~NdkGui();
  virtual bool			initGui(int width, int height);
  virtual e_way			getEvent();
  virtual bool			moveSnake(std::pair<unsigned int, unsigned int> from,
				  std::pair<unsigned int, unsigned int> to,
				  bool eat);
  virtual bool			addItem(std::pair<int, int> from, e_itemType type);
  virtual void			gameOver(size_t size);
};

extern "C" IGui*		getInstance();

#endif
