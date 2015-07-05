//
// IElf.hh for IElf in /home/girard_r/rendu/cpp_santa/Srcs/Includes
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Sat Jan 17 13:42:47 2015 Aurélien GIRARDEAU
// Last update Sun Jan 18 08:44:13 2015 Alexandre Tea
//

#ifndef __IELF_HH__
# define __IELF_HH__

# include <string>
# include <vector>
# include "Object.hh"
# include "Toy.hh"
# include "Box.hh"
# include "Wrap.hh"
# include "ITable.hh"
# include "IConveyorBelt.hh"

# define	FULL	"Error: Elf: The elf already wear an Object"
# define	IS_EMPTY	"Error: Elf: hand is empty"

class		IElf
{
public:
  virtual ~IElf();
  /*
  ** Methodes Toy et Wrapp
  */
  virtual bool		wraps(Object& wrap, Object* obj) = 0;		//via wrapMeThat  de Wrap
  virtual bool		openWrap(Object& wrap) = 0;			//open Wrap => soit une Box, soit un Toy, soit Rien (NULL) : via openMe de Wrap, Wrap empty after this method
  virtual bool		closeBox(Object& box) = 0;				// close Box via closeMe de Box

  /*
  ** Methodes Table et Conveyor Belt
  */
  virtual bool		pressIn(IConveyorBelt& conveyor) = 0;		// get first elem on queue to conveyor => false if already elem on conveyor
  virtual bool		pressOut(IConveyorBelt& conveyor) = 0;		// send on conveyor to santa, true if gift either false
  virtual char* const*	look(ITable& table) const = 0;			// Return titles from table
  virtual char* const*	look(IConveyorBelt& conveyor) const = 0;		// Return titles from conveyor
  virtual void		run(ITable& table, IConveyorBelt& conveyor) = 0;
};

#endif
