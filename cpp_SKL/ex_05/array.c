/*
** array.c for ex5 in /home/theoph_t/rendu/cpp_SKL/ex_05
**
** Made by Titouan Theophile
** Login   <theoph_t@epitech.net>
**
** Started on  Sat Jan 10 23:26:29 2015 Titouan Theophile
** Last update Sun Jan 11 06:42:54 2015 Alexandre Tea
*/

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "raise.h"
#include "array.h"
#include "new.h"

typedef struct
{
  Container	base;
  Class*	_type;
  size_t	_size;
  Object**	_tab;
  Iterator	*begin;
  Iterator	*end;
} ArrayClass;

typedef struct {
    Iterator	base;
    ArrayClass*	_array;
    size_t	_idx;
} ArrayIteratorClass;

static Class* ArrayIterator;

void		ArrayIterator_ctor(ArrayIteratorClass* self, va_list* args)
{
  memcpy(self, ArrayIterator, sizeof(Iterator));
  self->_array = va_arg(*args, ArrayClass*);
  self->_idx = va_arg(*args, size_t);
}

bool		ArrayIterator_eq(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self->_idx == other->_idx)
    return (true);
  return (false);
}

bool		ArrayIterator_gt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self->_idx > other->_idx)
    return (true);
  return (false);
}

bool		ArrayIterator_lt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self->_idx < other->_idx)
    return (true);
  return (false);
}

void		ArrayIterator_incr(ArrayIteratorClass* self)
{
  if (self->_idx >= self->_array->_size - 1)
    raise("Can't increment, iterator is at the end of array");
  self->_idx += 1;
}

Object*		ArrayIterator_getval(ArrayIteratorClass* self)
{
  return (self->_array->_tab[self->_idx]);
}

void		ArrayIterator_setval(ArrayIteratorClass* self, ...)
{
  va_list	ap;

  if (self->_array->_tab[self->_idx] != NULL)
    delete(self->_array->_tab[self->_idx]);

  va_start(ap, self);
  self->_array->_tab[self->_idx] = va_new(self->_array->_type, &ap);
  va_end(ap);
}

static ArrayIteratorClass ArrayIteratorDescr = {
    {
        {
            sizeof(ArrayIteratorClass), "ArrayIterator",
            (ctor_t) &ArrayIterator_ctor,
            NULL, /* dtor */
            NULL, /* str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            (binary_comparator_t) &ArrayIterator_eq,
            (binary_comparator_t) &ArrayIterator_gt,
            (binary_comparator_t) &ArrayIterator_lt,
        },
        (incr_t) &ArrayIterator_incr,
        (getval_t) &ArrayIterator_getval,
        (setval_t) &ArrayIterator_setval,
    },
    NULL,
    0
};

static Class* ArrayIterator = (Class*) &ArrayIteratorDescr;

void		Array_ctor(ArrayClass* self, va_list* args)
{
  int		size = va_arg(*args, int);
  int		i = 0;
  va_list	save;

  memcpy(self, Array, sizeof(Container));
  self->_type = va_arg(*args, Class*);
  if ((self->_tab = malloc(sizeof(self->_type) * (size))) == NULL)
    raise("Out of memory");
  while (i < size)
    {
      va_copy(save, *args);
      self->_tab[i] = va_new(self->_type, &save);
      i++;
    }
  self->_size = size;
  self->begin = NULL;
  self->end = NULL;
}

void		Array_dtor(ArrayClass* self)
{
  unsigned int	i;

  i = 0;
  while (i < len((Container *)self))
    {
      delete(self->_tab[i]);
      ++i;
    }
  if (self->begin != NULL)
    {
      delete(self->begin);
      self->begin = NULL;
    }
  if (self->end != NULL)
    {
      delete(self->end);
      self->end = NULL;
    }
  free(self->_tab);
}

size_t		Array_len(ArrayClass* self)
{
  return (self->_size);
}

Iterator*	Array_begin(ArrayClass* self)
{
  if (self->begin != NULL)
    delete(self->begin);

  return ((self->begin = new(ArrayIterator, self, 0)));
}

Iterator*	Array_end(ArrayClass* self)
{
  if (self->end != NULL)
    delete(self->end);

  return ((self->end = new(ArrayIterator, self, self->_size - 1)));
}

Object*		Array_getitem(ArrayClass* self, ...)
{
  va_list	ap;
  size_t	idx;

  va_start(ap, self);
  if ((idx = va_arg(ap, size_t)) > self->_size - 1)
    raise("Getitem: out of array");
  va_end(ap);
  return (self->_tab[idx]);
}


void		Array_setitem(ArrayClass* self, ...)
{
  va_list	ap;
  size_t	idx;

  va_start(ap, self);
  if ((idx = va_arg(ap, size_t)) > self->_size - 1)
    raise("Setitem: out of array");
  if (self != NULL && self->_tab[idx] != NULL)
    delete(self->_tab[idx]);
  self->_tab[idx] = va_new(self->_type, &ap);
  va_end(ap);
}

static ArrayClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(ArrayClass), "Array",
            (ctor_t) &Array_ctor, (dtor_t) &Array_dtor,
            NULL, /*str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &Array_len,
        (iter_t) &Array_begin,
        (iter_t) &Array_end,
        (getitem_t) &Array_getitem,
        (setitem_t) &Array_setitem,
    },
    NULL, 0, NULL, NULL, NULL
};

Class* Array = (Class*) &_descr;
