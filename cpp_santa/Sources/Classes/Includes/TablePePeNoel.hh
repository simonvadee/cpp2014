/**
 * theoph_t tea_a girard_r vadee_s
 */

#ifndef __TABLEPEPENOEL_H__
# define __TABLEPEPENOEL_H__

#include <vector>
#include "ITable.hh"

class		TablePePeNoel : public ITable
{
public:

  TablePePeNoel();
  TablePePeNoel(TablePePeNoel const& other);

  virtual ~TablePePeNoel();

  TablePePeNoel&			operator=(TablePePeNoel const& other);

  virtual bool				addObject(Object* elem);
  virtual Object*			getObject(size_t index) const;
  virtual Object*			objectTaken(size_t index);
  virtual char* const*			getObjectTitles();
  virtual std::vector<Object*>		getVector() const;

protected:
  std::vector<Object*>	_objects;
};

#endif /* _TABLEPEPENOEL_H__ */
