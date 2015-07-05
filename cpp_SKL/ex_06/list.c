/*
** list.c for list in /home/girard_r/rendu/cpp_SKL/ex_06
** 
** Made by Aurélien GIRARDEAU
** Login   <girard_r@epitech.net>
** 
** Started on  Sat Jan 10 21:14:38 2015 Aurélien GIRARDEAU
** Last update Sun Jan 11 07:05:32 2015 Aurélien GIRARDEAU
*/

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "raise.h"
#include "list.h"
#include "new.h"

typedef struct	s_list
{
  Class *value;
  struct s_list *next;
}		t_list;

typedef struct
{
  Container base;
  size_t _size;
  Class *type;
  t_list *_list;
  Iterator *begin;
  Iterator *end;
} ListClass;

typedef struct {
  Iterator base;
  t_list *current;
  ListClass *_list;
  size_t _idx;
} ListIteratorClass;

static Class *ListIterator;

void ListIterator_ctor(ListIteratorClass* self, va_list* args)
{
  memcpy(self, ListIterator, sizeof(Iterator));
  self->_list = va_arg(*args, ListClass*);
  self->_idx = va_arg(*args, size_t);
  self->current = self->_list->_list;
}

bool ListIterator_eq(ListIteratorClass* self, ListIteratorClass* other)
{
  if (self->_idx == other->_idx)
    return true;
  return false;
}

bool ListIterator_gt(ListIteratorClass* self, ListIteratorClass* other)
{
  if (self->_idx > other->_idx)
    return true;
  return false;
}

bool ListIterator_lt(ListIteratorClass* self, ListIteratorClass* other)
{
  if (self->_idx < other->_idx)
    return true;
  return false;
}

void ListIterator_incr(ListIteratorClass* self)
{
  if (self->_idx < self->_list->_size - 1) {
    self->_idx += 1;
    self->current = self->current->next;
  }
  else {
    raise("Out of list");
  }
}

Object*	ListIterator_getval(ListIteratorClass* self)
{
  return (self->current->value);
}

void	ListIterator_setval(ListIteratorClass* self, ...)
{
  t_list	*list = self->current;
  va_list	args;

  va_start(args, self);
  if (list->value)
    delete(list->value);
  list->value = va_new(self->_list->type, &args);
  va_end(args);
}

static ListIteratorClass ListIteratorDescr = {
    {
        {
            sizeof(ListIteratorClass), "ListIterator",
            (ctor_t) &ListIterator_ctor,
            NULL, /* dtor */
            NULL, /* str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            (binary_comparator_t) &ListIterator_eq,
            (binary_comparator_t) &ListIterator_gt,
            (binary_comparator_t) &ListIterator_lt,
        },
        (incr_t) &ListIterator_incr,
        (getval_t) &ListIterator_getval,
        (setval_t) &ListIterator_setval,
    },
    NULL,
    NULL,
    0
};

static Class* ListIterator = (Class*) &ListIteratorDescr;

void List_ctor(ListClass* self, va_list* args)
{
  unsigned int	i = 0;
  va_list	save;
  t_list	*tmp = NULL;
  t_list	*begin = NULL;

  self->_list = NULL;
  memcpy(self, List, sizeof(Container));
  self->_size = va_arg(*args, size_t);
  self->type = va_arg(*args, Class *);
  while (i < self->_size)
    {
      if ((tmp = malloc(sizeof(*(self->_list)))) == NULL)
	raise("Out of Memory");
      va_copy(save, *args);
      tmp->value = va_new(self->type, &save);
      tmp->next = NULL;
      if (self->_list == NULL)
	{
	  self->_list = tmp;
	  begin = tmp;
	}
      else
	{
	  while (self->_list->next != NULL)
	    self->_list = self->_list->next;
	  self->_list->next = tmp;
	}
      i += 1;
    }
  self->_list = begin;
  self->begin = NULL;
  self->end = NULL;
}

void		List_dtor(ListClass* self)
{
  t_list	*tmp;
  t_list	*save;

  tmp = self->_list;
  while (tmp != NULL) {
    save = tmp;
    delete(tmp->value);
    tmp = tmp->next;
    free(save);
  }
  if (self->begin)
    free(self->begin);
  if (self->end)
    free(self->end);
}

size_t List_len(ListClass* self)
{
  return (self->_size);
}

Iterator* List_begin(ListClass* self)
{
  if (self->begin)
    free(self->begin);
  self->begin = new(ListIterator, self, 0);
  return (self->begin);
}

Iterator* List_end(ListClass* self)
{
  t_list *tmp = self->_list;

  while (tmp && tmp->next)
    tmp = tmp->next;
  if (self->end)
    free(self->end);
  self->end = new(ListIterator, self, self->_size - 1, tmp);
  return (self->end);
}

Object* List_getitem(ListClass* self, ...)
{
  t_list *list = self->_list;
  size_t pos;
  va_list args;
  unsigned int	i = 0;
  
  va_start(args, self);
  pos = va_arg(args, size_t);
  va_end(args);
  while (i != pos)
    {
      list = list->next;
      ++i;
    }
  return (list->value);
}

void List_setitem(ListClass* self, ...)
{
  t_list *list = self->_list;
  size_t pos;
  va_list args;
  unsigned int	i = 0;

  va_start(args, self);
  if ((pos = va_arg(args, size_t)) > (self->_size - 1))
    raise("Setitem : out of array");
  printf("%d\n", (int)pos);
  while (list && list->next && i != pos)
    {
      list = list->next;
      ++i;
    }
  if (list->value)
    delete(list->value);
  list->value = va_new(self->type, &args);
  va_end(args);
}

static ListClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(ListClass), "List",
            (ctor_t) &List_ctor, (dtor_t) &List_dtor,
            NULL, /*str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &List_len,
        (iter_t) &List_begin,
        (iter_t) &List_end,
        (getitem_t) &List_getitem,
        (setitem_t) &List_setitem,
    },
    0, NULL, NULL, NULL, NULL
};

Class* List = (Class*) &_descr;
