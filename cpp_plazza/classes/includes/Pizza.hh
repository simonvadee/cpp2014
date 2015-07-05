#ifndef PIZZA_HH_
# define PIZZA_HH_

# include "Correspondance.hh"

class					Pizza
{
private:
  Correspondance			*_coresp;
  e_msgtype				_msg;
  t_pack				_order;
  int					_number;

  bool					isValid(std::string& order);
  static bool				isNumber(int c);

public:
  Pizza(Correspondance *coresp);
  ~Pizza();
  
  bool					pack(std::string& order);
  std::string				unpack(t_pack &pack) const;
  t_pack				getPack() const;
  bool					reduceStock();
  int					getStock() const;
};

#endif
