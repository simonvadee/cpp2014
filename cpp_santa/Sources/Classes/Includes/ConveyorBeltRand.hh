//
// ConveyorBeltRand.hh for ConveyorBeltRand in /home/tea_a/Work/Rendu/cpp_santa/Sources/Classes/Includes
//
// Made by Alexandre Tea
// Login   <tea_a@epitech.net>
//
// Started on  Sat Jan 17 15:04:16 2015 Alexandre Tea
// Last update Sun Jan 18 06:42:45 2015 Alexandre Tea
//

#ifndef __CONVEYORBELTRAND_HH__
# define __CONVEYORBELTRAND_HH__

# include <string>
# include "Object.hh"
# include "MagicTypeSource.hh"
// # include "Toy.hh"
// # include "Box.hh"
// # include "GiftPaper.hh"
# include "IConveyorBelt.hh"

# define MTSNOTSET	"Magic type source is not set"

/*
** for virtual functions' usage, see IConveyorBelt.hh
*/

class ConveyorBeltRand : public IConveyorBelt
{
private:
  Object*		_current;
  MagicTypeSource*	_mts;

public:
  ConveyorBeltRand();
  ConveyorBeltRand(ConveyorBeltRand const& c);
  virtual ~ConveyorBeltRand();

public:
  virtual bool			inPressed();
  virtual bool			outPressed();
  virtual bool			isEmpty() const;

private:
  std::string			serialize(Object* gift);
  std::string			serializeObject(Object* obj, std::string const& xmlChild);
  std::string			putIntoTags(std::string const& tag, std::string const& content);

public:
  ConveyorBeltRand&		operator=(ConveyorBeltRand const& rhs);

public:
  void				setMTS(MagicTypeSource const&);
  void				unsetMTS();
  virtual Object*		objectTaken();
  virtual bool			setObject(Object* obj);
  virtual Object*		getObject() const;
};

#endif /* !__CONVEYORBELTRAND_HH__ */
