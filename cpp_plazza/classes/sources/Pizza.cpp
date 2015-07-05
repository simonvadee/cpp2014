/*
** vadee_s
*/

#include <cstdlib>
#include <algorithm>
#include <cctype>
#include "../includes/Pizza.hh"

Pizza::Pizza(Correspondance *coresp)
  : _coresp(coresp)
{
  _number = 0;
}

Pizza::~Pizza()
{
}

bool			Pizza::isValid(std::string& order)
{
  size_t			size;
  size_t			size2;

  size = order.find(" ");
  if (size == std::string::npos || size == 0)
    return (false);
  size2 = order.find(" ", order.find(" ") + 1);
  if (size2 == std::string::npos || size2 == size + 1)
    return (false);
  size = order.find("x", size2);
  if (size == std::string::npos || size == order.size())
    return (false);
  return (true);
}

bool			Pizza::isNumber(int c)
{
  if (!isdigit(c))
    return (false);
  return (true);
}

bool			Pizza::pack(std::string& order)
{
  if (!isValid(order))
    return (false);
  _order.pizza = _coresp->getCodeFromName(order.substr(0, order.find(" ")));
  _order.size = _coresp->getSizeFromName(order.substr(order.find(" ") + 1, (order.rfind("x") - 2) - order.find(" ")));
  _order.msg = ORDER;
  order = order.substr(order.find("x", order.find(" ", order.find(" ") + 1) + 1) + 1, order.size());
  _number = std::atoi(order.c_str());
  if (_order.pizza == -1 || _order.size == -1)
    return (false);
  return (true);
}

std::string		Pizza::unpack(t_pack &pack) const
{
  std::string		str = "";

  str = _coresp->getNameFromCode(pack.pizza) + " " + _coresp->getSizeFromCode(pack.size);
  return (str);
}

t_pack			Pizza::getPack() const
{
  return _order;
}

bool			Pizza::reduceStock()
{
  if (_number <= 0)
    return false;
  _number -= 1;
  return true;
}

int			Pizza::getStock() const
{
  return _number;
}
