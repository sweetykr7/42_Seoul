#include "push_swap.h"
#include "util_list.c"
#include "util_stack_a.c"
#include "util_stack_b.c"
#include "push_swap.c"

#include <stdio.h>

int main(void)
{
	t_head	*head_a;
	t_head	*head_b;
	t_list	*temp;
	int testarr_a[15];
	//int testarr_b[5];
	int i;
	int	pull_data;

	head_a = new_head();
	head_b = new_head();
	i = 0;
	while (i < 5)
	{
		testarr[i] = 1 + 3 * i;
		testarr_b[i] = -(1 + 5 * i);
		i++;
	}

	i = 0;
	while (i < 5)
	{
		head_a = list_add(head, testarr[i]);
		head_b = list_add(head_b, testarr_b[i]);
		i++;
	}

	// 기본 출력
	i = 0;
	temp = head_a->head;
	while (i < head_a->cnt)
	{
		printf("stack a[%d] : %d \n",i,(temp->data));
		temp = temp->next;
		i++;
	}

	i = 0;
	temp = head_b->head;
	while (i < head_b->cnt)
	{
		printf("stack b[%d] : %d \n",i,(temp->data));
		temp = temp->next;
		i++;
	}

	return (0);
}
