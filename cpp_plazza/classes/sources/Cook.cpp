//
// Cook.cpp for plazza in /home/girard_r/Documents/plazza
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Fri Apr 24 17:03:04 2015 Aurélien GIRARDEAU
// Last update Sun Apr 26 18:21:52 2015 Aurélien GIRARDEAU
//

#include "Cook.hh"

Cook::Cook(SafeQueue<t_pack>* orders, SafeStock* stock,
	   SafeFinished<t_pack>* ordersComplete, useconds_t time)
  : _active(false),
    _orders(orders),
    _stock(stock),
    _ordersComplete(ordersComplete),
    _timeMultiplier(time),
    _corresp()
{
}

Cook::~Cook()
{
}

void					Cook::setActive(bool set)
{
  ScopedLock				lock(_mutexActive);

  _active = set;
}

bool					Cook::checkActive()
{
  ScopedLock				lock(_mutexActive);

  return _active;
}

bool					Cook::getIngrList()
{
  setActive(false);
  if (!(_pizza = _orders->pop()))
    return false;
  std::cout << "cook took a pizza" << std::endl;
  setActive(true);
  _reciepe = _corresp.getReciepeFromCode(_pizza->pizza);
  return true;
}

void					Cook::retrieveFromStock()
{
  std::map<e_ingr, int>::iterator	it;

  for (it = _reciepe.begin(); it != _reciepe.end(); ++it)
    {
      while (it->second != 0)
	{
	  if (!_stock->get(it->first))
	    continue ;
	  it->second -= 1;
	}
    }
  std::cout << "cook took all ingredients" << std::endl;
}

void					Cook::cookOrder()
{
  sleep(_corresp.getTimeFromCode(_pizza->pizza) * _timeMultiplier);
}

void					Cook::sendCompleteOrder()
{
  _pizza->msg = ORDER_COMPLETE;
  _ordersComplete->push(*_pizza);
  std::cout << "cook finished a pizza" << std::endl;
}

void					Cook::start()
{
  while (42)
    {
      try
	{
	  if (!getIngrList())
	    continue ;
	  retrieveFromStock();
	  cookOrder();
	  sendCompleteOrder();
	}
      catch (PlazzaError::ClosingThreads error)
	{
	  break ;
	}
    }
}
