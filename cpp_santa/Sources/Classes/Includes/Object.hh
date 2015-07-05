//
// Object.hh for santa in /home/theoph_t/test/cpp_santa/Sources/Classes/Includes
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 22:13:57 2015 Titouan Theophile
// Last update Sun Jan 18 06:29:31 2015 Titouan Theophile
//

#ifndef __OBJECT_H__
# define __OBJECT_H__

# include <iostream>

# define NB_TYPES	3

enum objectType
  {
    TOY = 0,
    BOX,
    GIFTPAPER
  };


class Object
{

public:

  Object(std::string const &);
  virtual ~Object();
  virtual Object		*clone() const = 0;

  virtual objectType		getType() const = 0;
  virtual std::string const&	getTitle() const;
  virtual bool			getIsOpen() const = 0;
  virtual bool			wrapMeThat(Object *) = 0;
  virtual Object*		openMe() = 0;
  virtual bool			closeMe() = 0;
  virtual void			isTaken() const = 0;
  virtual bool		        isEmpty() const = 0;
  virtual Object*	        getStock() const = 0;

protected:

  std::string _title;
};

#endif /* !__OBJECT_H__ */
