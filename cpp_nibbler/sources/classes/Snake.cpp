//
// Snake.cpp for nibbler in /home/roman/Documents/dev/cpp_nibbler
//
// Made by grout_r
// Login   <roman@epitech.net>
//
// Started on  Tue Mar 24 16:12:23 2015 grout_r
// Last update Sun Apr  5 15:21:58 2015 simon vadée
//

#include <stddef.h>
#include <iostream>
#include "Snake.hh"

void Snake::initSnake(unsigned width, unsigned height, IGui &gui)
{
  this->_snake.push_front(std::make_pair(width/2, height/2));
  this->_snake.push_front(std::make_pair((width/2) + 1, height/2));
  this->_snake.push_front(std::make_pair((width/2) + 2, height/2));
  this->_snake.push_front(std::make_pair((width/2) + 3, height/2));
  for (unsigned int i = 0; i != 4; ++i)
    gui.moveSnake(std::make_pair(0, 0), _snake[i], false);
}

Snake::Snake(unsigned int width, unsigned int height, IGui& gui)
{
  this->_speed = 10000;
  this->_dead = false;
  this->_moveAlias[TOP] = std::make_pair(0, -1);
  this->_moveAlias[RIGHT] = std::make_pair(1, 0);
  this->_moveAlias[DOWN] = std::make_pair(0, 1);
  this->_moveAlias[LEFT] = std::make_pair(-1, 0);
  initSnake(width, height, gui);
  this->_actualWay = TOP;
}

Snake::~Snake()
{
}

bool							Snake::hurtMyself() const
{
  for(unsigned int i = 1; i != this->_snake.size(); ++i)
    {
      if (_snake[0] == _snake[i])
	return (true);
    }
  return (false);
}

bool							Snake::hitWall(Map const& map) const
{
  if (_snake[0].first >= map.getSize().first
      || _snake[0].second >= map.getSize().second)
    return true;
  return false;
}

bool							Snake::move(e_way direction, Map& map, IGui &gui)
{
  std::pair<unsigned int, unsigned int>			tmp(_snake.back());
  bool							eating;

  if (direction == _actualWay)
    return false;
  else if (direction == -_actualWay)
    return false;
  else if (direction != NOTHING)
    _actualWay = direction;
  this->getNewHead(_actualWay);
  if (this->hurtMyself()
      || this->hitWall(map))
    this->_dead = true;
  eating = this->eat(map.isAnItem(_snake.front()), map, tmp, gui);
  gui.moveSnake(tmp, _snake.front(), eating);
  return true;
}

int							Snake::getSpeed() const
{
  return (this->_speed);
}

bool							Snake::eat(Item *item, Map &map, std::pair<unsigned int, unsigned int> tmp, IGui &gui)
{
  if (item == NULL)
    return false;
  (void)tmp;
  if (item->getType() == GROW)
    _snake.push_back(tmp);
  else if (item->getType() == SPEED)
    {
      _speed -= _speed / 5;
      map.eraseItem(item);
      return false;
    }
  else if (item->getType() == INVERT)
    {
      revertQueue();
      map.eraseItem(item);
      return false;
    }
  map.eraseItem(item);
  map.addItem(GROW, gui, _snake);
  map.manageBonus(_snake, &gui);
  return true;
}

e_way							Snake::getWay() const
{
  return (this->_actualWay);
}

void							Snake::findNewWay()
{
  std::pair<unsigned int, unsigned int>			last = _snake.back();
  std::pair<unsigned int, unsigned int>			before_last = _snake[_snake.size() - 2];
  std::pair<unsigned int, unsigned int>			newWay;

  newWay.first = last.first - before_last.first;
  newWay.second = last.second - before_last.second;
  for (unsigned int i = -2; i != 2; ++i)
    {
      if (newWay == _moveAlias[static_cast<e_way>(i)])
	{
	  _actualWay = static_cast<e_way>(i);
	  return ;
	}
    }
}

void							Snake::revertQueue()
{
  std::deque<std::pair<unsigned int, unsigned int> >	rev;

  for (unsigned int i = 0; i != _snake.size(); ++i)
    rev.push_front(_snake[i]);
  findNewWay();
  _snake = rev;
}

void							Snake::getNewHead(e_way direction)
{
  for (unsigned int i = _snake.size() - 1; i != 0; --i)
    _snake[i] = _snake[i - 1];
  _snake.front().first += _moveAlias[direction].first;
  _snake.front().second += _moveAlias[direction].second;
}

std::deque<std::pair<unsigned , unsigned > >		Snake::getQueue() const
{
  return this->_snake;
}

bool		Snake::isAlive() const
{
  return !(this->_dead);
}
