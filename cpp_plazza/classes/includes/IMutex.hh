//
// IMutex.hh for IMutex in /home/girard_r/Documents/plazza/tp
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Thu Apr 16 13:44:05 2015 Aurélien GIRARDEAU
// Last update Fri Apr 17 13:30:07 2015 Aurélien GIRARDEAU
//

#ifndef IMUTEX_HH_
# define IMUTEX_HH_

# include <pthread.h>

class		IMutex
{
public :
  virtual ~IMutex(void) {}
  virtual void			lock(void) = 0;
  virtual void			unlock(void) = 0;
  virtual bool			trylock(void) = 0;
  virtual pthread_mutex_t*	getMutex(void) = 0;
};

#endif
