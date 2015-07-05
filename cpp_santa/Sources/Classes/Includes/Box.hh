//
// Box.hh for box in /home/tea_a/Work/Rendu/cpp_santa
//
// Made by Alexandre Tea
// Login   <tea_a@epitech.net>
//
// Started on  Sat Jan 17 22:21:53 2015 Alexandre Tea
// Last update Sun Jan 18 06:24:35 2015 Titouan Theophile
//

#ifndef __BOX_HH__
# define __BOX_HH__

#include "Wrap.hh"

class Box : public Wrap
{

public:

  Box();
  Box(Box&);
  virtual ~Box();

  virtual Box			*clone() const;

  bool				getIsOpen() const;
  virtual objectType		getType() const;
  virtual bool			wrapMeThat(Object *);
  virtual Object*		openMe();
  virtual bool			closeMe();
  virtual void			isTaken() const;
  virtual Box&			operator=(Box const&);

private:
  bool				_isOpen;
};

#endif /* !__BOX_HH__ */
