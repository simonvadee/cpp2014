//
// OperandFactory.hh for abstractvm in /home/girard_r/rendu/cpp_abstractvm/classes/sources
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Fri Feb 13 11:54:58 2015 Aurélien GIRARDEAU
// Last update Sun Mar  1 15:19:56 2015 Aurélien GIRARDEAU
//

#ifndef OPERAND_FACTORY_HH_
# define OPERAND_FACTORY_HH_

# include <string>
# include "Operand.hh"
# include "Errors.hpp"

# define MIN(x, y) ((x) > (y) ? (y) : (x))

class			OperandFactory
{
  typedef IOperand*	(OperandFactory::*ptrFactory)(const std::string& value);

  ptrFactory		_createPtr[5];
private :
  IOperand*		createInt8(const std::string& value);
  IOperand*		createInt16(const std::string& value);
  IOperand*		createInt32(const std::string& value);
  IOperand*		createFloat(const std::string& value);
  IOperand*		createDouble(const std::string& value);
  template <typename T>
  T			fromString(const std::string& value);
  template <typename T>
  T		        processString(const std::string& value, size_t& pos);
  template <typename T>
  T			modulus(T from, T quotient);

public :
  OperandFactory();
  ~OperandFactory();
  IOperand*		createOperand(eOperandType type, const std::string& value);
  template <typename T>
  T			fromStringStream(const std::string& value);
};

#endif
