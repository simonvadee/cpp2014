//
// GiftPaper.cpp for Santa in /home/theoph_t/test
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sat Jan 17 15:58:04 2015 Titouan Theophile
// Last update Sun Jan 18 06:41:29 2015 Titouan Theophile
//

#include "GiftPaper.hh"

GiftPaper::GiftPaper() : Wrap((std::string const &)"GiftPaper"), _isOpen(true)
{

}

GiftPaper::GiftPaper(GiftPaper& copy) : Wrap(copy)
{

}

objectType	GiftPaper::getType() const
{
  return GIFTPAPER;
}

GiftPaper     *GiftPaper::clone() const
{
  return (new GiftPaper());
}

bool GiftPaper::wrapMeThat(Object *box)
{
  if (_stock != NULL)
    return false;
  _stock = box;
  _isEmpty = false;
  return true;
}

Object*               GiftPaper::openMe()
{
  _isEmpty = true;
  return _stock;
}

bool                  GiftPaper::closeMe()
{
  return false;
}


bool                  GiftPaper::getIsOpen() const
{
  return true;
}

void	GiftPaper::isTaken() const
{
  std::cout << "Look a my shiny skin" << std::endl;
}

GiftPaper::~GiftPaper()
{
  std::cout << "Someone burnt the gift paper..." << std::endl;
}


GiftPaper&          GiftPaper::operator=(GiftPaper const& copy)
{
  _title = copy._title;
  _isEmpty = copy._isEmpty;
  _stock = copy._stock->clone();
  return *this;
}
