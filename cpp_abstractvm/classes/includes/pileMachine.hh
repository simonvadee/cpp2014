/**
 ** vadee_s
 */

#ifndef PILEMACHINE_H_
# define PILEMACHINE_H_

#include <iostream>
#include <deque>
#include <map>
#include "Operand.hh"
#include "OperandFactory.hh"

class		PileMachine
{

public:

  PileMachine();
  ~PileMachine();

  void		run(char* file);

private:

  PileMachine(const PileMachine &);
  PileMachine &operator=(const PileMachine &);

  bool		push(std::string const& value);
  bool		pop();
  bool		dump();
  bool		assert(std::string const& value);
  bool		add();
  bool		sub();
  bool		mul();
  bool		div();
  bool		mod();
  bool		print();
  bool		exit();

  void		getContentToProcess(char *file);
  bool		parse_line(char buff[1024]);
  void		lex_line(char buff[1024]);
  void		checkArgValidity(std::string const& cmd, std::string const& arg);

private:

  OperandFactory	_factory;
  bool			_exit;
  bool			_standardEntry;
  std::string		_content;

  std::deque<IOperand*>	_pile;

  typedef	bool		(PileMachine::*funcPtrNoParam)();
  typedef	bool		(PileMachine::*funcPtrParam)(std::string const& value);

  std::map<std::string, funcPtrNoParam>	_ptrMapNoParam;
  std::map<std::string, funcPtrParam>  	_ptrMapParam;

  std::map<std::string, eOperandType>	_defineType;
};

#endif /* !PILEMACHINE_H_ */
