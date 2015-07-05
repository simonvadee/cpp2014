//
// Map.hh for nibbler in /home/roman/Documents/dev/cpp_nibbler
//
// Made by grout_r
// Login   <roman@epitech.net>
//
// Started on  Tue Mar 24 16:01:56 2015 grout_r
// Last update Tue Mar 24 16:13:14 2015 grout_r
//

#ifndef MAP_HH_
# define MAP_HH_

# include <stdlib.h>
# include <iostream>
# include <stddef.h>
# include <deque>
# include "Item.hh"
# include "IGui.hh"

class						Map
{

private:
  std::pair<unsigned int , unsigned int>	_mapSize;
  std::deque<Item *>				_itemList;

public:
  Map(unsigned int x, unsigned int y);
  ~Map();

  void						manageBonus(std::deque<std::pair<unsigned int, unsigned int> > const& queue, IGui *gui);
  void						eraseItem(Item *item);
  void						addItem(e_itemType type, IGui &gui,
							std::deque<std::pair<unsigned int, unsigned int> > const& snake);
  Item						*isAnItem(std::pair<unsigned, unsigned> request);
  bool						isInQueue(std::pair<unsigned int, unsigned int> const& elem, std::deque<std::pair<unsigned int, unsigned int> > const& queue) const;
  std::pair<unsigned int , unsigned int>	getSize() const;
};

#endif
