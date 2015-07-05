/**
 * theoph_t tea_a girard_r vadee_s
 */

#ifndef __ITABLE_HH__
# define __ITABLE_HH__

# include <iostream>
# include <vector>
# include "Object.hh"

# define BROKEN_TABLE "The table shakes... *CRAAAAAACK*"
# define WRONG_INDEX "Error : wrong index"

class ITable
{
public:
  virtual				~ITable();
  virtual bool				addObject(Object* elem) = 0;	/* add object to the table, return false if full*/
  virtual Object*			getObject(size_t index) const = 0 ;	/* return the object at the index[index], return NULL if the index is wrong */
  virtual Object*			objectTaken(size_t index) = 0;	/* return the elem indicated by [index] and delete it from the array*/
  virtual char* const*			getObjectTitles()  = 0; /* return a bi-dimensional array of char containing the type of each Object on the Table*/
  virtual std::vector<Object*>		getVector() const = 0;
};

#endif /* ! __ITABLE_HH__ */
