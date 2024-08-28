#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>

typedef struct {
  int row;
  int col;
  int x;
  int y;  
  //Color color;
  struct node *neighbors[4];
} node;

typedef struct pair pair;
struct pair {
  node *node;  // Pointer to a node
  size_t priority;
};


void swap(pair queue[], size_t i, size_t j);

node* dequeue(pair queue[], size_t size);

void bubble_up(pair queue[], size_t curr);

void enqueue(pair queue[], node *node, size_t priority, size_t size);

void decrease_key(pair queue[], node *node, size_t priority, size_t size);


#endif /* UTILS_H */
