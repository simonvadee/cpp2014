//
// CondVar.hh for CondVar in /home/girard_r/Documents/plazza/tp
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Fri Apr 17 13:24:07 2015 Aurélien GIRARDEAU
// Last update Fri Apr 17 15:23:13 2015 Aurélien GIRARDEAU
//

#ifndef CONDVAR_HH_
# define CONDVAR_HH_

# include <pthread.h>
# include <exception>
# include "Mutex.hh"
# include "ICondVar.hh"

class			CondVar : public ICondVar
{
private:
  Mutex*		_mutex;
  pthread_cond_t	_cond;

public:
  CondVar(Mutex* mutex);
  ~CondVar();
  virtual void		wait(void);
  virtual void		signal(void);
  virtual void		broadcast(void);
};

#endif
