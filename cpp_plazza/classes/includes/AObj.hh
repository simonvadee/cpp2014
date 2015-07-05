//
// AObj.hh for plazza in /home/girard_r/Documents/plazza/tp
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Thu Apr 16 18:26:29 2015 Aurélien GIRARDEAU
// Last update Wed Apr 22 13:15:13 2015 Aurélien GIRARDEAU
//

#ifndef AOBJ_H_
# define AOBJ_H_

# include "Mutex.hh"

class		AObj
{
public :
  AObj() {}
  virtual ~AObj() {}
  virtual void		start() = 0;
};

#endif
