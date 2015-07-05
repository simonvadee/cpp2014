//
// Console.hh for plazza in /home/girard_r/Documents/plazza
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Thu Apr 23 21:53:13 2015 Aurélien GIRARDEAU
// Last update Fri Apr 24 16:10:38 2015 Aurélien GIRARDEAU
//

#ifndef CONSOLE_HH_
# define CONSOLE_HH_

# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <iostream>
# include <string>
# include <deque>
# include <utility>

class				Console
{
private :
  sf::RenderWindow*		_app;
  std::pair<int, int>		_sizeWindow;
  std::pair<int, int>		_originConsole;
  std::pair<int, int>		_consoleSize;
  std::deque<sf::String>	_consoleLine;
  size_t			_size;

public :
  Console();
  ~Console();
  void				addLine(std::string const&);
  void				setWindow(sf::RenderWindow* window);
  void				display();

private :
  Console(Console const&);
  Console&			operator=(Console const&);

  void				removeLine();
  void				rotateConsole(std::string const&);
  void				fillConsoleLine();
  void				displayConsoleLine();
};

#endif /* !CONSOLE_HH_ */
