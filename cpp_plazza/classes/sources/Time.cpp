//
// Time.cpp for plazza in /home/girard_r/Documents/plazza
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Fri Apr 24 18:41:18 2015 Aurélien GIRARDEAU
// Last update Sun Apr 26 18:03:59 2015 Aurélien GIRARDEAU
//

#include "Time.hh"

Time::Time(SafeStock* stock, std::deque<Cook*>* cooks, useconds_t& wait)
  : _stock(stock), _cooks(cooks), _isFinished(false), _wait(wait)
{
}

Time::~Time()
{
}

void				Time::setFinished()
{
  ScopedLock			lock(_mutexFinished);

  _isFinished = true;
}

bool				Time::isFinished()
{
  ScopedLock			lock(_mutexFinished);

  return (_isFinished);
}

bool				Time::isActive()
{
  std::deque<Cook*>::iterator	it;

  for (it = _cooks->begin(); it != _cooks->end(); ++it)
    {
      if ((*it)->checkActive())
	return true;
    }
  return false;
}

void				Time::start()
{
  useconds_t			timeout = 0;
  useconds_t			refresh = 0;

  while (1)
    {
      if (isActive())
	timeout = 0;
      timeout += 1000;
      refresh += 1000;
      usleep(1000);
      if (timeout >= 5000000)
	{
	  setFinished();
	  break ;
	}
      if (refresh >= _wait)
	{
	  _stock->refresh();
	  refresh = 0;
	}
    }
}
