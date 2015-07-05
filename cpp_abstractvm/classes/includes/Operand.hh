//
// Operand.hh for abstractvm in /home/girard_r/rendu/cpp_abstractvm/classes/includes
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue Feb 10 15:08:06 2015 Aurélien GIRARDEAU
// Last update Mon Feb 23 16:03:06 2015 Aurélien GIRARDEAU
//

#ifndef OPERAND_HH_
# define OPERAND_HH_

# include <iostream>
# include <stdint.h>
# include <sstream>
# include <stdint.h>
# include "Errors.hpp"
# include "IOperand.hh"
# include "OperandFactory.hh"

class OperandFactory;

template <typename T>
class			Operand : public IOperand
{
private :
  T					_operand;
  int					_precision;
  eOperandType				_type;
  OperandFactory			*_factory;

public :
  Operand(T operand, int precision, eOperandType type);
  Operand(Operand const& other);
  Operand&	operator=(Operand const& other);
  virtual ~Operand();

  virtual		std::string const& toString() const;

  virtual int		getPrecision() const;
  virtual eOperandType	getType() const;

  virtual IOperand*	operator+(const IOperand &rhs) const;
  virtual IOperand*	operator-(const IOperand &rhs) const;
  virtual IOperand*	operator*(const IOperand &rhs) const;
  virtual IOperand*	operator/(const IOperand &rhs) const;
  virtual IOperand*	operator%(const IOperand &rhs) const;

private :
  IOperand*		processDivOp(std::string const&, const IOperand&) const;
};

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;

#endif
