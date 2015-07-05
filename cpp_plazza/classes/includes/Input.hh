//
// Input.hh for plazza in /home/girard_r/Documents/plazza
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Wed Apr 22 18:17:12 2015 Aurélien GIRARDEAU
// Last update Sat Apr 25 14:35:53 2015 Aurélien GIRARDEAU
//

# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <iostream>
# include <string>
# include <cstdlib>
# include <utility>
# include <sstream>
# include "Exceptions.hpp"

class			Input
{
private :
  int			_cmp;
  std::string		_entry;
  sf::RenderWindow*	_app;
  std::pair<int, int>	_sizeWindow;
  std::pair<int, int>	_input_sizes;
  std::pair<int, int>	_originInput;
  sf::Font		_font;

public :
  Input();
  ~Input();
  bool		handleInput(int code);
  void		display();
  void		setWindow(sf::RenderWindow* window);
  std::string	getEntry() const;
  void		clearEntry();
  void		setTitle();
private :
  Input(Input const&);
  Input&	operator=(Input const&);

  void		testOverflow();
  void		testUnderflow();
};
