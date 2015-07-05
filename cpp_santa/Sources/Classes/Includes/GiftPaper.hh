//
// GiftPaper.hh for giftpaper in /home/tea_a/Work/Rendu/cpp_santa/Sources/Classes/Includes
//
// Made by Alexandre Tea
// Login   <tea_a@epitech.net>
//
// Started on  Sat Jan 17 22:17:14 2015 Alexandre Tea
// Last update Sun Jan 18 06:41:59 2015 Titouan Theophile
//

#ifndef __GIFTPAPER_HH__
# define __GIFTPAPER_HH__

#include "Wrap.hh"

class GiftPaper : public Wrap
{

public:

  GiftPaper();
  GiftPaper(GiftPaper&);
  virtual ~GiftPaper();

  virtual objectType		getType() const;
  virtual GiftPaper		*clone() const;
  virtual bool			wrapMeThat(Object *);
  virtual Object*		openMe();
  virtual bool			getIsOpen() const;
  virtual void			isTaken() const;
  virtual bool			closeMe();
  GiftPaper&			operator=(GiftPaper const&);

private:
  bool				_isOpen;
};


#endif /* !__GIFTPAPER_HH__ */
