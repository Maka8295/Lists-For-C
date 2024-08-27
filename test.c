
#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int main(void)
{
  node *list = NULL;
  list = append(5, list, "1", "55555", "333", "4444", "22");

  list = sortShort(list);
  
  node *ptr = list;
  while(ptr != NULL)
  {
    printf("%s, ", ptr->str);
    ptr = ptr->next;
  }
  printf("\n");




  // clean up
  while(list != NULL)
  {
    node *ptr = list;
    list = list->next;
    free(ptr);
  }

}
