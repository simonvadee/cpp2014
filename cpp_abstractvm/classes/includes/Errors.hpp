//
// Errors.hpp for abstractvm in /home/girard_r/rendu/cpp_abstractvm/classes
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Sat Feb 14 12:32:20 2015 Aurélien GIRARDEAU
// Last update Mon Feb 23 14:23:33 2015 Aurélien GIRARDEAU
//

#ifndef ERRORS_HPP_
# define ERRORS_HPP_

# include <string>
# include <exception>

/*
** Le programme assembleur comporte une ou plusieurs fautes lexicales ou syntaxiques
*/
class		MainException : public std::exception
{
 public :
  MainException(std::string const& message)
    : _message(message) {}
  virtual ~MainException() throw() {}
  virtual const char*	what() const throw()
  { return _message.c_str(); }
 private :
  std::string	_message;
};

// /*
// ** Une instruction est inconnue
// */
// class		UnknownInstructionException : public std::exception
// {
//  public :
//   UnknownInstructionException(std::string const& message)
//     : _message(message) {}
//   virtual ~UnknownInstructionException() throw() {}
//   virtual const char*	what() const throw()
//   { return _message.c_str(); }
//  private :
//   std::string	_message;
// };

// /*
// ** Overflow sur une valeur
// */
// class		OverflowException : public std::exception
// {
//  public :
//   OverflowException(std::string const& message)
//     : _message(message) {}
//   virtual ~OverflowException() throw() {}
//   virtual const char*	what() const throw()
//   { return _message.c_str(); }
//  private :
//   std::string	_message;
// };

// /*
// ** Underflow sur une valeur
// */
// class		UnderflowException : public std::exception
// {
//  public :
//   UnderflowException(std::string const& message)
//     : _message(message) {}
//   virtual ~UnderflowException() throw() {}
//   virtual const char*	what() const throw()
//   { return _message.c_str(); }
//  private :
//   std::string	_message;
// };

// /*
// ** Instruction pop sur une pile vide
// */
// class		EmptyPopException : public std::exception
// {
//  public :
//   EmptyPopException(std::string const& message)
//     : _message(message) {}
//   virtual ~EmptyPopException() throw() {}
//   virtual const char*	what() const throw()
//   { return _message.c_str(); }
//  private :
//   std::string	_message;
// };

// /*
// ** Division / Modulo par 0
// */
// class		FloatingPointException : public std::exception
// {
//  public :
//   FloatingPointException(std::string const& message)
//     : _message(message) {}
//   virtual ~FloatingPointException() throw() {}
//   virtual const char*	what() const throw()
//   { return _message.c_str(); }
//  private :
//   std::string	_message;
// };

// /*
// ** Le programme ne comporte pas d’instruction exit
// */
// class		NoExitException : public std::exception
// {
//  public :
//   NoExitException(std::string const& message)
//     : _message(message) {}
//   virtual ~NoExitException() throw() {}
//   virtual const char*	what() const throw()
//   { return _message.c_str(); }
//  private :
//   std::string	_message;
// };

// /*
// ** Une instruction assert n'est pas vérifiée
// */
// class		UncheckAssertException : public std::exception
// {
//  public :
//   UncheckAssertException(std::string const& message)
//     : _message(message) {}
//   virtual ~UncheckAssertException() throw() {}
//   virtual const char*	what() const throw()
//   { return _message.c_str(); }
//  private :
//   std::string	_message;
// };

// /*
// ** La pile comporte strictement moins de deux valeurs lors de l’execution d’une instruction arithmetique
// */
// class		MissOperandsException : public std::exception
// {
//  public :
//   MissOperandsException(std::string const& message)
//     : _message(message) {}
//   virtual ~MissOperandsException() throw() {}
//   virtual const char*	what() const throw()
//   { return _message.c_str(); }
//  private :
//   std::string	_message;
// };

#endif
