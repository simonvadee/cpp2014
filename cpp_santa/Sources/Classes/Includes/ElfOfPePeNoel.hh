//
// ElfOfPePeNoel.hh for ElfOfPePeNoel in /home/girard_r/rendu/cpp_santa/Srcs/Includes
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Sat Jan 17 14:52:56 2015 Aurélien GIRARDEAU
// Last update Sun Jan 18 08:45:02 2015 Alexandre Tea
//

#ifndef __ELFOFPEPENOEL_HH__
# define __ELFOFPEPENOEL_HH__

# include "IElf.hh"

class			ElfOfPePeNoel : public IElf
{
  Object*		_carryObject;

public:
  ElfOfPePeNoel();
  ElfOfPePeNoel(ElfOfPePeNoel const& other);
  virtual			~ElfOfPePeNoel();
  ElfOfPePeNoel&		operator=(ElfOfPePeNoel const& other);
  virtual bool			openWrap(Object& wrap);
  virtual bool			closeBox(Object& box);
  virtual bool			wraps(Object& wrap, Object *obj);
  bool				takeObject(ITable& table, size_t idx);
  bool				takeObject(IConveyorBelt& conveyor);
  bool				putObject(ITable& table);
  bool				putObject(IConveyorBelt& conveyor);
  virtual bool			pressIn(IConveyorBelt& conveyor);
  virtual bool			pressOut(IConveyorBelt& conveyor);
  virtual char* const*		look(ITable& table) const;
  virtual char* const*		look(IConveyorBelt& conveyor) const;
  virtual void			run(ITable& table, IConveyorBelt& conveyor);
  virtual int			seekInTable(ITable &table, objectType type) const;

  bool				buildGift(ITable& table, IConveyorBelt& conveyor);
  bool				fillTable(ITable& table, IConveyorBelt& conveyor);
};

#endif
