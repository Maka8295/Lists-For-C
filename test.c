
#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int main(void)
{
  node *list = NULL;
  list = append(5, list, "1", "2", "3", "4", "5");
  printf("%s", indexVal(list, 2));
}
