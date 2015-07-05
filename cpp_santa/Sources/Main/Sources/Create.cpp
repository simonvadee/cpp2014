/**
 * vadee_s
 */

#include <deque>
#include "TablePePeNoel.hh"
#include "ConveyorBeltPePeNoel.hh"

TablePePeNoel*			createTable()
{
  TablePePeNoel*		ret = new TablePePeNoel;

  return ret;
}

ConveyorBeltPePeNoel*		createConveyor(std::deque<Object*> queue)
{
  ConveyorBeltPePeNoel*		ret = new ConveyorBeltPePeNoel(queue);

  return ret;
}
