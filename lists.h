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

int len(node *list);

node* strip(node *list, char *input);

node* sortLong(node* list);

node* sortShort(node *list); 

#endif /* UTILS_H */
