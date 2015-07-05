/*
** char.c for charclass in /home/tea_a/Work/Rendu/cpp_SKL/ex_04
**
** Made by Alexandre Tea
** Login   <tea_a@epitech.net>
**
** Started on  Sat Jan 10 11:31:54 2015 Alexandre Tea
** Last update Sun Jan 11 03:37:49 2015 Titouan Theophile
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "object.h"
#include "new.h"
#include "char.h"
#include "raise.h"

typedef struct
{
  Class		base;
  char		value;
  char		*to_str;
} CharClass;

static void		Char_ctor(Object* self, va_list* args)
{
  memcpy(self, Char, sizeof(Class));
  ((CharClass*) self)->value = va_arg(*args, int);
  ((CharClass*) self)->to_str = NULL;
}

static void		Char_dtor(Object* self)
{
  if (((CharClass*) self)->to_str != NULL)
    free(((CharClass*) self)->to_str);
}

static char const*	Char_str(Object* self)
{
  if (((CharClass*) self)->to_str != NULL)
    free(((CharClass*) self)->to_str);
  if ((((CharClass*) self)->to_str = malloc(sizeof(*((CharClass*) self)->to_str) * 3)) == NULL)
    raise("Out of memory");
  sprintf(((CharClass*) self)->to_str, "%c", ((CharClass*) self)->value);
  return (((CharClass*) self)->to_str);
}

static Object*		Char_add(const Object* self, const Object* other)
{
  return (new(Char, ((CharClass*) self)->value + ((CharClass*) other)->value));
}

static Object*		Char_sub(const Object* self, const Object* other)
{
  return (new(Char, ((CharClass*) self)->value - ((CharClass*) other)->value));
}

static Object*		Char_mul(const Object* self, const Object* other)
{
  return (new(Char, ((CharClass*) self)->value * ((CharClass*) other)->value));
}

static Object*		Char_div(const Object* self, const Object* other)
{
  if (((CharClass*) other)->value == 0)
    raise("Division by zero");
  return (new(Char, ((CharClass*) self)->value / ((CharClass*) other)->value));
}

static bool		Char_eq(const Object* self, const Object* other)
{
  if (((CharClass*) self)->value == ((CharClass*) other)->value)
    return (true);
  return (false);
}

static bool		Char_gt(const Object* self, const Object* other)
{
  if (((CharClass*) self)->value > ((CharClass*) other)->value)
    return (true);
  return (false);
}

static bool		Char_lt(const Object* self, const Object* other)
{
  if (((CharClass*) self)->value < ((CharClass*) other)->value)
    return (true);
  return (false);
}

static CharClass _description = {
  { sizeof(CharClass), "Char",
    &Char_ctor, &Char_dtor, &Char_str, &Char_add, &Char_sub, &Char_mul, &Char_div, &Char_eq, &Char_gt, &Char_lt },
  0, NULL
};

Class* Char = (Class*) &_description;
