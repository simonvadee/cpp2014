//
// Toy.hh for santa in /home/theoph_t/test/cpp_santa/Sources/Classes/Includes
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 23:18:40 2015 Titouan Theophile
// Last update Sun Jan 18 06:34:36 2015 Titouan Theophile
//

#ifndef __TOY_HH__
# define __TOY_HH__

# include <string>
# include "Object.hh"

class Toy : public Object
{

public:

  Toy(std::string const &);
  virtual ~Toy();

  virtual Object                *clone() const = 0;
  virtual objectType            getType() const;
  virtual bool                  getIsOpen() const = 0;
  virtual bool                  wrapMeThat(Object *) = 0;
  virtual Object*               openMe() = 0;
  virtual bool                  closeMe() = 0;
  virtual void                  isTaken() const = 0;
  virtual bool		        isEmpty() const = 0;
  virtual Object*	        getStock() const = 0;

};

#endif /* !__TOY_HH__ */
