/**
 * theoph_t tea_a girard_r vadee_s
 */

#include "TablePePeNoel.hh"

TablePePeNoel::TablePePeNoel()
{
  std::cout << "A fuckin table has been created" << std::endl;
}

TablePePeNoel::TablePePeNoel(TablePePeNoel const& other)
{
  std::cout << "A fuckin table has been created" << std::endl;
  for (std::vector<Object*>::const_iterator it = other._objects.begin(); it != other._objects.end(); it++)
    _objects.push_back(*it);
}

TablePePeNoel::~TablePePeNoel()
{
  std::cout << "The table lays on the ground, inanimate (as a table should)" << std::endl;
  if (_objects.size() > 0)
    _objects.clear();
}

TablePePeNoel&			TablePePeNoel::operator=(TablePePeNoel const& other)
{
  for (std::vector<Object*>::const_iterator it = other._objects.begin(); it != other._objects.end(); it++)
    _objects.push_back(*it);
  return *this;
}


bool				TablePePeNoel::addObject(Object* elem)
{
  if (_objects.size() == 10)
    {
      std::cerr << BROKEN_TABLE << std::endl;
      return false;
    }
  _objects.push_back(elem);
  return true;
}

Object*				TablePePeNoel::getObject(size_t index) const
{
  if (index > _objects.size() - 1)
    {
      std::cerr << WRONG_INDEX << std::endl;
      return NULL;
    }
  return _objects[index];
}

Object*				TablePePeNoel::objectTaken(size_t index)
{
  Object*	ret;

  if (index > _objects.size() - 1)
    {
      std::cerr << WRONG_INDEX << std::endl;
      return NULL;
    }
  ret = _objects[index]->clone();
  _objects.erase(_objects.begin() + index);
  return ret;
}

char* const*			TablePePeNoel::getObjectTitles()
{
  char**			array = new char* [_objects.size() + 1];
  std::vector<Object*>::iterator	it;
  size_t			i = 0;

  for (it = _objects.begin(); it != _objects.end(); it++)
    {
      array[i] = new char [(*it)->getTitle().size() + 1];
      std::copy((*it)->getTitle().begin(), (*it)->getTitle().end(), array[i]);
      array[i][(*it)->getTitle().size()] = 0;
      ++i;
    }
  array[i] = NULL;
  return array;
}

std::vector<Object*>		TablePePeNoel::getVector() const
{
  return _objects;
}
