//
// TableRand.hh for TableRand in /home/tea_a/Work/Rendu/cpp_santa/Sources/Classes/Sources
//
// Made by Alexandre Tea
// Login   <tea_a@epitech.net>
//
// Started on  Sat Jan 17 23:35:45 2015 Alexandre Tea
// Last update Sun Jan 18 02:18:39 2015 Alexandre Tea
//

#ifndef __TABLERAND_HH__
# define __TABLERAND_HH__

# include "TablePePeNoel.hh"
# include "MagicTypeSource.hh"

class TableRand : public TablePePeNoel
{
private:
  MagicTypeSource	*_mts;

public:
  TableRand();
  TableRand(MagicTypeSource* mts);
  TableRand(TableRand const& t);
  ~TableRand();

public:
  TableRand&	operator=(TableRand const&);
};

#endif /* !__TABLERAND_HH__ */
