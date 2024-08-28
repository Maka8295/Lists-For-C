#include "pq.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>



int main() {
    // Initialize priority queue
    PriorityQueue pq = { { NULL }, 0 };

    // Create some nodes
    for (int i = 0; i < MAX; i++) {
      node *node = malloc(sizeof(node));
      node->priority = i+1;
      enqueue(&pq, node);
    }


    // Dequeue a node and print its priority
    for (int j = 0; j < MAX; j++) {
      node* dequeued = dequeue(&pq);
      if (dequeued) {
          printf("Dequeued node with priority %d\n", dequeued->priority);
          free(dequeued);
      }

    }

    // Peek at the top node's priority
    node* top = peek(&pq);
    if (top) {
        printf("Top node has priority %d\n", top->priority);
    }

    // Free remaining nodes
    while (pq.size > 0) {
        free(dequeue(&pq));
    }

    return 0;
}

