/*
** vertex.c for cpp_SKL in /home/girard_r/rendu/cpp_SKL/ex_02
**
** Made by Aurélien GIRARDEAU
** Login   <girard_r@epitech.net>
**
** Started on  Sat Jan 10 12:17:16 2015 Aurélien GIRARDEAU
** Last update Sun Jan 11 07:11:14 2015 Aurélien GIRARDEAU
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "new.h"
#include "raise.h"
#include "object.h"
#include "vertex.h"

typedef struct
{
  Class base;
  int x, y, z;
  char *to_str;
} VertexClass;

static int int_to_str(int nb) {
  unsigned int count = 0;

  if (nb == 0)
    return 1;
  if (nb < 0)
    {
      count++;
      nb *= -1;
    }
  while (nb > 0)
    {
      nb = nb/10;
      count++;
    }
  return (count);
}

static void Vertex_ctor(Object *self, va_list *args)
{
  memcpy(self, Vertex, sizeof(Class));
  ((VertexClass *)self)->x = va_arg(args, int);
  ((VertexClass *)self)->y = va_arg(args, int);
  ((VertexClass *)self)->z = va_arg(args, int);
  ((VertexClass *)self)->to_str = NULL;
}

static void Vertex_dtor(Object* self)
{
  if (((VertexClass *)self)->to_str != NULL)
    free(((VertexClass *)self)->to_str);
}

static char const *Vertex_str(Object *self) {
  unsigned int	size;

  if (((VertexClass *)self)->to_str != NULL)
    {
      free(((VertexClass *)self)->to_str);
    }
  size = sizeof(char) * (strlen(((VertexClass *)self)->base.__name__) + int_to_str(((VertexClass *)self)->x) + int_to_str(((VertexClass *)self)->y) + int_to_str(((VertexClass *)self)->z) + 10);
  if ((((VertexClass *)self)->to_str = malloc(size)) == NULL)
    raise("Out of memory\n");
  snprintf(((VertexClass *)self)->to_str, size, "<%s (%d, %d, %d)>", ((VertexClass *)self)->base.__name__, ((VertexClass *)self)->x, ((VertexClass *)self)->y, ((VertexClass *)self)->z);
  return (((VertexClass *)self)->to_str);
}

static VertexClass _description = {
  { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_str},
  0, 0, 0, NULL
};

Class* Vertex = (Class*) &_description;
