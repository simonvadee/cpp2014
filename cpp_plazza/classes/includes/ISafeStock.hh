#ifndef ISAFESTOCK_HH_
# define ISAFESTOCK_HH_

# include <map>

template <typename T>
class			ISafeStock
{
public:
  virtual ~ISafeStock(void) {}
  virtual void		refresh() = 0;
  virtual bool		tryGet(T value) = 0;
  virtual bool		get(T value) = 0;
};

#endif
