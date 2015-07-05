//
// Cook.hh for plazza in /home/girard_r/Documents/plazza
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Fri Apr 24 17:02:26 2015 Aurélien GIRARDEAU
// Last update Sun Apr 26 18:03:03 2015 Aurélien GIRARDEAU
//

#ifndef COOK_HH_
# define COOK_HH_

# include <unistd.h>
# include "AObj.hh"
# include "Correspondance.hh"
# include "SafeQueue.hh"
# include "SafeStock.hh"
# include "SafeFinished.hh"

class			Time;

class			Cook : public AObj
{
private :
  bool			_active;
  SafeQueue<t_pack>*	_orders;
  SafeStock*		_stock;
  SafeFinished<t_pack>*	_ordersComplete;
  useconds_t		_timeMultiplier;
  Correspondance	_corresp;
  t_pack		*_pizza;
  std::map<e_ingr, int>	_reciepe;
  Mutex			_mutexActive;

public :

  Cook(SafeQueue<t_pack>*, SafeStock*, SafeFinished<t_pack>*, useconds_t time);

  virtual ~Cook();
  virtual void		start();
  bool			checkActive();

private :
  Cook(Cook const&);
  Cook&			operator=(Cook const&);

  bool			getIngrList();
  void			retrieveFromStock();
  void			cookOrder();
  void			sendCompleteOrder();
  void			setActive(bool);
};

#include "Kitchen.hh"

#endif /* !COOK_HH_ */
