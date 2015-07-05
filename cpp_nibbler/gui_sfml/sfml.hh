//
// sfml.hh for nibb in /home/roman/Documents/dev/cpp_nibbler/gui_sfml
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Thu Mar 26 14:58:50 2015 grout_r
// Last update Thu Apr  2 14:23:04 2015 roman grout
//

#ifndef SFML_H_
# define SFML_H_

# include <iostream>
# include <unistd.h>
# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <sstream>
# include "IGui.hh"

class							Sfml : public IGui
{
private:
  int							x;
  int							y;
  sf::RenderWindow*					app;
  sf::Font						font;

  void							colorizeBlock(std::pair <int, int> pos, sf::Color);
  void							freeObject();
  void							printGameOver();
  void							printScore(size_t score);
public:
  Sfml();
  ~Sfml();
  bool							initGui(int x, int y);
  e_way							getEvent();
  bool							moveSnake(std::pair<unsigned int , unsigned int> from, 
								  std::pair<unsigned int, unsigned int> to,
								  bool eat);
  bool							addItem(std::pair<int, int> from, 
								e_itemType type);
  void							gameOver(size_t score);
};

#endif
