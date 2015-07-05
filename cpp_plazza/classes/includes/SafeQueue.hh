//
// SafeQueue.hh for plazza in /home/girard_r/Documents/plazza/tp
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Thu Apr 16 19:07:08 2015 Aurélien GIRARDEAU
// Last update Fri Apr 24 21:51:56 2015 Aurélien GIRARDEAU
//

#ifndef SAFEQUEUE_HH_
# define SAFEQUEUE_HH_

# include <cstdlib>
# include <deque>
# include "Thread.hh"
# include "ScopedLock.hh"
# include "ISafeQueue.hh"
# include "CondVar.hh"
# include "Exceptions.hpp"

template <typename T>
class			SafeQueue : public ISafeQueue<T>
{
private:
  bool			_isFinished;
  Mutex*		_mutex;
  CondVar*		_cond;
  std::deque<T*>	_queue;

public:
  SafeQueue(Mutex* mutex, CondVar* _cond);
  virtual ~SafeQueue(void);
  virtual void		push(T const& value);
  virtual bool		tryPop(T** value);
  virtual bool		isFinished(void);
  virtual void		setFinished(void);
  T*			pop(void);
};

# include "SafeQueue.tpp"

#endif
