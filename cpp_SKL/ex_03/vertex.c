/*
** vertex.c for cpp_SKL in /home/girard_r/rendu/cpp_SKL/ex_02
** 
** Made by Aurélien GIRARDEAU
** Login   <girard_r@epitech.net>
** 
** Started on  Sat Jan 10 12:17:16 2015 Aurélien GIRARDEAU
** Last update Sat Jan 10 17:07:55 2015 Aurélien GIRARDEAU
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
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
  (void) self;
  if (((VertexClass *)self)->to_str != NULL)
    free(((VertexClass *)self)->to_str);
}

static const char *Vertex_str(Object *self) {
  unsigned int	size;

  if (((VertexClass *)self)->to_str != NULL)
    free(((VertexClass *)self)->to_str);
  size = sizeof(char) * (strlen(((VertexClass *)self)->base.__name__) + int_to_str(((VertexClass *)self)->x) + int_to_str(((VertexClass *)self)->y) + int_to_str(((VertexClass *)self)->z) + 10);
  if ((((VertexClass *)self)->to_str = malloc(size)) == NULL)
    raise("Out of memory\n");
  snprintf(((VertexClass *)self)->to_str, size, "<%s (%d, %d, %d)>", ((VertexClass *)self)->base.__name__, ((VertexClass *)self)->x, ((VertexClass *)self)->y, ((VertexClass *)self)->z);
  return (((VertexClass *)self)->to_str);
}

static Object  *Vertex_add(const Object *first, const Object *second) {
  int		newX;
  int		newY;
  int		newZ;

  newX = ((VertexClass *)first)->x + ((VertexClass *)second)->x;
  newY = ((VertexClass *)first)->y + ((VertexClass *)second)->y;
  newZ = ((VertexClass *)first)->z + ((VertexClass *)second)->z;

  return ((Object *)new(Vertex, newX, newY, newZ));
}

static Object  *Vertex_sub(const Object *first, const Object *second) {
  int		newX;
  int		newY;
  int		newZ;

  newX = ((VertexClass *)first)->x - ((VertexClass *)second)->x;
  newY = ((VertexClass *)first)->y - ((VertexClass *)second)->y;
  newZ = ((VertexClass *)first)->z - ((VertexClass *)second)->z;

  return ((Object *)new(Vertex, newX, newY, newZ));
}

static VertexClass _description = {
  { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_str, &Vertex_add, &Vertex_sub },
  0, 0, 0, NULL
};

Class* Vertex = (Class*) &_description;
