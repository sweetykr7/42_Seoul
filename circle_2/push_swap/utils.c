#include "push_swap.h"

node  *new_node(int data)
{
  node *new;

  new = (node *)malloc(sizeof(node));
  if (!new)
    return (0);
  new->data = data;
  new->pre = 0;
  new->next = 0;

  return (new);
}

node  