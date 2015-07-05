//
// Kitchen.hh for plazza in /home/girard_r/Documents/plazza
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Fri Apr 24 16:53:47 2015 Aurélien GIRARDEAU
// Last update Sun Apr 26 18:00:40 2015 Aurélien GIRARDEAU
//

#ifndef KITCHEN_HH_
# define KITCHEN_HH_

# include <unistd.h>
# include "NamedPipe.hh"
# include "Thread.hh"
# include "Correspondance.hh"
# include "SafeQueue.hh"
# include "SafeStock.hh"
# include "Cook.hh"
# include "CondVar.hh"
# include "SafeFinished.hh"
# include "Time.hh"

template class			SafeQueue<t_pack>;
template class			Thread<Cook>;
template class			Thread<Time>;
template class			SafeFinished<t_pack>;

class				Kitchen
{
private :
  float				_multiplier;
  int				_nbCooks;
  useconds_t			_wait;
  Mutex				_mutexOrders;
  Mutex				_mutexStock;
  Mutex				_mutexGet;
  Mutex				_mutexOrdersComplete;
  CondVar			_condOrders;
  CondVar			_condStock;

  SafeQueue<t_pack>*		_orders;
  SafeFinished<t_pack>*		_ordersComplete;
  std::deque<Thread<Cook>* >	_thCooks;
  std::deque<Cook*>		_cooks;
  SafeStock*			_ingr;
  Time*				_time;
  Thread<Time>*			_thTime;
  NamedPipe*			_pipe;

public :
  Kitchen(float multiplier, int, useconds_t, NamedPipe*);
  ~Kitchen();
  void				start();
  void				initConf();
  void				startCooks();
  void				startTime();
  void				listenReception();
  void				sendReception();
  void				signalDeath();
  void				closeProcess();
  void				answerState();

private :
  Kitchen(Kitchen const&);
  Kitchen&			operator=(Kitchen const&);
};

#endif /* !KITCHEN_HH_ */
