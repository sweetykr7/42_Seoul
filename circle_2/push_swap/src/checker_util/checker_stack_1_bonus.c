/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:18:18 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/12 11:04:23 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	push_from_to_checker(t_head *b, t_head *a)
{
	t_list	*pull_list;

	if (b->total_cnt == 0)
		return (0);
	pull_list = pull_stack(b);
	push_stack(a, pull_list);
	return (1);
}

int	swap_checker(t_head *a)
{
	t_list	*pull_list1;
	t_list	*pull_list2;
	t_list	*temp;

	if (a->total_cnt < 2)
		return (0);
	pull_list1 = a->head;
	pull_list2 = a->head->next;
	if (a->head->next->next)
		temp = a->head->next->next;
	else
		temp = 0;
	a->head = pull_list2;
	a->head->next = pull_list1;
	a->head->next->next = temp;
	return (1);
}

int	re_reverse_checker(t_head *a)
{
	t_list	*last_list;
	t_list	*last_second_list;
	t_list	*pre_first_lst;

	if (a->total_cnt == 0)
		return (0);
	if (a->total_cnt == 1)
		return (1);
	if (a->total_cnt == 2)
		return (swap_checker(a));
	pre_first_lst = a->head;
	last_second_list = last_second_lst(a->head);
	last_list = last_second_list->next;
	last_second_list->next = 0;
	a->head = last_list;
	a->head->next = pre_first_lst;
	return (1);
}

int	reverse_checker(t_head *a)
{
	t_list	*pre_first_lst;
	t_list	*temp;

	if (a->total_cnt == 0)
		return (0);
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
	return (1);
}
