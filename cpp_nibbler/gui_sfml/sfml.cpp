//
// sfml.cpp for nibb in /home/roman/Documents/dev/cpp_nibbler/gui_sfml
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Thu Mar 26 15:00:11 2015 grout_r
// Last update Sun Apr  5 11:39:52 2015 grout_r
//

#include "sfml.hh"

Sfml::Sfml()
{
}

Sfml::~Sfml()
{
}

void			Sfml::colorizeBlock(std::pair <int, int> pos, sf::Color color)
{
  sf::Shape		carre;
  
  carre.AddPoint(pos.first, pos.second, color, sf::Color(0 , 0, 0));
  carre.AddPoint(pos.first + 10, pos.second, color, sf::Color(0 , 0, 0));
  carre.AddPoint(pos.first + 10, pos.second + 10, color, sf::Color(0 , 0, 0));
  carre.AddPoint(pos.first, pos.second + 10, color, sf::Color( 0, 0, 0));
  this->app->Draw(carre);
  this->app->Display();
}

bool			Sfml::initGui(int x, int y)
{
  this->x = x * 10;
  this->y = y * 10;
  this->app = new sf::RenderWindow(sf::VideoMode(this->x, this->y, 32), "Nibbler");
  if (!font.LoadFromFile("./gui_sfml/ressources/font.ttf"))
    {
      std::cout << "Fail to load ressources." << std::endl;
      this->freeObject();
      return false;
    }
  this->app->Clear();
  this->app->Display();
  return true;
}

e_way			Sfml::getEvent()
{
  sf::Event event;

  while (this->app->GetEvent(event))
    {
      if (event.Type == sf::Event::Closed)
	return EXIT;
      if (event.Type == sf::Event::KeyPressed)
	switch (event.Key.Code)
	  {
	  case sf::Key::Up :
	    return TOP;
	  case sf::Key::Down :
	    return DOWN;
	  case sf::Key::Left :
	    return LEFT;
	  case sf::Key::Right :
	    return RIGHT;
	  default :
	    return NOTHING;
	  }
      return NOTHING;
    }
  return NOTHING;  
}

bool						Sfml::moveSnake(std::pair<unsigned int, unsigned int> from ,
								std::pair<unsigned int, unsigned int> to ,
								bool food)
{
  std::pair<unsigned int, unsigned int>		newFrom = std::make_pair(from.first * 10, from.second * 10);
  std::pair<unsigned int, unsigned int>		newTo = std::make_pair(to.first * 10, to.second * 10);

  this->colorizeBlock(newTo, sf::Color::Red);
  this->colorizeBlock(newFrom, sf::Color::Black);  
  return food;
}

bool						Sfml::addItem(std::pair<int, int> pos,
							      e_itemType type)
{
  std::pair<unsigned int, unsigned int>		newItem = std::make_pair(pos.first * 10, pos.second * 10);

  switch (type)
    {
    case GROW :
      {
	this->colorizeBlock(newItem, sf::Color::Blue);
	break;
      }
    case SPEED :
      {
	this->colorizeBlock(newItem, sf::Color::Green);
	break;
      }
    case INVERT :
      {
	this->colorizeBlock(newItem, sf::Color::Yellow);
	break;
      }
    default :
      return false;
    }
  return true;
}

void						Sfml::freeObject()
{
  this->app->Close();
  delete this->app;
}

void						Sfml::printGameOver()
{
  sf::Image					gameOver;
  sf::Sprite				        sprite;

  if (!gameOver.LoadFromFile("./gui_sfml/ressources/go.jpg"))
    return (this->freeObject());
  sprite.SetImage(gameOver);
  sprite.SetPosition((this->x / 2) - (gameOver.GetWidth() / 2), 
  (this->y / 2) - (gameOver.GetHeight() / 2));
  this->app->Draw(sprite);
}

void						Sfml::printScore(size_t score)
{
  std::ostringstream				oss;
  std::string					message;
  sf::String					text;

  oss << score;
  message = "   YOU SUCKS .\nYOUR SCORE IS " + oss.str();
  text.SetColor(sf::Color::Red);
  text.SetText(message);
  text.SetFont(this->font);
  text.SetSize(50);
  text.SetPosition((this->x / 2) - (text.GetRect().GetWidth() / 2), 
		   (this->y / 6));
  this->app->Draw(text);
}

void						Sfml::gameOver(size_t score)
{
  this->printGameOver();
  this->printScore(score);
  this->app->Display();
  sleep(3);
  this->freeObject();
}

extern "C"
{
  Sfml		*getInstance()
  {
    return new Sfml();
  }
}
