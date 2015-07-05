//
// Time.hh for plazza in /home/girard_r/Documents/plazza
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Fri Apr 24 18:41:28 2015 Aurélien GIRARDEAU
// Last update Sun Apr 26 18:00:00 2015 Aurélien GIRARDEAU
//

#ifndef TIME_HH_
# define TIME_HH_

# include <unistd.h>
# include <deque>
# include "AObj.hh"
# include "Mutex.hh"
# include "ScopedLock.hh"
# include "SafeStock.hh"
# include "Cook.hh"

class			Time : public AObj
{
private :
  SafeStock*		_stock;
  std::deque<Cook*>*	_cooks;
  bool			_isFinished;
  Mutex			_mutexFinished;
  useconds_t		_wait;

public :
  Time(SafeStock*, std::deque<Cook*>*, useconds_t&);
  ~Time();
  void			start();
  void			setFinished();
  bool			isFinished();
  bool			isActive();

private :
  Time(Time const&);
  Time&			operator=(Time const&);
};

#endif
