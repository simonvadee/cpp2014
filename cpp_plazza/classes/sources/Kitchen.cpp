//
// Kitchen.cpp for plazza in /home/girard_r/Documents/plazza
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Fri Apr 24 16:53:50 2015 Aurélien GIRARDEAU
// Last update Sun Apr 26 18:19:01 2015 Aurélien GIRARDEAU
//

#include "Kitchen.hh"

Kitchen::Kitchen(float multiplier, int nbCooks, useconds_t wait, NamedPipe *pipe)
  : _multiplier(multiplier),
    _nbCooks(nbCooks),
    _wait(wait),
    _mutexOrders(),
    _mutexStock(),
    _mutexGet(),
    _condOrders(&_mutexOrders),
    _condStock(&_mutexStock),
    _orders(new SafeQueue<t_pack>(&_mutexOrders, &_condOrders)),
    _ordersComplete(new SafeFinished<t_pack>(&_mutexOrdersComplete)),
    _ingr(new SafeStock(&_mutexStock, &_condStock)),
    _time(NULL),
    _thTime(NULL),
    _pipe(pipe)

{
  initConf();
}

Kitchen::~Kitchen()
{
  std::deque<Cook*>::iterator	it;

  delete _orders;
  delete _ingr;
  delete _thTime;
  delete _time;
  for (it = _cooks.begin(); it != _cooks.end(); ++it)
    delete (*it);
}

void					Kitchen::initConf()
{
  Cook*					newCook;
  Thread<Cook>*				newThread;

  for (int i = 0; i < _nbCooks; ++i)
    {
      newCook = new Cook(_orders, _ingr, _ordersComplete, _multiplier);
      _cooks.push_front(newCook);
      newThread = new Thread<Cook>(newCook);
      _thCooks.push_front(newThread);
    }
  _time = new Time(_ingr, &_cooks, _wait);
  _thTime = new Thread<Time>(_time);
}

void					Kitchen::startCooks()
{
  std::deque<Thread<Cook>* >::iterator	it;

  for (it = _thCooks.begin(); it != _thCooks.end(); ++it)
    (*it)->start();
}

void					Kitchen::signalDeath()
{
  _orders->setFinished();
  _condOrders.broadcast();
}

void					Kitchen::closeProcess()
{
  std::deque<Thread<Cook>* >::iterator	it;

  for (it = _thCooks.begin(); it != _thCooks.end(); ++it)
    (*it)->wait();
  exit(0);
}

void					Kitchen::answerState()
{
  std::cout << "lol" << std::endl;
}

void					Kitchen::listenReception()
{
  t_pack				data;

  _pipe->receive(&data);
  _orders->push(data);
  std::cout << "pushed pizza " << data.size << std::endl;
  usleep(10);
}

void					Kitchen::sendReception()
{
  t_pack				*ret = NULL;

  std::cout << "attempt sending" << std::endl;
  while (!_ordersComplete->tryPop(&ret))
    {
      std::cout << "sending order finished" << std::endl;
      _pipe->send(*ret);
    }
}

void					Kitchen::startTime()
{
  _thTime->start();
}

void					Kitchen::start()
{
  fd_set				bitfield;
  struct timeval			timeout;

  startTime();
  startCooks();
  timeout.tv_sec = 0;
  timeout.tv_usec = 1;
  FD_ZERO(&bitfield);
  FD_SET(_pipe->getReceive(), &bitfield);
  while (_time->isFinished())
     {
       select(_pipe->getReceive() + 1, &bitfield, NULL, NULL, &timeout);
       if (FD_ISSET(_pipe->getReceive(), &bitfield))
	 {
	   listenReception();
	 }
       sendReception();
     }
  signalDeath();
  closeProcess();
}
