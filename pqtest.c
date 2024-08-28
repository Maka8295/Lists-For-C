#include "pq.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

//As mentioned by Anthony Blake, a priority queue is meant to be implemented with a heap tree, which can
//be represented as an array. In such an array, tree nodes are placed level-by-level. The index of the
//parent of node at index i can then be calculated as (i - 1) / 2 and the two children are at 2 * i + 1
//and 2 * i + 2. E.g., the tree
/*
 *        2
 *     4     6
 *    5 8   9 7
 */
//would be saved as [2, 4, 6, 5, 8, 9, 7].

#define NODES 10

int main(void)
{
  pair queue[NODES];
  
  for (int i = 0; i < NODES; i++)
  {
    node square;
    square.x = 1;
    pair pair;
    pair.node = &square;
    pair.priority = i + 1;
    queue[i] = pair;
  }

  for (int i = 0; i < NODES; i++)
  {
    printf("%i", queue[i].node->x);
    printf("%zu", queue[i].priority);
  }


}

