//
// Playmobil.hh for santa in /home/theoph_t/test/cpp_santa/Sources/Classes/Includes
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 23:36:56 2015 Titouan Theophile
// Last update Sun Jan 18 05:49:02 2015 Alexandre Tea
//

#ifndef __PLAYMOBIL_HH__
# define __PLAYMOBIL_HH__

#include "Toy.hh"

class Playmobil : public Toy
{

public:

  Playmobil();
  Playmobil(std::string const &);
  Playmobil(Playmobil const &);
  virtual ~Playmobil();

  virtual Playmobil*		clone() const;
  virtual void                  isTaken() const;
  virtual Playmobil&           operator=(Object&);

private:

  virtual bool                  getIsOpen() const;
  virtual bool                  wrapMeThat(Object *);
  virtual Object*               openMe();
  virtual bool                  closeMe();
  virtual bool		        isEmpty() const;
  virtual Object*	        getStock() const;
};

#endif /* !__PLAYMOBIL_HH__ */
