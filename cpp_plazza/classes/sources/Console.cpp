//
// Console.cpp for console in /home/girard_r/Documents/plazza
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Thu Apr 23 21:52:51 2015 Aurélien GIRARDEAU
// Last update Fri Apr 24 16:11:49 2015 Aurélien GIRARDEAU
//

#include "Console.hh"

Console::Console()
  : _app(NULL), _sizeWindow(1280, 720)
{
  _consoleSize.first = _sizeWindow.first * 8 / 10;
  _consoleSize.second = _sizeWindow.second * 4 / 10;
  _originConsole.first = (_sizeWindow.first - _consoleSize.first) / 2;
  _originConsole.second = _sizeWindow.second * 1 / 2;
  _size = _consoleSize.second / 15;
  fillConsoleLine();
}

Console::~Console()
{
}

void		Console::fillConsoleLine()
{
  sf::String	line("", sf::Font::GetDefaultFont(), 15);

  line.SetColor(sf::Color(0, 0, 0));
  for (size_t i = 0; i < _size; ++i)
    {
      if (i == _size - 1)
	line.SetText("Welcome to plazza ! Here orders finished are displayed");
      line.SetPosition(_originConsole.first, _originConsole.second + i * 15);
      _consoleLine.push_front(line);
    }
    
}

void					Console::displayConsoleLine()
{
  std::deque<sf::String>::iterator	it;

  for (it = _consoleLine.begin(); it != _consoleLine.end(); ++it)
    _app->Draw(*it);
  _app->Display();
}

void		Console::display()
{
  sf::Shape	Rect;

  Rect.AddPoint(_originConsole.first,
		_originConsole.second,
		sf::Color(255, 255, 255),
		sf::Color(0, 0, 0));
  Rect.AddPoint(_originConsole.first + _consoleSize.first,
		_originConsole.second,
		sf::Color(255, 255, 255),
		sf::Color(0, 0, 0));
  Rect.AddPoint(_originConsole.first + _consoleSize.first,
		_originConsole.second + _consoleSize.second,
		sf::Color(255, 255, 255),
		sf::Color(0, 0, 0));
  Rect.AddPoint(_originConsole.first,
		_originConsole.second + _consoleSize.second,
		sf::Color(255, 255, 255),
		sf::Color(0, 0, 0));
  Rect.EnableFill(true);
  Rect.EnableOutline(true);
  Rect.SetOutlineWidth(2);
  _app->Draw(Rect);
  _app->Display();
  displayConsoleLine();
}

void		Console::addLine(std::string const& line)
{
  rotateConsole(line);
  display();
}

void		Console::setWindow(sf::RenderWindow* window)
{
  _app = window;
  display();
}

void		Console::removeLine()
{
}

void		Console::rotateConsole(std::string const& line)
{
  std::deque<sf::String>::iterator	it;
  std::string				tmp;
  std::string				newLine(line);

  for (it = _consoleLine.begin(); it != _consoleLine.end(); ++it)
    {
      tmp = it->GetText();
      it->SetText(newLine);
      newLine = tmp;
    }
}
