#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>

#define MAX 3000
typedef struct {
  int row;
  int col;
  int x;
  int y;
  int priority;
  //Color color;
  struct node *neighbors[4];
} node;

// Define PriorityQueue structure
typedef struct {
    node* items[MAX];
    int size;
} PriorityQueue;

void swap(node* pq[], int i, int j);
void heapifyUp(PriorityQueue* pq, int index);
void enqueue(PriorityQueue* pq, node* n);
void heapifyDown(PriorityQueue* pq, int index);
node* dequeue(PriorityQueue* pq);
node* peek(PriorityQueue* pq);

#endif /* UTILS_H */
