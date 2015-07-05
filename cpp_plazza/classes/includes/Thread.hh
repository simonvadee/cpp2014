//
// Thread.hh for plazza in /home/girard_r/Documents/plazza/tp
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Thu Apr 16 15:31:31 2015 Aurélien GIRARDEAU
// Last update Wed Apr 22 15:25:19 2015 Aurélien GIRARDEAU
//

#ifndef THREAD_HH_
# define THREAD_HH_

# include <map>
# include <string>
# include <iostream>
# include <pthread.h>
# include <errno.h>
# include "Exceptions.hpp"
# include "AObj.hh"
# include "ScopedLock.hh"
# include "IThread.hh"

template <typename T>
class		Thread : public IThread
{
private :
  e_status			_status;
  T*				_handler;
  pthread_t			_th;
  std::map<int, std::string>	_joinErrors;

public :
  Thread(T* handler);
  virtual ~Thread();
  virtual bool		wait();
  virtual bool		start();
private :
  Thread(Thread const&);
  Thread&	operator=(Thread const&);
};

void*		start_routine(void *);

# include "Thread.tpp"

#endif
