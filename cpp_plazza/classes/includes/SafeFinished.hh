//
// SafeQueue.hh for plazza in /home/girard_r/Documents/plazza/tp
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Thu Apr 16 19:07:08 2015 Aurélien GIRARDEAU
// Last update Sat Apr 25 17:51:23 2015 Aurélien GIRARDEAU
//

#ifndef SAFEFINISHED_HH_
# define SAFEFINISHED_HH_

# include <cstdlib>
# include <deque>
# include "Thread.hh"
# include "ScopedLock.hh"
# include "ISafeQueue.hh"
# include "CondVar.hh"
# include "Exceptions.hpp"

template <typename T>
class			SafeFinished
{
private:
  Mutex*		_mutex;
  std::deque<T*>	_queue;

public:
  SafeFinished(Mutex* mutex);
  ~SafeFinished(void);
  void		push(T const& value);
  bool		tryPop(T** value);
};

# include "SafeFinished.tpp"

#endif
