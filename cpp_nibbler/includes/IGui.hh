//
// IGui.hh for nibbler in /home/roman/Documents/dev/cpp_nibbler
//
// Made by grout_r
// Login   <roman@epitech.net>
//
// Started on  Tue Mar 24 15:55:52 2015 grout_r
// Last update Wed Apr  1 13:40:40 2015 grout_r
//

#ifndef IGUI_HH_
# define IGUI_HH_

# include <utility>
# include <stddef.h>

typedef enum
  {
    NOTHING,
    TOP,
    RIGHT,
    DOWN = -1,
    LEFT = -2,
    EXIT = 42
  }	e_way;

typedef enum
  {
    GROW,
    SPEED,
    INVERT
  }	e_itemType;

class			IGui
{
public :
  virtual		~IGui() {};
  virtual e_way		getEvent() = 0;
  virtual bool		initGui(int x, int y) = 0;
  virtual bool		moveSnake(std::pair<unsigned int, unsigned int> from,
				  std::pair<unsigned int, unsigned int> to, bool eat) = 0;
  virtual bool		addItem(std::pair<int, int> from, e_itemType type) = 0;
  virtual void		gameOver(size_t size) = 0;
};

#endif /* !IGUI_HH_ */
