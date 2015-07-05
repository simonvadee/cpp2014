//
// IConveyorBelt.hh for IConveyor in /home/tea_a/Work/Rendu/cpp_santa/Sources/Classes/Includes
//
// Made by Alexandre Tea
// Login   <tea_a@epitech.net>
//
// Started on  Sat Jan 17 13:48:59 2015 Alexandre Tea
// Last update Sun Jan 18 04:37:57 2015 Alexandre Tea
//

#ifndef __ICONVEYORBELT_HH__
# define __ICONVEYORBELT_HH__

# include "Object.hh"

# define	EMPTY		"Conveyor is empty"
# define	NOT_EMPTY	"there is already an object in the conveyor you little stupid piece of shit"
# define	GIFT_OUT	"A gift is sent to Santa !"
# define	POPPED_IN	"just popped from the conveyor !"	/* a OBJECTNAME jsut popped from the conveyor */

class IConveyorBelt
{
public:
  virtual ~IConveyorBelt();
  virtual bool			inPressed() = 0;		/* get an element in, return false if not empty */
  virtual bool			outPressed() = 0;		/* get the current element out or return false if empty */
  virtual Object*		getObject() const = 0;		/* return current element or null if empty */
  virtual Object*		objectTaken() = 0;
  virtual bool			setObject(Object*) = 0;		/* put object in conveyor, return false if empty */
  virtual bool			isEmpty() const = 0;
};

#endif /* !__ICONVEYORBELT_HH__ */
