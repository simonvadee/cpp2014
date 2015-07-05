//
// Gui.hh for plazza in /home/girard_r/Documents/plazza/gui
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Wed Apr 22 13:09:50 2015 Aurélien GIRARDEAU
// Last update Sat Apr 25 17:04:39 2015 Aurélien GIRARDEAU
//

#ifndef GUI_HH_
# define GUI_HH_

# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <cstdlib>
# include <deque>
# include <map>
# include <string>
# include <unistd.h>
# include <algorithm>
# include "Exceptions.hpp"
# include "Mutex.hh"
# include "AObj.hh"
# include "ScopedLock.hh"
# include "Input.hh"
# include "Console.hh"

class						Gui : public AObj
{
private :
  typedef void					(Gui::*eventPtr)(sf::Event const& event);

  sf::RenderWindow*				_app;
  bool						_isFinished;
  bool						_askDisplay;
  std::deque<std::string>*			_ordersFinished;
  std::deque<std::string>*			_ordersToDo;
  Input						_input;
  Console					_console;
  std::map<sf::Event::EventType, eventPtr>	_mapEvent;
  Mutex						_guiMutex;
public :
  Gui();
  virtual ~Gui();

  /*
  ** Methodes pour la réception
  */
  void				setStatus(std::string const&);
  void				printStatus(std::deque<std::string>*);
  bool				isDisplayAsked();
  void				pushOrdersFinished(std::string& finish);
  bool				ordersTryPop(std::string* order);
  void				setAskDisplayTrue();
private :
  Gui(Gui const&);
  Gui&		operator=(Gui const&);
  void		initGui();
  void		setBackground();
  void		checkOrdersFinished();
  void		pollEvent();
  void		initTools();
  void		resumeApp(sf::Event const& event);
  void		setFinished(sf::Event const& event);
  void		tryAddInput(sf::Event const& event);
  void		testCode(sf::Event const& event);
public :
  virtual void	start();
  void		setFinished();
  bool		isFinished() const;
};

#endif
