//
// Exceptions.hpp for plazza in /home/girard_r/Documents/plazza/tp
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Fri Apr 17 16:37:06 2015 Aurélien GIRARDEAU
// Last update Sat Apr 25 15:55:48 2015 Aurélien GIRARDEAU
//

#ifndef EXCEPTIONS_HH_
# define EXCEPTIONS_HH_

# include <exception>
# include <string>
# include <stdio.h>
# include <string.h>
# include <errno.h>

namespace	PlazzaError
{
  class		NoMoreTasks : public std::exception
  {
  public :
    NoMoreTasks(std::string const& message) throw()
      : _message(message) {}
    virtual ~NoMoreTasks() throw() {}
    virtual const char*	what() const throw()
    { return _message.c_str(); }
  private :
    std::string	_message;
  };

  class		NoMoreIngredients : public std::exception
  {
  public :
    NoMoreIngredients(std::string const& message)
      : _message(message) {}
    virtual ~NoMoreIngredients() throw() {}
    virtual const char*	what() const throw()
    { return _message.c_str(); }
  private :
    std::string	_message;
  };

  class		ClosingThreads : public std::exception
  {
  public :
    ClosingThreads(std::string const& message)
      : _message(message) {}
    virtual ~ClosingThreads() throw() {}
    virtual const char*	what() const throw()
    { return _message.c_str(); }
  private :
    std::string	_message;
  };

  class		ProcessError : public std::exception
  {
  public :
    ProcessError(int error, std::string const& message)
      : _error(error), _message(message) {}
    virtual ~ProcessError() throw() {}
    virtual const char*	what() const throw()
    {
      std::string	tmp(strerror(_error));

      tmp += " " + _message;
      return tmp.c_str();
    }
  private :
    int		_error;
    std::string	_message;
  };

  class		ThreadError : public std::exception
  {
  public :
    ThreadError(int error, std::string const& message)
      : _error(error), _message(message) {}
    virtual ~ThreadError() throw() {}
    virtual const char*	what() const throw()
    {
      std::string	tmp(strerror(_error));

      tmp += " " + _message;
      return tmp.c_str();
    }
  private :
    int		_error;
    std::string	_message;
  };

  class		NamedPipeError : public std::exception
  {
  public :
    NamedPipeError(int error, std::string const& message)
      : _error(error), _message(message) {}
    virtual ~NamedPipeError() throw() {}
    virtual const char*	what() const throw()
    {
      std::string	tmp(strerror(_error));

      tmp += " " + _message;
      return tmp.c_str();
    }
  private :
    int		_error;
    std::string	_message;
  };

  class		GuiError : public std::exception
  {
  public :
    GuiError(std::string const& message)
      : _message(message) {}
    virtual ~GuiError() throw() {}
    virtual const char*	what() const throw()
    { return _message.c_str(); }
  private :
    std::string	_message;
  };
};

#endif /* !EXCEPTIONS_HH_ */
