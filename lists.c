// A rudimentry implimentation of Pythons lists in C. Made for practice.

#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

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


// returns length of list

int len(node *list)
{
  node *ptr = list;
  int count = 0;
  
  while (ptr != NULL)
  {
    count++;
    ptr = ptr->next;
  }
  return count;
}


// remove node from list that has str == input returns updated list
// if not found it returns list unmodified

node* strip(node *list, char *input)
{
  if (list == NULL)
  {
    return list;
  }

  // if head of list is match
  if (strcmp(list->str, input) == 0)
  {
    node *tmp = list;
    list = list->next;
    free(tmp);
    return list;
  }

  node *prev = list;
  node *ptr = list->next;

  while(ptr != NULL)
  {
    if (strcmp(ptr->str, input) == 0)
    {
      prev->next = ptr->next;
      free(ptr);
      return list;
    }
    prev = ptr;
    ptr = ptr->next;
  }

  return list;
}


// sort list by longest to shortest BUBBLE SORT

node* sortLong(node *list) 
{  
  if (list == NULL || list->next == NULL) 
  {
    return list; // List is empty or has only one element
  }

  bool swapped;
  node *head = list;
  node *end = NULL;

  do 
  {
    swapped = false;
    node *current = head;
    node *prev = NULL;

    while (current->next != end)
    {
      if (strlen(current->str) < strlen(current->next->str))
      {
        // Swap nodes
        node *nextNode = current->next;
        if (prev)
        {
          prev->next = nextNode;
        } 
        else
        {
          head = nextNode;
        }
        current->next = nextNode->next;
        nextNode->next = current;

        swapped = true;
        prev = nextNode;
      } 
      else 
      {
        prev = current;
        current = current->next;
      }
    }
    end = current; // Update end to the last unsorted element
    
  } while (swapped);

    return head;
}


// sort list by shortest to longest BUBBLE SORT

node* sortShort(node *list) 
{  
  if (list == NULL || list->next == NULL) 
  {
    return list; // List is empty or has only one element
  }

  bool swapped;
  node *head = list;
  node *end = NULL;

  do 
  {
    swapped = false;
    node *current = head;
    node *prev = NULL;

    while (current->next != end)
    {
      if (strlen(current->str) > strlen(current->next->str))
      {
        // Swap nodes
        node *nextNode = current->next;
        if (prev)
        {
          prev->next = nextNode;
        } 
        else
        {
          head = nextNode;
        }
        current->next = nextNode->next;
        nextNode->next = current;

        swapped = true;
        prev = nextNode;
      } 
      else 
      {
        prev = current;
        current = current->next;
      }
    }
    end = current; // Update end to the last unsorted element
    
  } while (swapped);

    return head;
}
