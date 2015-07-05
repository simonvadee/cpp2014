
//
// routine.cpp for plazza in /home/girard_r/Documents/plazza/tp
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Thu Apr 16 19:12:30 2015 Aurélien GIRARDEAU
// Last update Thu Apr 16 19:25:37 2015 Aurélien GIRARDEAU
//

#include "AObj.hh"

void*		start_routine(void *arg)
{
  AObj		*obj = reinterpret_cast<AObj*>(arg);

  obj->start();
  return (NULL);
}
