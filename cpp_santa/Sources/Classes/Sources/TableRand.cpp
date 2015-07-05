//
// TableRand.cpp for tablerand in /home/tea_a/Work/Rendu/cpp_santa/Sources/Classes/Sources
//
// Made by Alexandre Tea
// Login   <tea_a@epitech.net>
//
// Started on  Sat Jan 17 23:39:40 2015 Alexandre Tea
// Last update Sun Jan 18 06:13:48 2015 Alexandre Tea
//

#include <cstdlib>
#include "TableRand.hh"

TableRand::TableRand() : _mts(new MagicTypeSource())
{
}

TableRand::TableRand(MagicTypeSource* mts) : _mts(new MagicTypeSource(*mts))
{
  int	i = 0;

  while (i < 10)
    {
      _objects.push_back(mts->generateObject(random() % NB_TYPES));
      ++i;
    }
}

TableRand::TableRand(TableRand const& t) : TablePePeNoel(), _mts(new MagicTypeSource(*t._mts))
{
}

TableRand::~TableRand()
{
  if (_mts != NULL)
    delete (_mts);
}


TableRand&	TableRand::operator=(TableRand const& t)
{
  if (_mts != NULL)
    delete (_mts);
  _mts = new MagicTypeSource(*t._mts);

  return (*this);
}
