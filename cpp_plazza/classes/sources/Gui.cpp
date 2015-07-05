//
// Gui.cpp for plazza in /home/girard_r/Documents/plazza/gui
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Wed Apr 22 13:28:32 2015 Aurélien GIRARDEAU
// Last update Sun Apr 26 17:17:25 2015 Aurélien GIRARDEAU
//

// #include <X11/Xlib.h>
#include <iostream>
#include "Gui.hh"
#include "Exceptions.hpp"

Gui::Gui()
  : _app(NULL),
    _isFinished(false),
    _askDisplay(false),
    _ordersFinished(new std::deque<std::string>),
    _ordersToDo(new std::deque<std::string>)
{
  _mapEvent[sf::Event::Closed] = &Gui::setFinished;
  _mapEvent[sf::Event::TextEntered] = &Gui::tryAddInput;
  _mapEvent[sf::Event::KeyPressed] = &Gui::testCode;
  _mapEvent[sf::Event::GainedFocus] = &Gui::resumeApp;
}

Gui::~Gui()
{
  delete _ordersFinished;
  delete _ordersToDo;
  if (_app)
    delete _app;
}

void		Gui::resumeApp(sf::Event const&)
{
  setBackground();
  _input.display();
  _input.setTitle();
  _console.display();
}

void		Gui::testCode(sf::Event const& event)
{
  std::string	cpy;

  if (event.Key.Code == sf::Key::Return)
    {
      cpy = _input.getEntry();
      std::transform(cpy.begin(), cpy.end(), cpy.begin(), ::tolower);
      if (cpy == "ask status")
	{
	  setAskDisplayTrue();
	  std::string	request = "Request for status received, processing ...";
	  pushOrdersFinished(request);
	  return ;
	}
      _ordersToDo->push_front(_input.getEntry());
      _input.clearEntry();
    }
}

void		Gui::setFinished(sf::Event const&)
{
  ScopedLock	lock(_guiMutex);

  _isFinished = true;
}

void		Gui::setFinished()
{
  ScopedLock	lock(_guiMutex);

  _isFinished = true;
}

void		Gui::tryAddInput(sf::Event const& event)
{
  if (_input.handleInput(event.Text.Unicode))
    _input.display();
}

void							Gui::pollEvent()
{
  sf::Event						event;
  std::map<sf::Event::EventType, eventPtr>::iterator	it;

  if (_app->GetEvent(event) && (it = _mapEvent.find(event.Type)) != _mapEvent.end())
    (this->*it->second)(event);
}


void		Gui::checkOrdersFinished()
{
  ScopedLock	lock(_guiMutex);

  while (!_ordersFinished->empty())
    {
      _console.addLine(_ordersFinished->front());
      _ordersFinished->pop_front();
    }
}

void		Gui::initTools()
{
  initGui();
  setBackground();
  _input.setWindow(_app);
  _input.setTitle();
  _console.setWindow(_app);
}

void		Gui::start()
{
  try
    {
      initTools();
      while (!_isFinished)
	{
	  pollEvent();
	  checkOrdersFinished();
	}
    }
  catch (PlazzaError::GuiError e)
    {
      std::cerr << e.what() << std::endl;
    }
  _app->Close();
}

void		Gui::setAskDisplayTrue()
{
  ScopedLock	lock(_guiMutex);

  _askDisplay = true;
}

void		Gui::setBackground()
{
  sf::Shape	background;

  background.AddPoint(20, 20, sf::Color(255, 255, 230), sf::Color(102, 0, 0));
  background.AddPoint(20, 699, sf::Color(255, 255, 102), sf::Color(29, 0, 0));
  background.AddPoint(1259, 699, sf::Color(255, 255, 230), sf::Color(102, 0, 0));
  background.AddPoint(1259, 20, sf::Color(255, 255, 102), sf::Color(29, 0, 0));
  background.EnableFill(true);
  background.EnableOutline(true);
  background.SetOutlineWidth(20);
  _app->Draw(background);
  _app->Display();
}

void		Gui::initGui()
{
  _app = new sf::RenderWindow(sf::VideoMode(1280, 720, 32), "***** Plazza *****");
  _app->Clear();
  _app->Display();
}

bool		Gui::isDisplayAsked()
{
  ScopedLock	lock(_guiMutex);
  bool		ret;

  ret = _askDisplay;
  _askDisplay = false;
  return (ret);
}

void		Gui::pushOrdersFinished(std::string& finish)
{
  ScopedLock	lock(_guiMutex);

  _ordersFinished->push_back(finish);
}

bool		Gui::ordersTryPop(std::string* order)
{
  ScopedLock	lock(_guiMutex);

  if (!_ordersToDo->empty())
    {
      *order = _ordersToDo->front();
      _ordersToDo->pop_front();
      return (true);
    }
  (void)order;
  return (false);
}

void		Gui::printStatus(std::deque<std::string>* status)
{
  ScopedLock	lock(_guiMutex);

  while (!status->empty())
    {
      _ordersFinished->push_back(status->front());
      status->pop_front();
    }
}

bool		Gui::isFinished() const
{
  return (_isFinished);
}
