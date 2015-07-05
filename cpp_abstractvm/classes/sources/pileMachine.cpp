//
// pileMachine.cpp for abstractvm in /home/girard_r/rendu/cpp_abstractvm
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue Feb 24 15:47:39 2015 Aurélien GIRARDEAU
// Last update Sun Mar  1 20:17:19 2015 Aurélien GIRARDEAU
//

#include <fstream>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "Errors.hpp"
#include "pileMachine.hh"

PileMachine::PileMachine()
{
  _ptrMapNoParam["pop"] = &PileMachine::pop;
  _ptrMapNoParam["dump"] = &PileMachine::dump;
  _ptrMapNoParam["add"] = &PileMachine::add;
  _ptrMapNoParam["sub"] = &PileMachine::sub;
  _ptrMapNoParam["mul"] = &PileMachine::mul;
  _ptrMapNoParam["div"] = &PileMachine::div;
  _ptrMapNoParam["mod"] = &PileMachine::mod;
  _ptrMapNoParam["print"] = &PileMachine::print;
  _ptrMapNoParam["exit"] = &PileMachine::exit;
  _ptrMapParam["push"] = &PileMachine::push;
  _ptrMapParam["assert"] = &PileMachine::assert;
  _defineType["int8"] = Int8;
  _defineType["int16"] = Int16;
  _defineType["int32"] = Int32;
  _defineType["float"] = Float;
  _defineType["double"] = Double;
  _exit = false;
}

PileMachine::~PileMachine()
{
  while (_pile.size() > 0)
    _pile.pop_front();
}

PileMachine::PileMachine(const PileMachine &other)
{
  _exit = other._exit;
  _pile = other._pile;
  _ptrMapNoParam = other._ptrMapNoParam;
  _ptrMapParam = other._ptrMapParam;
  _defineType = other._defineType;
}

PileMachine&		PileMachine::operator=(const PileMachine &other)
{
  _exit = other._exit;
  _pile = other._pile;
  _ptrMapNoParam = other._ptrMapNoParam;
  _ptrMapParam = other._ptrMapParam;
  _defineType = other._defineType;
  return *this;
}

bool			is_num(std::string const &value)
{
  for (unsigned int i = 0; i != value.size(); i++)
    {
      if (value.size() >= 1 && value[0] == '-')
	continue;
      if (value[i] != '.' && (value[i] < '0' || value[i] > '9'))
	return false;
    }
  return true;
}

bool			PileMachine::push(std::string const& arg)
{
  std::size_t		pos;
  std::string		type;
  std::string		value;

  pos = arg.find('(');
  type = arg.substr(0, pos);
  value = arg.substr(pos + 1, arg.length() - type.length() - 2);
  _pile.push_front(_factory.createOperand(_defineType[type], value));
  return true;
}

bool			PileMachine::pop()
{
  if (!_pile.empty())
    _pile.pop_front();
  else
    throw MainException("'pop' on empty stack : failure");
  return true;
}

bool			PileMachine::dump()
{
  for (std::deque<IOperand*>::iterator it = _pile.begin(); it != _pile.end(); it++)
    std::cout << (*it)->toString() << std::endl;
  return true;
}

bool			PileMachine::assert(std::string const& arg)
{
  std::string		value;
  std::size_t		pos_first;
  std::size_t		pos_second;
  std::istringstream	is;
  std::string		type;

  is.str(arg);
  is >> type;
  type = type.substr(0, type.find("("));
  pos_first = arg.find('(');
  pos_second = arg.find(')');
  value = arg.substr(pos_first + 1, (pos_second - pos_first) - 1);
  if (_pile.empty())
    throw MainException("'assert' on empty stack : failure");
  if (_pile.front()->getType() != _defineType[type]
      || _pile.front()->toString() != value)
    throw MainException("Value or type passed to assert is not verified : " + arg);
  return true;
}

bool			PileMachine::add()
{
  IOperand*		res;
  IOperand*		op1;
  IOperand*		op2;

  if (!(_pile.size() >= 2))
    throw MainException("Not enough values to process operation 'add'");
  op1 = _pile[0];
  op2 = _pile[1];
  _pile.pop_front();
  _pile.pop_front();
  res = *op1 + *op2;
  delete op1;
  delete op2;
  _pile.push_front(res);
  return true;
}

bool			PileMachine::sub()
{
  IOperand*		op1;
  IOperand*		op2;
  IOperand*		res;

  if (!(_pile.size() >= 2))
    throw MainException("Not enough values to process operation 'sub'");
  op1 = _pile[0];
  op2 = _pile[1];
  _pile.pop_front();
  _pile.pop_front();
  res = *op2 - *op1;
  delete op1;
  delete op2;
  _pile.push_front(res);
  return true;
}

bool			PileMachine::mul()
{
  IOperand*		op1;
  IOperand*		op2;
  IOperand*		res;

  if (!(_pile.size() >= 2))
    throw MainException("Not enough values to process operation 'mul'");
  op1 = _pile[0];
  op2 = _pile[1];
  _pile.pop_front();
  _pile.pop_front();
  res = *op1 * *op2;
  delete op1;
  delete op2;
  _pile.push_front(res);
  return true;
}

bool			PileMachine::div()
{
  IOperand*		op1;
  IOperand*		op2;
  IOperand*		res;

  if (!(_pile.size() >= 2))
    throw MainException("Not enough values to process operation 'div'");
  op1 = _pile[0];
  op2 = _pile[1];
  _pile.pop_front();
  _pile.pop_front();
  res = *op2 / *op1;
  delete op1;
  delete op2;
  _pile.push_front(res);
  return true;
}

bool			PileMachine::mod()
{
    IOperand*		op1;
  IOperand*		op2;
  IOperand*		res;

  if (!(_pile.size() >= 2))
    throw MainException("Not enough values to process operation 'mod'");
  op1 = _pile[0];
  op2 = _pile[1];
  _pile.pop_front();
  _pile.pop_front();
  res = *op2 % *op1;
  delete op1;
  delete op2;
  _pile.push_front(res);
  return true;
}

bool			PileMachine::print()
{
  short			trans;
  std::istringstream	convert;

  if (_pile.empty())
    throw MainException("Not enough values to process operation 'print'");
  else if (_pile.front()->getType() != Int8)
    throw MainException("Passing wrong argument to operation 'print' (not an Int8)");
  else
    {
      convert.str(_pile.front()->toString());
      convert >> trans;
      std::cout << static_cast<char>(trans) << std::endl;
    }
  return true;
}

bool			PileMachine::exit()
{
  return false;
}

std::string		process_comment(std::string str)
{
  if (str == ";;")
    return str;
  str = str.substr(0, str.find(';'));
  return str;
}

bool			PileMachine::parse_line(char buff[1024])
{
  std::istringstream	line;
  std::string		cmd;
  std::string		arg;

  line.str(buff);
  line.str(process_comment(line.str()));
  if (line.str().empty())
    return true;
  line >> cmd;
  if (_ptrMapNoParam[cmd])
    return ((this->*_ptrMapNoParam[cmd])());
  line >> arg;
  return ((this->*_ptrMapParam[cmd])(arg));
}

void			PileMachine::checkArgValidity(std::string const& cmd, std::string const& arg)
{
  std::istringstream	is;
  std::string		type;
  size_t		pos_first;
  size_t		pos_second;
  std::string		value;

  if (arg.empty())
    throw MainException("use of instruction '" + cmd + "' without argument");
  is.str(arg);
  is >> type;
  type = type.substr(0, type.find("("));
  pos_first = arg.find('(');
  pos_second = arg.find(')');
  value = arg.substr(pos_first + 1, (pos_second - pos_first) - 1);
  if (pos_first == std::string::npos
      || pos_first == std::string::npos
      || pos_second < pos_first
      || value.empty())
    throw MainException("Syntax Error on : [" + arg + "]");
  if (type != "int8" && !_defineType[type])
    throw MainException("Unknown type name " + type);
  else if (!is_num(value))
    throw MainException(value + " is not a valid argument");
}

void			PileMachine::lex_line(char buff[1024])
{
  std::istringstream	line;
  std::string		cmd;
  std::string		arg;

  line.str(buff);
  line.str(process_comment(line.str()));
  if (line.str().empty())
    return ;
  line >> cmd;
  line >> arg;
  if (cmd == "exit")
    _exit = true;
  if (!_ptrMapNoParam[cmd] && !_ptrMapParam[cmd])
    throw MainException("No such instruction : '" + cmd + "'");
  if (_ptrMapParam[cmd])
    this->checkArgValidity(cmd, arg);
}

void			PileMachine::getContentToProcess(char *file)
{
  std::istream*		toRead = &std::cin;
  std::ifstream		getFile;
  std::istringstream	is;
  char			buff[1024];
  std::string		line;

  if (!file)
    {
      _standardEntry = true;
      while (toRead->getline(buff, 1024))
	{
	  is.clear();
	  is.str(buff);
	  is >> line;
	  if (line == ";;")
	    break;
	  line = buff;
	  _content += line + "\n";
	}
    }
  else
    {
      _standardEntry = false;
      getFile.open(file);
      if (!getFile.is_open())
  	{
  	  std::string const	wrongFile = file;
  	  throw MainException("No such file : " + wrongFile);
  	}
      toRead = &getFile;
      while (toRead->getline(buff, 1024))
	{
	  line = buff;
	  _content += line + "\n";
	}
    }
}

void			PileMachine::run(char *file)
{
  std::istringstream	is;
  char			buff[1024];

  this->getContentToProcess(file);
  is.str(_content);
  while (is.getline(buff, 1024))
    lex_line(buff);
  if (!_exit)
    throw MainException("Program ended without instruction 'exit'");
  is.clear();
  is.str(_content);
  while (is.getline(buff, 1024))
    {
      if (!parse_line(buff))
	return ;
    }
}
