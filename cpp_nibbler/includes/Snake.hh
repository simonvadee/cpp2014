//
// snake.hh for nibbler in /home/girard_r/rendu/cpp_nibbler
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue Mar 24 16:10:05 2015 Aurélien GIRARDEAU
// Last update Wed Mar 25 17:35:48 2015 Aurélien GIRARDEAU
//

#ifndef NIBBLER_H_
# define NIBBLER_H_

# include <map>
# include <utility>
# include <deque>
# include "Map.hh"
# include "Item.hh"
# include "IGui.hh"

class							Snake
{

private :
  e_way							_actualWay;
  std::map<e_way, std::pair<unsigned int, unsigned int> >		_moveAlias;
  std::deque<std::pair<unsigned int, unsigned int> >	_snake;
  unsigned int						_speed;
  bool							_dead;

private:
  bool							eat(Item *item, Map &map, std::pair<unsigned int, unsigned int> tmp, IGui& gui);
  void							getNewHead(e_way direction);
  void							initSnake(unsigned, unsigned, IGui&);
  bool							hurtMyself() const;
  bool							hitWall(Map const& map) const;
  void							revertQueue();
  void							findNewWay();

public:
  Snake(unsigned int width, unsigned int height, IGui &gui);
  ~Snake();

  bool							move(e_way direction, Map &map, IGui& gui);
  int							getSpeed() const;
  std::deque<std::pair<unsigned , unsigned > >		getQueue() const;
  e_way							getWay() const;
  bool							isAlive() const;
};

#endif
