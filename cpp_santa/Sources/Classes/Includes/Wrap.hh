//
// Wrap.hh for wrap in /home/tea_a/Work/Rendu/cpp_santa
//
// Made by Alexandre Tea
// Login   <tea_a@epitech.net>
//
// Started on  Sat Jan 17 22:24:51 2015 Alexandre Tea
// Last update Sun Jan 18 06:37:12 2015 Titouan Theophile
//

#ifndef __WRAP_HH__
# define __WRAP_HH__

# include "Object.hh"

class Wrap : public Object
{

public:

  Wrap(std::string const &);
  virtual ~Wrap();

  virtual Object                *clone() const = 0;

  virtual objectType            getType() const = 0;
  virtual bool                  getIsOpen() const = 0;
  virtual bool                  wrapMeThat(Object *) = 0;
  virtual Object*		openMe() = 0;
  virtual bool                  closeMe() = 0;
  virtual void                  isTaken() const = 0;
  virtual bool		        isEmpty() const;
  virtual Object*	        getStock() const;

protected:

  bool				_isEmpty;
  Object*			_stock;
};

#endif /* !__WARP_HH__ */
