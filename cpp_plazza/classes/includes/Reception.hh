//
// Reception.hh for plazza in /home/girard_r/Documents/plazza
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Thu Apr 23 12:09:54 2015 Aurélien GIRARDEAU
// Last update Sun Apr 26 14:34:05 2015 Aurélien GIRARDEAU
//

#ifndef RECEPTION_H_
# define RECEPTION_H_

# include <deque>
# include <sstream>
# include <string>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "Kitchen.hh"
# include "Thread.hh"
# include "Pizza.hh"
# include "Correspondance.hh"
# include "NamedPipe.hh"
# include "Gui.hh"

class					Reception
{

private:

  Gui					*_gui;
  Correspondance			_correspondance;

  float					_multiplier;
  int					_nb_cooks;
  useconds_t				_sec;
  unsigned int				_nb_kitchen;

  std::vector<int>			_kitchenOccupancy;
  std::vector<NamedPipe*>	     	_fd_tab;
  std::deque<Pizza*>			_orders;
  std::deque<std::string>		_string_orders;
  std::deque<std::string>		_status;

public:
  Reception(float multiplier, int nb_cooks, useconds_t sec);
  ~Reception();
  void					run();

private:

  bool					getInfosGui();
  void					makeOrders();
  void					sendOrders();
  bool					allKitchenBusy();
  bool					isKitchenFull(unsigned int);
  void					addKitchen();
  void					delKitchen(std::vector<NamedPipe*>::iterator it);
  void					listenKitchen();
  void					askStatus();
  std::string				getInfo(t_state &status);
  void					makeStatus();
  int					getSelectFds(fd_set* readFds);
  int					getMessage(NamedPipe* active);
};

#endif /* !RECEPTION_H_ */
