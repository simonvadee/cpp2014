//
// Reception.cpp for plazza in /home/girard_r/Documents/plazza
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Wed Apr 22 16:59:18 2015 Aurélien GIRARDEAU
// Last update Sun Apr 26 14:53:09 2015 Aurélien GIRARDEAU
//

#include <sstream>
#include <sys/wait.h>
#include "Reception.hh"

template class Thread<Gui>;

Reception::Reception(float multiplier, int nb_cooks, useconds_t sec) : _gui(new Gui), _multiplier(multiplier), _nb_cooks(nb_cooks), _sec(sec)
{

}

Reception::~Reception()
{
  delete _gui;
}

void					Reception::run()
{
  Thread<Gui>				GuiThread(_gui);

  GuiThread.start();
  while (getInfosGui())
    {
      if (_gui->isFinished())
	{
	  GuiThread.wait();
	  return ;
	}
      if (_gui->isDisplayAsked())
      	{
      	  askStatus();
      	  makeStatus();
      	  _gui->printStatus(&_status);
      	  continue ;
      	}
      makeOrders();
      sendOrders();
      listenKitchen();
    }
}

bool					Reception::getInfosGui()
{
  std::string				*buff = new std::string;

  _string_orders.clear();
  while (_gui->ordersTryPop(buff))
    _string_orders.push_back(*buff);
  return true;
}

void					Reception::makeOrders()
{
  Pizza					*elem;
  std::string				single;
  size_t				found;
  size_t				start;

  t_pack				tmp;

  for (std::deque<std::string>::iterator it = _string_orders.begin(); it != _string_orders.end(); ++it)
    {
      start = 0;
      found = 0;
      while (found != std::string::npos)
      	{
	  (void)start;
    	  if ((found = (it->find("; ", start))) != std::string::npos)
	    single = it->substr(start, found - start);
      	  else
	    single = it->substr(start);
	  start = found + 2;
      	  elem = new Pizza(&_correspondance);
	  if (!elem->pack(single))
	    {
	      delete elem;
	      std::cout << "syntax error" << std::endl;
	      return ;
	    }
	  tmp = elem->getPack();
	  std::cout << "RECEPTION : make order " <<  elem->getStock() << " pizza = " << tmp.pizza << " size = " << tmp.size << std::endl;
	  _orders.push_back(elem);
	}
    }
}

void					Reception::sendOrders()
{
  t_pack				tmp;
  std::deque<Pizza*>::iterator		it_orders;

  it_orders = _orders.begin();
  while (it_orders != _orders.end())
    {
      while ((*it_orders)->getStock() > 0)
	{
	  if (allKitchenBusy())
	    addKitchen();
	  for (unsigned int it_kitchen = 0; it_kitchen != _fd_tab.size(); ++it_kitchen)
	    {
	      if (isKitchenFull(it_kitchen))
		continue ;
	      if (!(*it_orders)->reduceStock())
		break ;
	      _kitchenOccupancy[it_kitchen] += 1;
	      tmp = (*it_orders)->getPack();
	      (*_fd_tab[it_kitchen]).send(tmp);
	    }
	}
      it_orders = _orders.erase(it_orders);
    }
}

bool					Reception::allKitchenBusy()
{
  for (unsigned int it_kitchen = 0; it_kitchen != _fd_tab.size(); ++it_kitchen)
    {
      if (!isKitchenFull(it_kitchen))
	return false;
    }
  return true;
}

bool					Reception::isKitchenFull(unsigned int idx)
{
  return (_kitchenOccupancy[idx] >= (2 * _nb_cooks));
}

void					Reception::addKitchen()
{
  std::ostringstream			index;
  index << _fd_tab.size();
  std::string				fdSend = "kitchen" + index.str() + 'S';
  std::string				fdReceive = "kitchen" + index.str() + 'R';
  pid_t					pid;

  if (mkfifo(fdSend.c_str(), S_IRUSR | S_IWUSR) != 0
      || mkfifo(fdReceive.c_str(), S_IRUSR | S_IWUSR) != 0)
    throw PlazzaError::NamedPipeError(errno, "Error while creating namedpipe " + fdSend + '\n');
  if ((pid = fork()) == -1)
    throw PlazzaError::ProcessError(errno, "Error while forking..\n");
  if (pid == 0)
    {
      NamedPipe*			kitchen_np = new NamedPipe(pid, fdReceive.c_str(), fdSend.c_str(), &_correspondance);
      Kitchen				kitchen(_multiplier, _nb_cooks, _sec, kitchen_np);

      (void)kitchen;
      kitchen.start();
    }
  else
    {
      NamedPipe				*kitchen = new NamedPipe(pid, fdSend.c_str(), fdReceive.c_str(), &_correspondance);

      _fd_tab.push_back(kitchen);
      _kitchenOccupancy.push_back(0);
      std::cout << "new kitchen created " << _fd_tab.size() << std::endl;
    }
}

void					Reception::delKitchen(std::vector<NamedPipe*>::iterator it)
{
  std::vector<NamedPipe*>::iterator cmp = _fd_tab.begin();
  int					count = 0;

  while (cmp != it)
    {
      ++cmp;
      ++count;
    }
  for (std::vector<int>::iterator del = _kitchenOccupancy.begin(); del != _kitchenOccupancy.end(); ++del)
    {
      if (--count == 0)
	{
	  _kitchenOccupancy.erase(del);
	  break ;
	}
    }
}

int					Reception::getSelectFds(fd_set* readFds)
{
  std::vector<NamedPipe*>::iterator	it;
  int					max = -1;
  int					ret = -1;

  for (it = _fd_tab.begin(); it != _fd_tab.end(); ++it)
    {
      ret = (*it)->getReceive();
      max = (ret > max ? ret : max);
      FD_SET(ret, readFds);
    }
  return (max);
}

int					Reception::getMessage(NamedPipe* active)
{
  t_pack				pack;
  std::string				tmp;
  Pizza					pizza(&_correspondance);
  int					pid;
  int					status;

  if (!active->receive(&pack))
    std::cerr << "error receive pack in Reception" << std::endl;
  if (pack.msg == ORDER_COMPLETE)
    {
      tmp = pizza.unpack(pack);
      _gui->pushOrdersFinished(tmp);
    }
  else if (pack.msg == CLOSE_KITCHEN)
    {
      pid = active->getPid();
      waitpid(pid, &status, 0);
      return (1);
    }
  return (0);
}

void					Reception::listenKitchen()
{
  fd_set				readFds;
  int					ret = 0;
  int					maxFd = -1;
  struct timeval			tv;
  std::vector<NamedPipe*>::iterator	it;

  tv.tv_sec = 0;
  tv.tv_usec = 1;
  maxFd = getSelectFds(&readFds);
  if ((ret = select(maxFd + 1, &readFds, NULL, NULL, &tv)) < 0)
    std::cerr << "SELECT FAILED" << std::endl;
  if (ret == 0)
    return ;
  for (it = _fd_tab.begin(); it != _fd_tab.end(); ++it)
    {
      if (FD_ISSET((*it)->getReceive(), &readFds)
	  && getMessage(*it))
	it = _fd_tab.erase(it);
    }


  // t_pack				pack;
  // Pizza					pizza(&_correspondance);
  // std::string				tmp;
  // int					status;
  // int					pid;

  // for (std::vector<NamedPipe*>::iterator it = _fd_tab.begin(); it != _fd_tab.end(); ++it)
  //   {
  //     if (!(*it)->receive(&pack))
  // 	continue ;
  //     if (pack.msg == ORDER_COMPLETE)
  // 	{
  // 	  tmp = pizza.unpack(pack);
  // 	  _gui->pushOrdersFinished(tmp);
  // 	}
  //     else if (pack.msg == CLOSE_KITCHEN)
  // 	{
  // 	  pid = (*it)->getPid();
  // 	  waitpid(pid, &status, 0);
  // 	  it = _fd_tab.erase(it);
  // 	}
  //   }
}

void					Reception::askStatus()
{
  t_pack				send;

  send.msg = ASK_STATE;
  for (std::vector<NamedPipe*>::iterator it = _fd_tab.begin(); it != _fd_tab.end(); ++it)
    (*it)->send(send);
  sleep(1);
}

std::string				Reception::getInfo(t_state &status)
{
  std::string				ret = "";
  std::stringstream			nb;

  if (status.msg == ANSWER_STATE)
    {
      int				i = 0;

      while (i != 8)
	{
	  nb << status.ingr[i];
	  ret = ret + _correspondance.getIngrFromCode((e_ingr)(i + 1)) + " x" + nb.str() + "\n";
	  ++i;
	}
      ret += "\n";
      return (ret);
    }
  else if (status.msg == ANSWER_COOK)
    {
      ret += _correspondance.getNameFromCode((e_pizza)(status.ingr[0])) + "\n";
      return (ret);
    }
  return (ret);
}

void					Reception::makeStatus()
{
  std::string				ret = "";
  t_state				rec;

  _status.clear();
  rec.msg = ORDER;
  for (std::vector<NamedPipe*>::iterator it = _fd_tab.begin(); it != _fd_tab.end(); ++it)
    {
      while (rec.msg != END_ANSWER)
	{
	  (*it)->receive(&rec);
	  ret += getInfo(rec);
	}
      _status.push_front(ret);
    }
}
