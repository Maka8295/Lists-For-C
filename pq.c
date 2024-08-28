// Thank you to Blaz on stackexchange!

#include "pq.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

void swap(pair queue[], size_t i, size_t j)
{
    pair temp = queue[i];
    queue[i] = queue[j];
    queue[j] = temp;
}


node* dequeue(pair queue[], size_t size)
{
    node *root = queue[0].node;
    queue[0] = queue[--size];

    // Loop while at least one child exists
    for (size_t curr = 0; 2 * curr + 1 < size;)
    {
        size_t min_cost = 1;
        if (2 * curr + 2 < size &&
            queue[2 * curr + 2].priority < queue[2 * curr + 1].priority) {
            min_cost = 2;
        }

        if (queue[curr].priority <= queue[2 * curr + min_cost].priority) {
            break;
        }

        swap(queue, curr, 2 * curr + min_cost);
        curr = 2 * curr + min_cost;
    }

    return root;
}

void bubble_up(pair queue[], size_t curr)
{
    while (curr > 0) 
    {
        size_t parent = (curr - 1) / 2;
        if (queue[parent].priority <= queue[curr].priority) {
            break;
        }
        swap(queue, parent, curr);
        curr = parent;
    }
}

void enqueue(pair queue[], node *node, size_t priority, size_t size)
{
    queue[size] = (pair){node, priority};
    bubble_up(queue, size);
}

void decrease_key(pair queue[], node *node, size_t priority, size_t size)
{
    size_t curr = 0;
    for (; curr < size && queue[curr].node != node; ++curr);
    queue[curr].priority = priority;
    bubble_up(queue, curr);
}


