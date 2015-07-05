//
// ConveyorBeltRand.cpp for ConveyorBeltRand in /home/tea_a/Work/Rendu/cpp_santa/Sources/Classes/Includes
//
// Made by Alexandre Tea
// Login   <tea_a@epitech.net>
//
// Started on  Sat Jan 17 16:06:29 2015 Alexandre Tea
// Last update Sun Jan 18 06:41:31 2015 Alexandre Tea
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Object.hh"
#include "IConveyorBelt.hh"
#include "ConveyorBeltRand.hh"

/*
** constructors / destructor
*/

ConveyorBeltRand::ConveyorBeltRand() : _current(NULL), _mts(new MagicTypeSource())
{
  std::cout << "ConveyorBeltRand corretly initialized" << std::endl;
}

ConveyorBeltRand::ConveyorBeltRand(ConveyorBeltRand const& c) :
  _current(c._current->clone()), _mts(new MagicTypeSource(*c._mts))
{
}

ConveyorBeltRand::~ConveyorBeltRand()
{
  std::cout << "ConveyorBeltRand has been destroyed.. no more gifts for childrens !" << std::endl;
  if (_current != NULL)
    delete (_current);
  if (_mts != NULL)
    delete (_mts);
}

/*
** member functions implemented from IConveyor
*/

void			ConveyorBeltRand::setMTS(MagicTypeSource const& mts)
{
  std::cout << "Magic type source has been set in the ConveyorBeltRand" << std::endl;
  _mts = new MagicTypeSource(mts);
}

void			ConveyorBeltRand::unsetMTS()
{
  std::cout << "Unsetting current magic type source from ConveyorBeltRand" << std::endl;
  if (_mts != NULL)
    delete (_mts);
  _mts = NULL;
}

bool			ConveyorBeltRand::inPressed()
{
  if (!isEmpty())
    {
      std::cerr << "Error: Conveyor: " << NOT_EMPTY << std::endl;
      return (false);
    }
  if (_mts == NULL)
    {
      std::cerr << "Error: Conveyor: " << MTSNOTSET << std::endl;
      return (false);
    }
  _current = _mts->generateObject(random() % NB_TYPES);
  std::cout << _current->getTitle() << " " << POPPED_IN  << std::endl;
  return (true);
}

bool			ConveyorBeltRand::outPressed()
{
  static int		idx = 0;
  std::stringstream	ss;
  std::ofstream		file;

  if (isEmpty())
    {
      std::cerr << "Error: Conveyor: " << EMPTY << std::endl;
      return (false);
    }
  std::cout << GIFT_OUT << std::endl;
  ss << idx;
  file.open(("gift" + ss.str() + ".xml").c_str(), std::ofstream::out);
  file << serialize(_current) << std::endl;
  file.close();
  ++idx;
  delete (_current);
  _current = NULL;
  return (true);
}

bool			ConveyorBeltRand::isEmpty() const
{
  return (_current == NULL);
}

Object*			ConveyorBeltRand::objectTaken()
{
  Object*		save = _current;

  if (isEmpty())
    return (NULL);

  _current = NULL;
  return (save);
}

bool			ConveyorBeltRand::setObject(Object* obj)
{
  if (!isEmpty())
    {
      std::cerr << "Error: Conveyor: " << NOT_EMPTY << std::endl;
      return (false);
    }
  _current = obj;
  return (true);
}

Object*			ConveyorBeltRand::getObject() const
{
  return (_current);
}

/*
** functions members
*/

std::string		ConveyorBeltRand::serialize(Object* gift)
{
  Object*		deep_1 = gift;
  Object*		deep_2 = NULL;
  Object*		deep_3 = NULL;

  if (gift == NULL)
    return ("");
  if (gift->getType() != TOY)
    {
      if ((deep_2 = gift->getStock()) != NULL && deep_2->getType() != TOY &&
	  deep_2->getStock() != NULL)
	deep_3 = deep_2->getStock();
      else
	deep_3 = NULL;
    }
  else
    deep_2 = deep_3 = NULL;
  return (serializeObject(deep_1, serializeObject(deep_2, serializeObject(deep_3, ""))));
}

std::string		ConveyorBeltRand::serializeObject(Object* obj, std::string const& xmlChild)
{
  std::string const	types[3] = {"Toy", "Box", "GiftPaper"};
  if (obj == NULL)
    return ("");
  return (putIntoTags(types[obj->getType()], putIntoTags("Title", obj->getTitle()) + xmlChild));
}

std::string		ConveyorBeltRand::putIntoTags(std::string const& tag, std::string const& content)
{
  return ("<" + tag + ">" + content + "</" + tag + ">");
}

/*
** operators
*/

ConveyorBeltRand&	ConveyorBeltRand::operator=(ConveyorBeltRand const& rhs)
{
  _current = rhs._current->clone();
  delete (_mts);
  _mts = new MagicTypeSource(*rhs._mts);

  return (*this);
}
