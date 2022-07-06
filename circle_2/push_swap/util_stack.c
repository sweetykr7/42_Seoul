/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:29:04 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/06 16:53:09 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_to(t_head *b, t_head *a, t_buf *print_buf, char option)
{
	t_list	*pull_list;

	(void)print_buf;
	pull_list = pull_stack(b);
	push_stack(a, pull_list);
	if (option == 'a')
		insert_print_buf(print_buf, "pa\n");
	else
		insert_print_buf(print_buf, "pb\n");
	// if (option == 'a')
	// 	insert_print_buf(print_buf, "pa");
	// else
	// 	insert_print_buf(print_buf, "pb");
	// printf("pass pa!\n");
}

void	swap(t_head *a, t_buf *print_buf, char option)
{
	t_list	*pull_list1;
	t_list	*pull_list2;
	t_list	*temp;

	(void)print_buf;
	pull_list1 = a->head;
	pull_list2 = a->head->next;
	if (a->head->next->next)
		temp = a->head->next->next;
	else
		temp = 0;
	a->head = pull_list2;
	a->head->next = pull_list1;
	a->head->next->next = temp;
	if (option == 'a')
		insert_print_buf(print_buf, "sa\n");
	else
		insert_print_buf(print_buf, "sb\n");
	// if (option == 'a')
	// 	insert_print_buf(print_buf, "sa");
	// else
	// 	insert_print_buf(print_buf, "sb");
	// printf("pass sa!\n");
}

void	re_reverse(t_head *a, t_buf *print_buf, char option)
{
	t_list	*last_list;
	t_list	*last_second_list;
	t_list	*pre_first_lst;

	(void)print_buf;
	if (a->total_cnt == 1)
		return ;
	if (a->total_cnt == 2)
	{
		if (option == 'a')
			return (swap(a, print_buf, 'a'));
		else
			return (swap(a, print_buf, 'b'));
	}
	pre_first_lst = a->head;
	last_second_list = last_second_lst(a->head);
	last_list = last_lst(a->head);
	a->head = last_list;
	a->head->next = pre_first_lst;
	last_second_list->next = 0;
	if (option == 'a')
		insert_print_buf(print_buf, "rra\n");
	else
		insert_print_buf(print_buf, "rrb\n");
	// if (option == 'a')
	// 	insert_print_buf(print_buf, "rra");
	// else
	// 	insert_print_buf(print_buf, "rrb");
	// printf("pass rr%c!\n", option);
}

void	reverse(t_head *a, t_buf *print_buf, char option)
{
	t_list	*pre_first_lst;
	t_list	*temp;

	(void)print_buf;
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
	if (option == 'a')
		insert_print_buf(print_buf, "ra\n");
	else
		insert_print_buf(print_buf, "rb\n");
	// if (option == 'a')
	// 	insert_print_buf(print_buf, "ra");
	// else
	// 	insert_print_buf(print_buf, "rb");
	// printf("pass ra!\n");
}
