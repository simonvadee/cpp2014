//
// ElfOfPePeNoel.cpp for ElfOfPePeNoel in /home/girard_r/rendu/cpp_santa/Sources/Classes
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Sat Jan 17 15:55:37 2015 Aurélien GIRARDEAU
// Last update Sun Jan 18 09:15:07 2015 Alexandre Tea
//

#include <string>
#include <iostream>
#include <vector>
#include "ElfOfPePeNoel.hh"
#include "GiftPaper.hh"
#include "Box.hh"
#include "Toy.hh"

ElfOfPePeNoel::ElfOfPePeNoel()
  : _carryObject(NULL)
{
  std::cout << "The elf of Santa has just arrived! * JingleBell, JingleBell... * " << std::endl;
}

ElfOfPePeNoel::ElfOfPePeNoel(ElfOfPePeNoel const& other)
{
  if (_carryObject)
    delete _carryObject;
  _carryObject = other._carryObject->clone();
  std::cout << "The elf of Santa has just arrived! * JingleBell, JingleBell... * " << std::endl;
}

ElfOfPePeNoel&	ElfOfPePeNoel::operator=(ElfOfPePeNoel const& other)
{
  if (_carryObject)
    delete _carryObject;
  _carryObject = other._carryObject->clone();
  return *this;
}

ElfOfPePeNoel::~ElfOfPePeNoel()
{
  if (_carryObject)
    delete _carryObject;
  std::cout << "The elf was smashed by a reindeer * SPROUTCHHH * " << std::endl;
}

bool		ElfOfPePeNoel::openWrap(Object& wrap)
{
  if (wrap.openMe() == NULL)
    return false;
  std::cout << "The elf just opened a " + wrap.getTitle() << std::endl;
  return true;
}

bool		ElfOfPePeNoel::closeBox(Object& box)
{
  std::cout << "The elf has just closed a box" << std::endl;
  return (box.closeMe());
}

bool		ElfOfPePeNoel::wraps(Object& wrap, Object *obj)
{
  bool		ret;

  std::cout << "tuuuut tuuut tuut" << std::endl;
  ret = wrap.wrapMeThat(obj);
  _carryObject = NULL;
  std::cout << "The elf wraps " + obj->getTitle() + " with a " + wrap.getTitle() << std::endl;
  return (ret);
}

bool		ElfOfPePeNoel::takeObject(ITable& table, size_t idx)
{
  Object* newObj;

  if (_carryObject) {
    std::cout << FULL << std::endl;
    return false;
  }
  newObj = table.objectTaken(idx);
  if (newObj->getType() == GIFTPAPER || newObj->getType() == BOX)
    std::cout << "whistles while working" << std::endl;
  if (newObj->getType() == TOY)
    newObj->isTaken();
  _carryObject = newObj;
  std::cout << "The Elf has taken " + newObj->getTitle() + " from the table." << std::endl;
  return true;
}

bool		ElfOfPePeNoel::takeObject(IConveyorBelt& conveyor)
{
  Object* newObj;

  if (_carryObject != NULL) {
    std::cout << FULL << std::endl;
    return false;
  }
  if ((newObj = conveyor.objectTaken()) == NULL)
    return (false);
  _carryObject = newObj;
  if (_carryObject == NULL)
    std::cout << "DDDDDDDDDDDDDDDDDD" << std::endl;
  std::cout << "The Elf has taken " + newObj->getTitle() + " from the conveyor." << std::endl;
  return true;
}

bool		ElfOfPePeNoel::putObject(ITable& table)
{
  if (_carryObject == NULL) {
    std::cout << EMPTY << std::endl;
    return false;
  }
  if (table.addObject(_carryObject)) {
    std::cout << "The elf put a " +  _carryObject->getTitle() + " on the table" << std::endl;
    _carryObject = NULL;
    return true;
  }
  return false;
}

bool		ElfOfPePeNoel::putObject(IConveyorBelt& conveyor)
{
  if (_carryObject) {
    std::cout << FULL << std::endl;
    return false;
  }
  if (conveyor.setObject(_carryObject)) {
    std::cout << "The elf put a " +  _carryObject->getTitle() + " on the conveyor" << std::endl;
    _carryObject = NULL;
    return true;
  }
  return false;
}

bool		ElfOfPePeNoel::pressIn(IConveyorBelt& conveyor)
{
  std::cout << "The Elf pressed the button IN" << std::endl;
  return conveyor.inPressed();
}

bool		ElfOfPePeNoel::pressOut(IConveyorBelt& conveyor)
{
  std::cout << "The Elf pressed the button OUT. Yeaaaah one gift for Santa!" << std::endl;
  return conveyor.outPressed();
}

char* const*	ElfOfPePeNoel::look(ITable& table) const
{
  std::cout << "The Elf look at the table" << std::endl;
  return table.getObjectTitles();
}

char* const*	ElfOfPePeNoel::look(IConveyorBelt& conveyor) const
{
  char**		newArray;
  Object*		obj;

  if ((obj = conveyor.getObject()) == NULL)
    return NULL;
  newArray = new char*[2];
  newArray[0] = new char [obj->getTitle().size() + 1];
  std::copy(obj->getTitle().begin(), obj->getTitle().end(), newArray[0]);
  newArray[1] = NULL;
  std::cout << "The Elf look at the Conveyor" << std::endl;
  return newArray;
}

int		ElfOfPePeNoel::seekInTable(ITable &table, objectType type) const
{
  std::vector<Object*>			vector = table.getVector();
  std::vector<Object*>::iterator	it;
  int					idx = 0;

  for (it = vector.begin(); it != vector.end(); ++it) {
    if (type == (*it)->getType())
      return idx;
    idx += 1;
  }
  return -1;
}

bool		ElfOfPePeNoel::fillTable(ITable& table, IConveyorBelt& conveyor)
{
  while (table.getVector().size() < 10)
    {
      if (conveyor.isEmpty() && !pressIn(conveyor))
	return (false);;
      if (!takeObject(conveyor) || putObject(table) == false)
	return (false);
    }
  return (true);
}

bool			ElfOfPePeNoel::buildGift(ITable& table, IConveyorBelt& conveyor)
{
  std::vector<Object*>	objs = table.getVector();
  Object*		toy = NULL;
  Object*		gp = NULL;
  Object*		box = NULL;
  std::vector<Object*>::iterator	it = objs.begin();

  while (it != objs.end())
    {
      if (toy == NULL && (*it)->getType() == TOY)
	toy = *it;
      else if (gp == NULL && (*it)->getType() == GIFTPAPER)
	gp = *it;
      else if (box == NULL && (*it)->getType() == BOX)
	box = *it;
      it++;
    }
  if (toy == NULL || gp == NULL || box == NULL)
    return (false);
  it = objs.begin();
  while (it != objs.end())
    {
      if (*it == toy || *it == gp)
	objs.erase(it);
      it++;
    } // remove objs from tab
  if (!wraps(*box, toy) || !wraps(*gp, box))
    return (false);
  if (!box->getIsOpen())
    openWrap(*box);
  if (!gp->isEmpty())
    openWrap(*box);
  if ((takeObject(table, seekInTable(table, BOX))) == false)
    return (false);
  if ((putObject(conveyor)) == false)
    return (false);
  pressOut(conveyor);
  return (true);
}

void		ElfOfPePeNoel::run(ITable& table, IConveyorBelt& conveyor)
{
  while (42)
    {
      if (!fillTable(table, conveyor))
	break;
      if (!buildGift(table, conveyor))
	break;
    }
  std::cout << "pepe ya un schmolle dans le bignou" << std::endl;
}
