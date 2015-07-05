//
// SafeStock.cpp for plazza in /home/girard_r/Documents/plazza
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Sat Apr 25 15:54:42 2015 Aurélien GIRARDEAU
// Last update Sun Apr 26 18:11:50 2015 Aurélien GIRARDEAU
//

#include "Exceptions.hpp"
#include "SafeStock.hh"

SafeStock::SafeStock(Mutex* mutex, CondVar* cond)
  : _mutex(mutex), _cond(cond)
{
  _queue[DOE] = 5;
  _queue[TOMATO] = 5;
  _queue[GRUYERE] = 5;
  _queue[HAM] = 5;
  _queue[MUSHROOMS] = 5;
  _queue[STEAK] = 5;
  _queue[EGGPLANT] = 5;
  _queue[GOAT_CHEESE] = 5;
  _queue[CHIEF_LOVE] = 5;
}

SafeStock::~SafeStock(void)
{
}

void		SafeStock::refresh()
{
  ScopedLock	lock(*_mutex);
  std::map<e_ingr, int>::iterator	it;

  for (it = _queue.begin(); it != _queue.end(); ++it)
    it->second += 1;
  _cond->broadcast();
}

bool		SafeStock::tryGet(e_ingr value)
{
  std::map<e_ingr, int>::iterator	it;

  if ((it = _queue.find(value)) != _queue.end() && it->second > 0)
    {
      it->second -= 1;
      return (true);
    }
  return (false);
}

bool					SafeStock::get(e_ingr value)
{
  ScopedLock				lock(*_mutex);
  std::map<e_ingr, int>::iterator	it;

  if ((it = _queue.find(value)) == _queue.end() || it->second == 0)
    _cond->wait();

  if (!tryGet(value))
    return false;
  return true;
}
