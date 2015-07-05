/*
** float.c for floatclass in /home/tea_a/Work/Rendu/cpp_SKL/ex_04
**
** Made by Alexandre Tea
** Login   <tea_a@epitech.net>
**
** Started on  Sat Jan 10 11:31:54 2015 Alexandre Tea
** Last update Sun Jan 11 03:37:37 2015 Titouan Theophile
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "object.h"
#include "new.h"
#include "float.h"
#include "raise.h"

typedef struct
{
  Class		base;
  float		value;
  char		*to_str;
} FloatClass;

static void		Float_ctor(Object* self, va_list* args)
{
  memcpy(self, Float, sizeof(Class));
  ((FloatClass*) self)->value = va_arg(*args, double);
  ((FloatClass*) self)->to_str = NULL;
}

static void		Float_dtor(Object* self)
{
  if (((FloatClass*) self)->to_str != NULL)
    free(((FloatClass*) self)->to_str);
}

static int              getIntLength(int nb)
{
  int                   length;

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

static int		getFloatLength(float nb, int precision)
{
  int			length;
  if (nb == 0)
    return (precision + 2);

  length = getIntLength((int) nb);
  if (nb < 0)
    length++;
  length += precision + 1;
  return (length);
}

static char const*	Float_str(Object* self)
{
  if (((FloatClass*) self)->to_str != NULL)
    free(((FloatClass*) self)->to_str);
  if ((((FloatClass*) self)->to_str =
       malloc(sizeof(*((FloatClass*) self)->to_str) * (getFloatLength(((FloatClass*) self)->value, 5) + 1))) == NULL)
    raise("Out of memory");
  sprintf(((FloatClass*) self)->to_str, "%.5f", ((FloatClass*) self)->value);
  return (((FloatClass*) self)->to_str);
}

static Object*		Float_add(const Object* self, const Object* other)
{
  return (new(Float, ((FloatClass*) self)->value + ((FloatClass*) other)->value));
}

static Object*		Float_sub(const Object* self, const Object* other)
{
  return (new(Float, ((FloatClass*) self)->value - ((FloatClass*) other)->value));
}

static Object*		Float_mul(const Object* self, const Object* other)
{
  return (new(Float, ((FloatClass*) self)->value * ((FloatClass*) other)->value));
}

static Object*		Float_div(const Object* self, const Object* other)
{
  if (((FloatClass*) other)->value == 0)
    raise("Division by zero");
  return (new(Float, ((FloatClass*) self)->value / ((FloatClass*) other)->value));
}

static bool		Float_eq(const Object* self, const Object* other)
{
  if (((FloatClass*) self)->value == ((FloatClass*) other)->value)
    return (true);
  return (false);
}

static bool		Float_gt(const Object* self, const Object* other)
{
  if (((FloatClass*) self)->value > ((FloatClass*) other)->value)
    return (true);
  return (false);
}

static bool		Float_lt(const Object* self, const Object* other)
{
  if (((FloatClass*) self)->value < ((FloatClass*) other)->value)
    return (true);
  return (false);
}

static FloatClass _description = {
  { sizeof(FloatClass), "Float",
    &Float_ctor, &Float_dtor, &Float_str, &Float_add, &Float_sub, &Float_mul, &Float_div, &Float_eq, &Float_gt, &Float_lt },
  0, NULL
};

Class* Float = (Class*) &_description;
