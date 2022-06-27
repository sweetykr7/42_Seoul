

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>



typedef struct circle_linked_list
{
  int data;
  struct circle_linked_list *pre;
  struct circle_linked_list *next;
} node;

node  *new_node(int data);

#endif