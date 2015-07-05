//
// OperandFactory.cpp for abstractvm in /home/girard_r/rendu/cpp_abstractvm/classes/sources
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Fri Feb 13 11:55:07 2015 Aurélien GIRARDEAU
// Last update Sat Feb 28 16:50:04 2015 Aurélien GIRARDEAU
//

#include <iomanip>
#include <float.h>
#include "OperandFactory.hh"

IOperand*	OperandFactory::createOperand(eOperandType type, const std::string& value)
{
  return ((this->*_createPtr[type])(value));
}

OperandFactory::OperandFactory()
{
  _createPtr[0] = &OperandFactory::createInt8;
  _createPtr[1] = &OperandFactory::createInt16;
  _createPtr[2] = &OperandFactory::createInt32;
  _createPtr[3] = &OperandFactory::createFloat;
  _createPtr[4] = &OperandFactory::createDouble;
}

OperandFactory::~OperandFactory()
{
}

template <typename T>
T			OperandFactory::modulus(T from, T quotient)
{
  T			tmpFrom;
  T			tmpQuotient;

  tmpFrom = (from > 0 ? from : -from);
  tmpQuotient = (quotient > 0 ? quotient : -quotient);
  while (tmpFrom >= tmpQuotient)
    tmpFrom -= tmpQuotient;
  if (from < 0)
    tmpFrom *= -1;
  return tmpFrom;
}

template <typename T>
T			OperandFactory::processString(const std::string& value, size_t& pos)
{
  T			left;
  T			right;
  std::istringstream	is;
  T			res;
  T			test;

  is.str(value.substr(0, pos) + " " + value.substr(pos + 1));
  is >> left;
  is >> right;
  if (value.c_str()[pos] == '/')
    {
      res = left / right;
      test = res * right;
      if (test - left > right || test - left < -right)
	{
	  std::string error = "Overflow/Underflow sur " + value.substr(0, pos) + " / " + value.substr(pos + 1);
	  throw MainException(error.c_str());
	}
      return (res);
    }
  return (modulus(left, right));
}

template <typename T>
T			OperandFactory::fromStringStream(const std::string& value)
{
  T			num;
  std::istringstream	is;

  is.str(value);
  is >> num;
  return num;
}

template <>
int8_t			OperandFactory::fromStringStream(const std::string& value)
{
  int			num;
  int8_t		toReturn;
  std::istringstream	is;

  is.str(value);
  is >> num;
  toReturn = num;
  return toReturn;
}

template <typename T>
T			OperandFactory::fromString(const std::string& value)
{
  T			num;
  std::ostringstream	os;
  size_t		pos;
  std::string		tmp;

  if ((pos = value.find("/")) != std::string::npos
      || (pos = value.find("%")) != std::string::npos)
    return this->processString<T>(value, pos);

  num = this->fromStringStream<T>(value);
  if ((pos = value.find(".")) != std::string::npos)
    os << std::fixed << std::setprecision(value.substr(pos).size()) << num;
  else
    os << std::fixed << num;
  tmp = os.str();
  if (tmp.size() > value.size())
    tmp = tmp.substr(0, value.size());
  if (tmp.compare(0, MIN(7, value.size()), value, 0, MIN(7, value.size())) != 0)
    {
      std::string error = "Overflow/Underflow sur " + value;
      throw MainException(error.c_str());
    }
  return (num);
}

template <>
int8_t			OperandFactory::fromString(const std::string& value)
{
  int8_t		num;
  int			tmp;
  size_t		pos;

  if ((pos = value.find("/")) != std::string::npos
      || (pos = value.find("%")) != std::string::npos)
    return this->processString<int8_t>(value, pos);
  num = fromStringStream<int8_t>(value);
  tmp = fromStringStream<int32_t>(value);
  if (tmp - num != 0)
    {
      std::string error = "Overflow/Underflow sur " + value;
      throw MainException(error.c_str());
    }
  return num;
}

IOperand*		OperandFactory::createInt8(const std::string& value)
{
  int8_t		operand;

  operand = this->fromString<int8_t>(value);
  return (new Operand<int8_t>(operand, 1, Int8));
}

IOperand*		OperandFactory::createInt16(const std::string& value)
{
  int16_t		operand;

  operand = this->fromString<int16_t>(value);
  return (new Operand<int16_t>(operand, 2, Int16));
}

IOperand*		OperandFactory::createInt32(const std::string& value)
{
  int32_t		operand;

  operand = this->fromString<int32_t>(value);
  return (new Operand<int32_t>(operand, 3, Int32));
}

IOperand*		OperandFactory::createFloat(const std::string& value)
{
  float			operand;

  operand = this->fromString<float>(value);
  return (new Operand<float>(operand, 4, Float));
}

IOperand*		OperandFactory::createDouble(const std::string& value)
{
  double		operand;

  operand = this->fromString<double>(value);
  return (new Operand<double>(operand, 5, Double));
}
