/*
** point.c for cpp_SKL in /home/girard_r/rendu/cpp_SKL/ex_02
** 
** Made by Aurélien GIRARDEAU
** Login   <girard_r@epitech.net>
** 
** Started on  Sat Jan 10 12:17:08 2015 Aurélien GIRARDEAU
** Last update Sat Jan 10 17:32:21 2015 Aurélien GIRARDEAU
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "raise.h"
#include "object.h"
#include "point.h"
#include "new.h"

typedef struct
{
  Class base;
  int x, y;
  char *to_str;
} PointClass;

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

static void Point_ctor(Object* self, va_list *args)
{
  memcpy(self, Point, sizeof(Class));
  ((PointClass *)self)->x = va_arg(args, int);
  ((PointClass *)self)->y = va_arg(args, int);
  ((PointClass *)self)->to_str = NULL;
}

static void Point_dtor(Object* self)
{
  if (((PointClass *)self)->to_str != NULL)
    free(((PointClass *)self)->to_str);
}

static char const* Point_str(Object *self) {
  unsigned int	size;

  if (((PointClass *)self)->to_str != NULL)
    free(((PointClass *)self)->to_str);
  size = sizeof(char) * (strlen(((PointClass *)self)->base.__name__) + int_to_str(((PointClass *)self)->x) + int_to_str(((PointClass *)self)->y) + 8);
  if ((((PointClass *)self)->to_str = malloc(size)) == NULL)
    raise("Out of memory\n");
  snprintf(((PointClass *)self)->to_str, size, "<%s (%d, %d)>", ((PointClass *)self)->base.__name__, ((PointClass *)self)->x, ((PointClass *)self)->y);
  return (((PointClass *)self)->to_str);
}

static Object *Point_add(const Object *first, const Object *second)
{
  return (new(Point, ((PointClass*)second)->x + ((PointClass*)first)->x, ((PointClass*)second)->y + ((PointClass*)first)->y));
}

static Object *Point_sub(const Object *first, const Object *second)
{
  return (new(Point, ((PointClass*)first)->x - ((PointClass*)second)->x, ((PointClass*)first)->y - ((PointClass*)second)->y));
}

static PointClass _description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_str, &Point_add, &Point_sub },
  0, 0, NULL
};

Class* Point = (Class*) &_description;
