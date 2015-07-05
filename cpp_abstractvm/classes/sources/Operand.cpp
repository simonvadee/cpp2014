//
// Operand.cpp for Operand in /home/girard_r/rendu/cpp_abstractvm/classes/sources
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue Feb 10 15:19:55 2015 Aurélien GIRARDEAU
// Last update Sun Mar  1 16:44:23 2015 Aurélien GIRARDEAU
//

#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "Operand.hh"

template <typename T>
Operand<T>::Operand(T operand, int precision, eOperandType type)
  : _operand(operand), _precision(precision), _type(type), _factory(new OperandFactory())
{
}

template <typename T>
Operand<T>::Operand(Operand const& other)
  : _operand(other._operand), _precision(other._precision), _type(other._type), _factory(new OperandFactory())
{
}

template <typename T>
Operand<T>::~Operand()
{
  delete _factory;
}

template <typename T>
Operand<T>&		Operand<T>::operator=(Operand const& other)
{
  _operand = other._operand;
  _precision = other._precision;
  _type = other._type;
  return (*this);
}

template <typename T>
std::string const&	Operand<T>::toString() const
{
  std::ostringstream	os;
  static std::string   	operand;

  if (_precision == 1)
    os << static_cast<int>(_operand);
  else
    os << _operand;
  operand = os.str();
  return (operand);
}

template <typename T>
int			Operand<T>::getPrecision() const
{
  return (_precision);
}

template <typename T>
eOperandType		Operand<T>::getType() const
{
  return (_type);
}

template <typename T>
IOperand*		Operand<T>::operator+(const IOperand& rhs) const
{
  IOperand		*newOp;
  std::istringstream	is;
  T			res;
  T			right;
  std::ostringstream	error;

  if (_precision < rhs.getPrecision())
    return (rhs + *this);

  right = _factory->fromStringStream<T>(rhs.toString());
  res = right + _operand;
  if ((right > 0 && _operand > 0 && res < 0)
      || (right < 0 && _operand < 0 && res > 0))
    {
      error << "Overflow/Underflow sur " << _operand << " + " << right;
      throw MainException(error.str().c_str());
    }
  newOp = new Operand<T>(res, _precision, _type);
  return (newOp);
}

template <typename T>
IOperand*		Operand<T>::operator*(const IOperand& rhs) const
{
  IOperand*		newOp;
  T			res;
  T			right;
  T			tmp;
  std::ostringstream	error;

  if (_precision < rhs.getPrecision())
    return (rhs * *this);

  right = _factory->fromStringStream<T>(rhs.toString());
  res = right * _operand;
  if (_operand != 0 && ((tmp = res / _operand - right) > 0.000001 || tmp < -0.000001))
    {
      error << "Overflow/Underflow sur " << _operand << " * " << right;
      throw MainException(error.str().c_str());
    }
  newOp = new Operand<T>(res, _precision, _type);
  return (newOp);
}

template <typename T>
IOperand*		Operand<T>::operator-(const IOperand& rhs) const
{
  IOperand		*mul;
  IOperand		*res;

  mul = rhs * Operand<T>(-1, _precision, _type);
  if (_precision < rhs.getPrecision())
    res = *mul + *this;
  else
    res = *this + *mul;
  delete mul;
  return (res);
}

template <typename T>
IOperand*		Operand<T>::processDivOp(std::string const& op, const IOperand& rhs) const
{
  const IOperand*	first;
  const IOperand*	second;
  IOperand*		res;
  std::string		tmp;

  first = ((_precision < rhs.getPrecision()) ? _factory->createOperand(rhs.getType(), this->toString()) : this);
  second = ((_precision > rhs.getPrecision()) ? _factory->createOperand(this->getType(), rhs.toString()) : &rhs);
  if (second->toString() == "0")
    throw MainException("Division ou Modulo par 0");
  tmp = first->toString();
  tmp += op + second->toString();
  res = _factory->createOperand(first->getType(), tmp);
  if (this != first)
    delete first;
  if (second != &rhs)
    delete second;
  return res;
}

template <typename T>
IOperand*		Operand<T>::operator/(const IOperand& rhs) const
{
  return (this->processDivOp("/", rhs));
}

template <typename T>
IOperand*		Operand<T>::operator%(const IOperand& rhs) const
{
  return (this->processDivOp("%", rhs));
}
