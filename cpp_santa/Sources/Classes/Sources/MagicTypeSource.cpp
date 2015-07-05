//
// MagicTypeSource.cpp for magictypesource in /home/tea_a/Work/Rendu/cpp_santa/Sources/Classes/Sources
//
// Made by Alexandre Tea
// Login   <tea_a@epitech.net>
//
// Started on  Sat Jan 17 23:52:48 2015 Alexandre Tea
// Last update Sun Jan 18 06:03:16 2015 Alexandre Tea
//

#include <cstdlib>
#include <iterator>
#include "Toy.hh"
#include "Box.hh"
#include "GiftPaper.hh"
#include "LittlePony.hh"
#include "Teddy.hh"
#include "MagicTypeSource.hh"

MagicTypeSource::MagicTypeSource()
{
  /* init toy types vector with mandatory ones */

  _toyTypes.push_back(new Box());
  _toyTypes.push_back(new GiftPaper());
  _toyTypes.push_back(new LittlePony());
  _toyTypes.push_back(new Teddy());
}

MagicTypeSource::MagicTypeSource(MagicTypeSource const& m)
{
  ToyTypeIterator	it;

  it = m._toyTypes.begin();
  while (it != m._toyTypes.end())
    {
      _toyTypes.push_back((*it)->clone());
      it++;
    }
}

MagicTypeSource::~MagicTypeSource()
{
  forgetToyTypes();
}

void			MagicTypeSource::learnToyType(Toy* toyType)
{
  if (toyType == NULL)
    return ;
  _toyTypes.push_back(toyType->clone());
  std::cout << "The MagicTypeSource learned to generate the toy " << toyType->getTitle()
	    << " !" << std::endl;
}

Object*			MagicTypeSource::generateObject(int type) const
{
  const GenerateFunctions 	generate[3] = {&MagicTypeSource::generateToy,
					       &MagicTypeSource::generateBox,
					       &MagicTypeSource::generateGiftPaper};

  return ((this->*generate[type])());
}

Object*			MagicTypeSource::generateToy() const
{
  return (_toyTypes[random() % _toyTypes.size()]->clone());
}

Object*			MagicTypeSource::generateBox() const
{
  return (new Box());
}

Object*			MagicTypeSource::generateGiftPaper() const
{
  return (new GiftPaper());
}

void			MagicTypeSource::forgetToyTypes()
{
  while (!_toyTypes.empty())
    {
      delete (_toyTypes.back());
      _toyTypes.pop_back();
    }
}

MagicTypeSource&	MagicTypeSource::operator=(MagicTypeSource const& rhs)
{
  ToyTypeIterator	it;

  this->forgetToyTypes();
  it = rhs._toyTypes.begin();
  while (it != rhs._toyTypes.end())
    {
      _toyTypes.push_back((*it)->clone());
      it++;
    }

  return (*this);
}
