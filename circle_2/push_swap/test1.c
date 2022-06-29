#include "push_swap.h"
#include "util_list.c"
#include "util_stack_a.c"
#include "util_stack_b.c"
#include "push_swap.c"

#include <stdio.h>

int main(void)
{
	t_head	*head;
	t_head	*head_b;
	t_list	*temp;
	int testarr[5];
	int testarr_b[5];
	int i;
	int	pull_data;

	head = new_head();
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
		head = list_add(head, testarr[i]);
		head_b = list_add(head_b, testarr_b[i]);
		i++;
	}

	// 기본 출력
	i = 0;
	temp = head->head;
	while (i < head->cnt)
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

	// pull test
	// pull_data = pull(head);
	// i = 0;
	// temp = head->head;
	// while (i < head->cnt)
	// {
	// 	printf("test %d \n",(temp->data));
	// 	temp = temp->next;
	// 	i++;
	// }

	//util_stack_a test
	// pa test;
	// pa(head, head_b);


	// i = 0;
	// temp = head->head;
	// while (i < head->cnt)
	// {
	// 	printf("pa Test, stack a[%d] : %d \n",i,(temp->data));
	// 	temp = temp->next;
	// 	i++;
	// }

	// sa test;
	// sa(head);


	// i = 0;
	// temp = head->head;
	// while (i < head->cnt)
	// {
	// 	printf("sa Test, stack a[%d] : %d \n",i,(temp->data));
	// 	temp = temp->next;
	// 	i++;
	// }

	//rra test
	// rra(head);

	// i = 0;
	// temp = head->head;
	// while (i < head->cnt)
	// {
	// 	printf("rra Test, stack a[%d] : %d \n",i,(temp->data));
	// 	temp = temp->next;
	// 	i++;
	// }

	//ra test
	// ra(head);

	// i = 0;
	// temp = head->head;
	// while (i < head->cnt)
	// {
	// 	printf("rra Test, stack a[%d] : %d \n",i,(temp->data));
	// 	temp = temp->next;
	// 	i++;
	// }



	//util_stack_b test
	//pb test;
	// pb(head_b, head);


	// i = 0;
	// temp = head_b->head;
	// while (i < head_b->cnt)
	// {
	// 	printf("pb Test, stack b[%d] : %d \n",i,(temp->data));
	// 	temp = temp->next;
	// 	i++;
	// }

	// sb(head_b);


	// i = 0;
	// temp = head_b->head;
	// while (i < head_b->cnt)
	// {
	// 	printf("sb Test, stack b[%d] : %d \n",i,(temp->data));
	// 	temp = temp->next;
	// 	i++;
	// }	

	// rb(head_b);


	// i = 0;
	// temp = head_b->head;
	// while (i < head_b->cnt)
	// {
	// 	printf("rb Test, stack b[%d] : %d \n",i,(temp->data));
	// 	temp = temp->next;
	// 	i++;
	// }	

	// rrb(head_b);


	// i = 0;
	// temp = head_b->head;
	// while (i < head_b->cnt)
	// {
	// 	printf("rrb Test, stack b[%d] : %d \n",i,(temp->data));
	// 	temp = temp->next;
	// 	i++;
	// }	











	
	return (0);
}
