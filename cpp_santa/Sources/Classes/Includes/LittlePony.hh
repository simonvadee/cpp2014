//
// LittlePony.hh for santa in /home/theoph_t/test/cpp_santa/Sources/Classes/Includes
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 23:36:56 2015 Titouan Theophile
// Last update Sun Jan 18 06:22:03 2015 Titouan Theophile
//

#ifndef __LITTLEPONY_HH__
# define __LITTLEPONY_HH__

#include "Toy.hh"

class LittlePony : public Toy
{

public:

  LittlePony();
  LittlePony(std::string const &);
  LittlePony(LittlePony const &);
  virtual ~LittlePony();

  virtual LittlePony*		clone() const;
  virtual void                  isTaken() const;
  virtual LittlePony&           operator=(Object&);

private:

  virtual bool                  getIsOpen() const;
  virtual bool                  wrapMeThat(Object *);
  virtual Object*               openMe();
  virtual bool                  closeMe();
  virtual bool		        isEmpty() const;
  virtual Object*	        getStock() const;
};

#endif /* !__LITTLEPONY_HH__ */
