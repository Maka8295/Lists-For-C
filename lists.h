#ifndef UTILS_H
#define UTILS_H

typedef struct node
{
  char *str;
  struct node *next;
}
node;

node* reverse(node* list);

char* indexVal(node *list, int index);

node* lastNode(node *list);

node* append(int num, node *list, ...);

#endif /* UTILS_H */
