/*
** ex_06.c for ex06 in /home/girard_r/rendu/cpp_SKL/ex_06
** 
** Made by Aurélien GIRARDEAU
** Login   <girard_r@epitech.net>
** 
** Started on  Sun Jan 11 06:36:54 2015 Aurélien GIRARDEAU
** Last update Sun Jan 11 07:07:32 2015 Aurélien GIRARDEAU
*/

#include <stdio.h>
#include <assert.h>

#include "list.h"
#include "int.h"
#include "new.h"

int main()
{
  Object*      array = new(List, 10, Int, 42);
  unsigned int index = 4;
  Object*      it = begin(array);
  Object*      it_end = end(array);
  Object*      tmp;

  printf("array size: %zu\n", len(array));
  setitem(array, 1, 6);
  setitem(array, 2, 7);
  setitem(array, 3, 8);
  while (gt(it, it_end) == 0 && index < len(array))
    {
      setitem(array, index, 5);
      printf("tab[%d] = %s\n", (int) index, str(getval(it)));
      incr(it);
      index++;
    }
  tmp = getitem(array, 0);
  setval(begin(array), tmp);
  printf("\ntab[0] = %s\n", str(getval(begin(array))));
  if (gt(getitem(array, 0), getitem(array, 1)))
    printf("GREATER\n");
  else
    printf("lower\n");
  if (lt(getitem(array, 2), getitem(array, 3)))
    printf("Lower\n");
  else
    printf("GREATER\n");
  if (eq(getitem(array, 8), getitem(array, 9)))
    printf("Equal\n");
  else
    printf("Not Equal\n");
  delete(array);
  return 0;
}

/* int	main() */
/* { */
/*   Object*      array = new(List, 10, Int, 42); */
/*   Object*      it = begin(array); */
/*   Object*      it_end = end(array); */

/*   printf("%s\n", str(getitem(array, 3))); */
/*   printf("%s\n\n", str(getitem(array, 3))); */

/*   int	i = 0; */
  
/*   while (lt(it, it_end) == true) */
/*     { */
/*       setitem(array, i, i); */
/*       ++i; */
/*       printf("%s\n", str(getval(it))); */
/*       incr(it); */
/*     } */

/*   delete(it); */
/*   delete(it_end); */
/*   delete(array); */
/*   return (0); */
/* } */
