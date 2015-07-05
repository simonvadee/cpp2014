//
// Map.cpp for nibbler in /home/roman/Documents/dev/cpp_nibbler
//
// Made by grout_r
// Login   <roman@epitech.net>
//
// Started on  Tue Mar 24 16:07:31 2015 grout_r
// Last update Tue Mar 24 16:07:36 2015 grout_r
//

# include "Map.hh"

Map::Map(unsigned int x, unsigned int y)
{
  this->_mapSize = std::make_pair(x, y);
}

Map::~Map()
{
  for (std::deque<Item*>::iterator it = _itemList.begin(); it!= _itemList.end(); ++it)
    delete *it;
  _itemList.clear();
}

void						Map::eraseItem(Item *item)
{
  for (std::deque<Item*>::iterator it = _itemList.begin(); it!= _itemList.end(); ++it)
    {
      if (*it == item)
	{
	  delete *it;
	  _itemList.erase(it);
	  return ;
	}
    }
}

void						Map::addItem(e_itemType type, IGui& gui, std::deque<std::pair<unsigned int, unsigned int> > const& snake)
{
  unsigned int					x = rand() % _mapSize.first;
  unsigned int					y = rand() % _mapSize.second;

  while (isInQueue(std::make_pair(x, y), snake)
	 || isAnItem(std::make_pair(x, y)))
    {
      x = rand() % _mapSize.first;
      y = rand() % _mapSize.second;
    }
  this->_itemList.push_back(new Item(type, x, y));
  gui.addItem(std::make_pair(x, y), type);
}

void						Map::manageBonus(std::deque<std::pair<unsigned int, unsigned int> > const& queue, IGui *gui)
{
  int	score = queue.size() - 4;

  if (score > 0 && score % 10 == 0)
    {
      addItem(INVERT, *gui, queue);
      return ;
    }
  else if (score > 0 && score % 5 == 0)
    {
      addItem(SPEED, *gui, queue);
      return ;
    }
}

Item						*Map::isAnItem(std::pair<unsigned, unsigned> request)
{
  for(unsigned int i = 0; i != this->_itemList.size(); i++)
    {
      if (this->_itemList[i]->getPos() == request)
	return (this->_itemList[i]);
    }
  return (NULL);
}

bool						Map::isInQueue(std::pair<unsigned int, unsigned int> const& elem, std::deque<std::pair<unsigned int, unsigned int> > const& queue) const
{
 for (unsigned int i = 0; i != queue.size(); i++)
    {
      if (elem == queue[i])
	return true;
    }
  return false;
}

std::pair<unsigned int , unsigned int>		Map::getSize() const
{
  return _mapSize;
}
