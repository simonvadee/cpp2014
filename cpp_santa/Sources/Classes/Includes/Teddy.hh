//
// Teddy.hh for santa in /home/theoph_t/test/cpp_santa/Sources/Classes/Includes
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 23:37:09 2015 Titouan Theophile
// Last update Sun Jan 18 06:29:16 2015 Titouan Theophile
//

#ifndef __TEDDY_HH__
# define __TEDDY_HH__

#include "Toy.hh"

class Teddy : public Toy
{

public:

  Teddy();
  Teddy(std::string const &);
  Teddy(Teddy&);
  virtual ~Teddy();

  virtual Teddy                *clone() const;
  virtual void                  isTaken() const;
  virtual Teddy&               operator=(Object&);

private:

  virtual bool                  getIsOpen() const;
  virtual bool                  wrapMeThat(Object *);
  virtual Object*               openMe();
  virtual bool                  closeMe();
  virtual bool		        isEmpty() const;
  virtual Object*	        getStock() const;
};

#endif /* !__TEDDY_HH___ */
