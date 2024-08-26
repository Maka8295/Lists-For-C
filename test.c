
#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int main(void)
{
  node *list = NULL;
  list = append(4, list, "1", "2", "3", "4");
  printf("%s\n", indexVal(list, 2));

  node *last = lastNode(list);
  printf("%s\n", last->str);
  
  list = reverse(list);
  node *ptr = list;
  while(ptr != NULL)
  {
    printf("%s, ", ptr->str);
    ptr = ptr->next;
  }
  printf("\n");

  printf("%i\n", len(list));

  list = strip(list, "1");
  printf("%s\n",lastNode(list)->str);

  // clean up
  while(list != NULL)
  {
    ptr = list;
    list = list->next;
    free(ptr);
  }
}
