//
// NdkGui.cpp for libndknib in /home/girard_r/rendu/cpp_nibbler/gui_ndkpp
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Sat Mar 28 15:48:07 2015 Aurélien GIRARDEAU
// Last update Mon Mar 30 16:06:05 2015 Aurélien GIRARDEAU
//

#include "NdkGui.hh"

NdkGui::NdkGui()
{
  _which[KEY_UP] = TOP;
  _which[KEY_RIGHT] = RIGHT;
  _which[KEY_DOWN] = DOWN;
  _which[KEY_LEFT] = LEFT;
  _items[GROW] = '*';
  _items[SPEED] = 'S';
  _items[INVERT] = 'I';
}

NdkGui::~NdkGui()
{
}

bool		NdkGui::initGui(int width, int height)
{
  struct winsize w;

  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  if (w.ws_row < height
      || w.ws_col < width)
    return false;
  initscr();
  nodelay(stdscr, true);
  keypad(stdscr, true);
  noecho();
  curs_set(0);
  resizeterm(height + 1, width + 1);
  getmaxyx(stdscr, _maxheight, _maxwidth);
  _snakechar = 'X';
  _border = (char)219;
  _empty = ' ';
  for (int i = 0; i != _maxheight; ++i)
    {
      move(i, _maxwidth - 1);
      addch(_border);
    }
  for (int i = 0; i != _maxwidth; ++i)
    {
      move(_maxheight - 1, i);
      addch(_border);
    }
  return (true);
}

e_way					NdkGui::getEvent()
{
  int					event = getch();
  std::map<int, e_way>::iterator	it;

  if ((it = _which.find(event)) != _which.end())
    return (it->second);
  return (NOTHING);
}

bool		NdkGui::moveSnake(std::pair<unsigned int, unsigned int> from,
				  std::pair<unsigned int, unsigned int> to,
				  bool eat)
{
  if (!eat)
    {
      move(from.second, from.first);
      addch(_empty);
    }
  move(to.second, to.first);
  addch(_snakechar);
  refresh();
  return (true);
}

bool		NdkGui::addItem(std::pair<int, int> from, e_itemType type)
{
  std::map<e_itemType, char>::iterator	it;

  move(from.second, from.first);
  if ((it = _items.find(type)) == _items.end())
    return false;
  addch(it->second);
  refresh();
  return true;
}

void		NdkGui::gameOver(size_t size)
{
  std::ostringstream	result;

  clear();
  result << "SCORE : " << size << std::endl;
  mvaddstr(_maxheight / 2, _maxwidth / 2, "GAME OVER");
  mvaddstr((_maxheight / 2) + 1, _maxwidth / 2, result.str().c_str());
  refresh();
  sleep(3);
  endwin();
}

extern "C"
{
  IGui*	getInstance()
  {
    return new NdkGui;
  }
}
