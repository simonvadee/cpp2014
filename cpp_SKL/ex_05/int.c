/*
** int.c for intclass in /home/tea_a/Work/Rendu/cpp_SKL/ex_04
**
** Made by Alexandre Tea
** Login   <tea_a@epitech.net>
**
** Started on  Sat Jan 10 11:31:54 2015 Alexandre Tea
** Last update Sun Jan 11 03:37:23 2015 Titouan Theophile
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "object.h"
#include "new.h"
#include "int.h"
#include "raise.h"

typedef struct
{
  Class		base;
  int		value;
  char		*to_str;
} IntClass;

static void		Int_ctor(Object* self, va_list* args)
{
  memcpy(self, Int, sizeof(Class));
  ((IntClass*) self)->value = va_arg(*args, int);
  printf("%d\n", ((IntClass*)self)->value);
  ((IntClass*) self)->to_str = NULL;
}

static void		Int_dtor(Object* self)
{
  if (((IntClass*) self)->to_str != NULL)
    free(((IntClass*) self)->to_str);
}

static int		getIntLength(int nb)
{
  int			length;

  length = 0;
  if (nb == 0)
    return (1);
  else if (nb < 0)
    {
      length++;
      nb *= -1;
    }
  while (nb > 0)
    {
      length++;
      nb = nb / 10;
    }
  return (length);
}

static char const*	Int_str(Object* self)
{
  if (((IntClass*) self)->to_str != NULL)
    free(((IntClass*) self)->to_str);
  if ((((IntClass*) self)->to_str =
       malloc(sizeof(*((IntClass*) self)->to_str) * (getIntLength(((IntClass*) self)->value) + 1))) == NULL)
    raise("Out of memory");
  sprintf(((IntClass*) self)->to_str , "%d", ((IntClass*) self)->value);
  return (((IntClass*) self)->to_str);
}

static Object*		Int_add(const Object* self, const Object* other)
{
  return (new(Int, ((IntClass*) self)->value + ((IntClass*) other)->value));
}

static Object*		Int_sub(const Object* self, const Object* other)
{
  return (new(Int, ((IntClass*) self)->value - ((IntClass*) other)->value));
}

static Object*		Int_mul(const Object* self, const Object* other)
{
  return (new(Int, ((IntClass*) self)->value * ((IntClass*) other)->value));
}

static Object*		Int_div(const Object* self, const Object* other)
{
  if (((IntClass*) other)->value == 0)
    raise("Division by zero");
  return (new(Int, ((IntClass*) self)->value / ((IntClass*) other)->value));
}

static bool		Int_eq(const Object* self, const Object* other)
{
  if (((IntClass*) self)->value == ((IntClass*) other)->value)
    return (true);
  return (false);
}

static bool		Int_gt(const Object* self, const Object* other)
{
  if (((IntClass*) self)->value > ((IntClass*) other)->value)
    return (true);
  return (false);
}

static bool		Int_lt(const Object* self, const Object* other)
{
  if (((IntClass*) self)->value < ((IntClass*) other)->value)
    return (true);
  return (false);
}

static IntClass _description = {
  { sizeof(IntClass), "Int",
    &Int_ctor, &Int_dtor, &Int_str, &Int_add, &Int_sub, &Int_mul, &Int_div, &Int_eq, &Int_gt, &Int_lt },
  0, NULL
};

Class* Int = (Class*) &_description;
