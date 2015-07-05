//
// Barbie.hh for santa in /home/theoph_t/test/cpp_santa/Sources/Classes/Includes
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 23:36:56 2015 Titouan Theophile
// Last update Sun Jan 18 05:51:21 2015 Alexandre Tea
//

#ifndef __BARBIE_HH__
# define __BARBIE_HH__

#include "Toy.hh"

class Barbie : public Toy
{

public:

  Barbie();
  Barbie(std::string const &);
  Barbie(Barbie const &);
  virtual ~Barbie();

  virtual Barbie*		clone() const;
  virtual void                  isTaken() const;
  virtual Barbie&	        operator=(Object&);

private:

  virtual bool                  getIsOpen() const;
  virtual bool                  wrapMeThat(Object *);
  virtual Object*               openMe();
  virtual bool                  closeMe();
  virtual bool		        isEmpty() const;
  virtual Object*	        getStock() const;
};

#endif /* !__BARBIE_HH__ */
