//
// Mutex.hh for Mutex in /home/girard_r/Documents/plazza/tp
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Thu Apr 16 13:46:23 2015 Aurélien GIRARDEAU
// Last update Wed Apr 22 14:52:01 2015 Aurélien GIRARDEAU
//

#ifndef MUTEX_HH_
# define MUTEX_HH_

# include <string>
# include <iostream>
# include "IMutex.hh"

class			Mutex : public IMutex
{
private :
  pthread_mutex_t		_mutex;
public :
  Mutex();
  virtual ~Mutex(void);
  virtual void			lock(void);
  virtual void			unlock(void);
  virtual bool			trylock(void);
  virtual pthread_mutex_t*	getMutex(void);
private :
  Mutex&	operator=(Mutex const& other);
  Mutex(Mutex const& other);
};

# endif
