//
// SafeStock.hh for plazza in /home/girard_r/Documents/plazza
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Sat Apr 25 15:54:48 2015 Aurélien GIRARDEAU
// Last update Sat Apr 25 15:54:49 2015 Aurélien GIRARDEAU
//

#ifndef SAFESTOCK_HH_
# define SAFESTOCK_HH_

# include "Mutex.hh"
# include "CondVar.hh"
# include "ScopedLock.hh"
# include "Correspondance.hh"
# include "ISafeStock.hh"

class			SafeStock : public ISafeStock<e_ingr>
{
  Mutex*		_mutex;
  CondVar*		_cond;
  std::map<e_ingr, int>	_queue;

public:
  SafeStock(Mutex *mutex, CondVar *cond);
  virtual ~SafeStock(void);
  virtual void		refresh();
  virtual bool		tryGet(e_ingr value);
  virtual bool		get(e_ingr value);
};

#endif
