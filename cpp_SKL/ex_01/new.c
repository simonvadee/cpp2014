/*
** new.c for ex01 in /home/theoph_t/rendu/cpp_SKL/ex_01
**
** Made by Titouan Theophile
** Login   <theoph_t@epitech.net>
**
** Started on  Sat Jan 10 11:05:37 2015 Titouan Theophile
** Last update Sun Jan 11 01:07:15 2015 Alexandre Tea
*/

#include <stdlib.h>
#include "new.h"
#include "raise.h"

void* new(Class* class)
{
  Object *new;

  if ((new = malloc(class->__size__)) == NULL)
    raise("Malloc failed");
  class->__init__(new);
  return (new);
}


void delete(Object* ptr)
{
  if (ptr != NULL && ((Class *)ptr)->__del__)
    {
      ((Class *)ptr)->__del__(ptr);
      free (ptr);
    }
}
