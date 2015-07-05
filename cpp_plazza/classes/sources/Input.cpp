//
// Input.cpp for plazza in /home/girard_r/Documents/plazza
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Wed Apr 22 19:30:03 2015 Aurélien GIRARDEAU
// Last update Sat Apr 25 17:07:00 2015 Aurélien GIRARDEAU
//

#include "Input.hh"

Input::Input()
  : _cmp(0), _entry(""), _app(NULL), _sizeWindow(1280, 720)
{
  if (!_font.LoadFromFile("./ressources/TT_Version/ChemyRetro_v01.ttf"))
    throw PlazzaError::GuiError("error while loading font");
  _input_sizes.first = _sizeWindow.first * 3 / 5;
  _input_sizes.second = 30;
  _originInput.first = (_sizeWindow.first - _input_sizes.first) / 2;
  _originInput.second = _sizeWindow.second * 2 / 10;
}

Input::~Input()
{
}

void		Input::setTitle()
{
  sf::String	Text("Orders", _font, 30);

  Text.SetColor(sf::Color(158, 11, 15));
  Text.SetPosition((_sizeWindow.first / 2) - Text.GetRect().GetWidth() / 2,
		   _originInput.second - 50);
  _app->Draw(Text);
  _app->Display();
}

void		Input::display()
{
  sf::String	Text("", sf::Font::GetDefaultFont(), 15);
  sf::Shape	Rect;
  std::string	toDisplay(_entry);

  Rect.AddPoint(_originInput.first,
		_originInput.second,
		sf::Color(255, 255, 255),
		sf::Color(0, 0, 0));
  Rect.AddPoint(_originInput.first + _input_sizes.first,
		_originInput.second,
		sf::Color(255, 255, 255),
		sf::Color(0, 0, 0));
  Rect.AddPoint(_originInput.first + _input_sizes.first,
		_originInput.second + _input_sizes.second,
		sf::Color(255, 255, 255),
		sf::Color(0, 0, 0));
  Rect.AddPoint(_originInput.first,
		_originInput.second + _input_sizes.second,
		sf::Color(255, 255, 255),
		sf::Color(0, 0, 0));
  Rect.EnableFill(true);
  Rect.EnableOutline(true);
  Rect.SetOutlineWidth(2);
  Text.SetColor(sf::Color(128, 128, 0));
  Text.SetPosition(_originInput.first + 5, _originInput.second + 5);
  Text.SetText(_entry.substr(_cmp));
  _app->Draw(Rect);
  _app->Draw(Text);
  _app->Display();
}

void		Input::testUnderflow()
{
  sf::String	Text("", _font, 15);

  if (_cmp > 0)
    {
      Text.SetText(_entry.substr(_cmp - 1));
      if (Text.GetRect().GetWidth() + 20 < _input_sizes.first)
	{
	  _cmp -= 1;
	  testUnderflow();
	}
    }
}

void		Input::clearEntry()
{
  _entry.clear();
  _cmp = 0;
  display();
}

std::string	Input::getEntry() const
{
  return (_entry);
}

void		Input::testOverflow()
{
  sf::String	Text("", _font, 15);

  Text.SetText(_entry.substr(_cmp));
  if (Text.GetRect().GetWidth() + 20 >= _input_sizes.first)
    {
      _cmp += 1;
      testOverflow();
    }
}

void		Input::setWindow(sf::RenderWindow* window)
{
  _app = window;
  display();
}

bool		Input::handleInput(int code)
{
  sf::Vector2f	pos;

  if (_entry.size() == _entry.max_size())
    return (false);
  if (isalnum(code) || code == ' ' || code == ';')
    {
      _entry += static_cast<char>(code);
      testOverflow();
      return (true);
    }
  if (code == 8 && _entry.size() > 0)
    {
      _entry = _entry.substr(0, _entry.size() - 1);
      testUnderflow();
      return (true);
    }
  return (false);
}
