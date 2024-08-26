// A rudimentry implimentation of Pythons lists in C. Made for practice.

#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Reverse items in list and returns pointer to new list
node* reverse(node* list)
{
  node *prev = NULL;
  node *next = NULL;

  while (list != NULL)
  {
    next = list->next;
    list->next = prev;
    prev = list;
    list = next;
  }
  return prev;
}


// Return value at certain index of list NULL if out of bounds
char* indexVal(node *list, int index)
{
  node *ptr = list;
  int count = 0;
  
  while (ptr != NULL && count < index)
  {
    ptr = ptr->next;
    count++;
  }

  if (ptr == NULL)
  {
    return NULL;
  }

  return ptr->str;
}


// finds last node in a list, returns pointer to that node
node* lastNode(node *list)
{
  node *last = list;
  while (last != NULL && last->next != NULL)
  {
    last = last->next;
  }
  return last;
}


// appends values to list OR creates a new list. Returns pointer to new list
// int num is the number of arguments you are appending
node* append(int num, node *list, ...)
{
  va_list args;
  va_start(args, list);
  
  for (int i = 0; i < num; i++)
  {
    if (list == NULL)
    {
      node *n = malloc(sizeof(node));
      if (n == NULL)
      {
        return list;
      }
      n->next = NULL;

      n->str = va_arg(args, char*);
      list = n;
    }
    else
    { 
      node *n = malloc(sizeof(node));
      if (n == NULL)
      {
        return list;
      }
      n->next = NULL;

      n->str = va_arg(args, char*);

      node *last = lastNode(list);
      last->next = n;
    }

  }
  va_end(args);
  return list;
}




