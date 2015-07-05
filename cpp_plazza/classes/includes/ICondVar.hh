#ifndef ICONDVAR_HH_
# define ICONDVAR_HH_

class			ICondVar
{
public:
  virtual void		wait(void) = 0;
  virtual void		signal(void) = 0;
  virtual void		broadcast(void) = 0;
};

#endif
