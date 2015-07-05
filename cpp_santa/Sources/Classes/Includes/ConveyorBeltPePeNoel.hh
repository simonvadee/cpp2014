//
// ConveyorBeltPePeNoel.hh for ConveyorBeltPePeNoel in /home/tea_a/Work/Rendu/cpp_santa/Sources/Classes/Includes
//
// Made by Alexandre Tea
// Login   <tea_a@epitech.net>
//
// Started on  Sat Jan 17 14:48:05 2015 Alexandre Tea
// Last update Sun Jan 18 07:40:01 2015 Alexandre Tea
//

#ifndef __CONVEYORBELTPEPENOEL_HH__
# define __CONVEYORBELTPEPENOEL_HH__

# include <deque>
# include "IConveyorBelt.hh"

class ConveyorBeltPePeNoel : public IConveyorBelt
{

public:

  ConveyorBeltPePeNoel(std::deque<Object*> _queue);
  ConveyorBeltPePeNoel(ConveyorBeltPePeNoel const& other);

  virtual ~ConveyorBeltPePeNoel();

  ConveyorBeltPePeNoel&		operator=(ConveyorBeltPePeNoel const& other);

  virtual bool			inPressed();
  virtual bool			outPressed();
  virtual Object*		getObject() const;
  virtual Object*		objectTaken();
  virtual bool			setObject(Object*);
  virtual bool			isEmpty() const;

private:

  bool			_isEmpty;
  Object*		_current;
  std::deque<Object*>	_queue;

};

#endif /* !__CONVEYORBELTPEPENOEL_HH__ */
