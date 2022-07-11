/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:29:04 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 17:36:19 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_from_to(t_head *b, t_head *a, t_buf *print_buf, char option)
{
	t_list	*pull_list;

	if (b->total_cnt == 0)
		return (1);
	pull_list = pull_stack(b);
	push_stack(a, pull_list);
	if (!push_from_to_insert_print_buf(print_buf, option))
		return (0);
	return (1);
}

int	swap(t_head *a, t_buf *print_buf, char option)
{
	t_list	*pull_list1;
	t_list	*pull_list2;
	t_list	*temp;

	pull_list1 = a->head;
	pull_list2 = a->head->next;
	if (a->head->next->next)
		temp = a->head->next->next;
	else
		temp = 0;
	a->head = pull_list2;
	a->head->next = pull_list1;
	a->head->next->next = temp;
	if (!swap_insert_print_buf(print_buf, option))
		return (0);
	return (1);
}

int	re_reverse(t_head *a, t_buf *print_buf, char option)
{
	t_list	*last_list;
	t_list	*last_second_list;
	t_list	*pre_first_lst;

	if (a->total_cnt == 1)
		return (1);
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
	if (!re_reverse_insert_print_buf(print_buf, option))
		return (0);
	return (1);
}

int	reverse(t_head *a, t_buf *print_buf, char option)
{
	t_list	*pre_first_lst;
	t_list	*temp;

	if (a->total_cnt == 1)
		return (1);
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
	if (!reverse_insert_print_buf(print_buf, option))
		return (0);
	return (1);
}
