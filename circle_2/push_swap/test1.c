#include "push_swap.h"

#include <stdio.h>

int main(void)
{
  node *new;
  new = new_node(1);

  printf("test %d",new->data);
  free(new);
  return (0);
}
