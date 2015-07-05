//
// TypeMagicSource.hh for typemagicsource in /home/tea_a/Work/Rendu/cpp_santa/Sandbox
//
// Made by Alexandre Tea
// Login   <tea_a@epitech.net>
//
// Started on  Sat Jan 17 23:48:35 2015 Alexandre Tea
// Last update Sun Jan 18 01:22:03 2015 Alexandre Tea
//

#ifndef __MAGICTYPESOURCE_HH__
# define __MAGICTYPESOURCE_HH__

# include <vector>
# include <string>
# include <iterator>
# include "Object.hh"
# include "Toy.hh"
# include "Box.hh"
# include "GiftPaper.hh"
# include "IConveyorBelt.hh"

typedef std::vector<Object*>::const_iterator	ToyTypeIterator;

class MagicTypeSource
{
  typedef Object* (MagicTypeSource::*GenerateFunctions)() const;

private:
  std::vector<Object*>	_toyTypes;	/* learned toy types */

public:
  MagicTypeSource();
  MagicTypeSource(MagicTypeSource const&);
  ~MagicTypeSource();

public:
  /*
  ** learnToyType
  ** able conveyor to generate a new toy type ; if already learned, do nothing
  */
  void				learnToyType(Toy* toyType);
  Object*			generateObject(int type) const;
  void				forgetToyTypes();

public:
  MagicTypeSource&		operator=(MagicTypeSource const& rhs);

private:
  Object*			generateToy() const;	/* returns new instance of toy randomly picked */
  Object*			generateBox() const;
  Object*			generateGiftPaper() const;
};

#endif /* !__MAGICTYPESOURCE_HH__ */
