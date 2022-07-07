/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:29:04 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/07 14:29:28 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_to(t_head *b, t_head *a, t_buf *print_buf, char option)
{
	t_list	*pull_list;

	int		check_zero_data;

	//printf("start pa or pb!!!!!!!!!!!!\n");	
	check_zero_data = 0;
	check_zero_data = check_data_zero_one(a);
	if (check_zero_data == -1)
		printf("zero data in the before pa!!!!!!!!!!!\n");
	check_zero_data = check_data_zero_one(b);
	if (check_zero_data == -1)
		printf("zero data in the before pb!!!!!!!!!!!\n");

	// t_list	*temp;
	// t_list	*temp2;


	// if (b->total_cnt != 0)
	// {
	// 	temp = b->head;		
	// 	if (b->head->next)
	// 		b->head = b->head->next;
	// 	else
	// 		b->head = 0;
	// 	temp->next = 0;
	// 	b->total_cnt = b->total_cnt - 1;
	// }
	// else
	// 	return ;
	
	// if (a->head)
	// 	temp2 = a->head;
	// else
	// 	temp2 = 0;
	
	// a->head = temp;
	// a->head->next = temp2;
	// a->total_cnt = a->total_cnt + 1;









	pull_list = pull_stack(b);
	// check_zero_data = check_data_zero_one(a);
	// if (check_zero_data == -1)
	// 	printf("zero data in the after pa or pb's pull_stack!!!!!!!!!!!\n");
	push_stack(a, pull_list);
	// check_zero_data = check_data_zero_one(a);
	// if (check_zero_data == -1)
	// 	printf("zero data in the after pa or pb's push_stack!!!!!!!!!!!\n");
	// if (option == 'a')
	// 	insert_print_buf(print_buf, "pa\n");
	// else
	// 	insert_print_buf(print_buf, "pb\n");
	(void)print_buf;
	if (option == 'a')
		printf("pa\n");
	else
		printf("pb\n");
	check_zero_data = check_data_zero_one(a);
	if (check_zero_data == -1)
		printf("zero data in the after pa or pb!!!!!!!!!!!\n");
	//printf("pass pa!\n");
}

void	swap(t_head *a, t_buf *print_buf, char option)
{
	t_list	*pull_list1;
	t_list	*pull_list2;
	t_list	*temp;
	int		check_zero_data;

	check_zero_data = 0;
	check_zero_data = check_data_zero_one(a);
	if (check_zero_data == -1)
		printf("zero data in the before swap!!!!!!!!!!!\n");

	
	pull_list1 = a->head;
	pull_list2 = a->head->next;
	if (a->head->next->next)
		temp = a->head->next->next;
	else
		temp = 0;
	a->head = pull_list2;
	a->head->next = pull_list1;
	a->head->next->next = temp;
	// if (option == 'a')
	// 	insert_print_buf(print_buf, "sa\n");
	// else
	// 	insert_print_buf(print_buf, "sb\n");
	(void)print_buf;
	if (option == 'a')
		printf("sa\n");
	else
		printf("sb\n");
	check_zero_data = check_data_zero_one(a);
	if (check_zero_data == -1)
		printf("zero data in the after swap!!!!!!!!!!!\n");

	//printf("pass sa!\n");
}

void	re_reverse(t_head *a, t_buf *print_buf, char option)
{
	t_list	*last_list;
	t_list	*last_second_list;
	t_list	*pre_first_lst;
	int		check_zero_data;

	check_zero_data = 0;
	check_zero_data = check_data_zero_one(a);
	if (check_zero_data == -1)
		printf("zero data in the before re_reverse!!!!!!!!!!!\n");
	if (a->total_cnt == 1)
		return ;
	printf("rr total cnt : %d\n", a->total_cnt);
	if (a->total_cnt == 2)
	{
		if (option == 'a')
			return (swap(a, print_buf, 'a'));
		else
			return (swap(a, print_buf, 'b'));
	}
	pre_first_lst = a->head;
	last_second_list = last_second_lst(a->head);
	last_list = last_second_list->next;
	last_second_list->next = 0;
	a->head = last_list;
	a->head->next = pre_first_lst;
	// if (option == 'a')
	// 	insert_print_buf(print_buf, "rra\n");
	// else
	// 	insert_print_buf(print_buf, "rrb\n");
	(void)print_buf;
	if (option == 'a')
		printf("rra\n");
	else
		printf("rrb\n");
	check_zero_data = check_data_zero_one(a);
	if (check_zero_data == -1)
		printf("zero data in the after re_reverse!!!!!!!!!!!\n");
	//printf("pass rr%c!\n", option);
}

void	reverse(t_head *a, t_buf *print_buf, char option)
{
	t_list	*pre_first_lst;
	t_list	*temp;

	int		check_zero_data;

	check_zero_data = 0;
	check_zero_data = check_data_zero_one(a);
	if (check_zero_data == -1)
		printf("zero data in the before reverse!!!!!!!!!!!\n");

	if (a->total_cnt == 1)
		return ;
	pre_first_lst = a->head;
	a->head = a->head->next;
	pre_first_lst->next = 0;
	temp = a->head;
	while (temp)
	{
		if (!temp->next)
		{
			temp->next = pre_first_lst;
			break ;
		}
		temp = temp->next;
	}
	// if (option == 'a')
	// 	insert_print_buf(print_buf, "ra\n");
	// else
	// 	insert_print_buf(print_buf, "rb\n");
	(void)print_buf;
	if (option == 'a')
		printf("ra\n");
	else
		printf("rb\n");
	//printf("pass ra!\n");
	check_zero_data = check_data_zero_one(a);
	if (check_zero_data == -1)
		printf("zero data in the after reverse!!!!!!!!!!!\n");
}
