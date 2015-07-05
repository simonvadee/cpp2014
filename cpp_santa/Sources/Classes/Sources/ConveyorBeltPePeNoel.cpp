/**
 * vadee_s
 */

#include "../Includes/ConveyorBeltPePeNoel.hh"

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel(std::deque<Object*> init) : _isEmpty(true), _current(NULL)
{
  for (std::deque<Object*>::const_iterator it = init.begin(); it != init.end(); it++)
    _queue.push_back(*it);
  std::cout << "Conveyor is on his way, biatch" << std::endl;
}

ConveyorBeltPePeNoel::~ConveyorBeltPePeNoel()
{
  std::cout << "Conveyor is done for today" << std::endl;
  if (_current)
    delete _current;
  if (_queue.size() > 0)
    _queue.clear();
}

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel(ConveyorBeltPePeNoel const& other) : _isEmpty(other._isEmpty)
{
  std::deque<Object*>::const_iterator it;

  std::cout << "Conveyor is on his way, biatch" << std::endl;
  if (other._current)
      _current = other._current->clone();
  else
    _current = NULL;
  for (it = other._queue.begin(); it != other._queue.end(); it++)
    _queue.push_back(*it);
}

ConveyorBeltPePeNoel&		ConveyorBeltPePeNoel::operator=(ConveyorBeltPePeNoel const& other)
{
  _isEmpty = other._isEmpty;
  if (other._current)
    _current = other._current->clone();
  else
    _current = NULL;
  for (std::deque<Object*>::const_iterator it = other._queue.begin(); it != other._queue.end(); it++)
    _queue.push_back(*it);
  return *this;
}

bool			ConveyorBeltPePeNoel::inPressed()
{
  if (!_isEmpty)
    {
      std::cerr << NOT_EMPTY << std::endl;
      return false;
    }
  else if (_queue.empty())
    {
      std::cerr << "Error : no more object to make gifts" << std::endl;
      return false;
    }
  _current = _queue.front()->clone();
  _isEmpty = false;
  _queue.pop_front();
  return true;
}

bool			ConveyorBeltPePeNoel::outPressed()
{
  if (_isEmpty)
    {
      std::cerr << EMPTY << std::endl;
      return false;
    }
  delete _current;
  _isEmpty = true;
  return true;
}

Object*			ConveyorBeltPePeNoel::getObject() const
{
  if (_isEmpty)
    return NULL;
  return _current;
}

Object*			ConveyorBeltPePeNoel::objectTaken()
{
  Object*		ret;

  if (_isEmpty)
    {
      std::cerr << EMPTY << std::endl;
      return NULL;
    }
  _isEmpty = true;
  ret = _current->clone();
  delete _current;
  _current = NULL;
  return (ret);
}

bool			ConveyorBeltPePeNoel::setObject(Object* elem)
{
  if (!_isEmpty)
    {
      std::cerr << NOT_EMPTY << std::endl;
      return false;
    }
  _current = elem->clone();
  _isEmpty = false;
  return true;
}

bool			ConveyorBeltPePeNoel::isEmpty() const
{
  return _isEmpty;
}
