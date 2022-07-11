/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 19:01:14 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_sort_complete_b(t_head *b, int size)
{
	t_list	*temp;

	temp = b->head;
	while (size > 0 && temp)
	{
		temp->cluster_cnt = -1;
		temp = temp->next;
		size--;
	}
}

int	sort_b_cnt_3(t_head *a, t_head *b, t_buf *print_buf)
{
	int	para1;
	int	para2;
	int	para3;
	int	error;

	error = 0;
	para1 = b->head->data;
	para2 = b->head->next->data;
	para3 = b->head->next->next->data;
	write_sort_complete_b(b, 3);
	if (para1 < para2 && para2 < para3)
		sort_b_case_1(a, b, print_buf, &error);
	else if (para1 < para3 && para3 < para2)
		sort_b_case_2(a, b, print_buf, &error);
	else if (para2 < para1 && para1 < para3)
		sort_b_case_3(a, b, print_buf, &error);
	else if (para3 < para1 && para1 < para2)
		sort_b_case_4(a, b, print_buf, &error);
	else if (para2 < para3 && para3 < para1)
		sort_b_case_5(a, b, print_buf, &error);
	if (error == 1)
		return (0);
	return (1);
}

int	sort_b_size_2(t_head *a, t_head *b, t_buf *print_buf)
{
	write_sort_complete_b(b, 2);
	if (!swap(b, print_buf, 'b'))
		return (0);
	if (!push_from_to(b, a, print_buf, 'a'))
		return (0);
	if (!push_from_to(b, a, print_buf, 'a'))
		return (0);
	return (1);
}

int	sorting_stack_b(t_head *a, t_head *b, int size, t_buf *print_buf)
{
	if (size == 3)
	{
		if (!sort_b_cnt_3(a, b, print_buf))
			return (0);
	}
	else if (size == 2)
	{
		if (!sort_b_size_2(a, b, print_buf))
			return (0);
	}
	else
	{
		write_sort_complete_b(b, 1);
		if (!push_from_to(b, a, print_buf, 'a'))
			return (0);
	}
	return (1);
}

int	sort_b(t_head *a, t_head *b, int size, t_buf *print_buf)
{
	if (check_desc_sort_b(b, size) == 1)
	{
		while (size > 0)
		{			
			if (!push_from_to(b, a, print_buf, 'a'))
				return (0);
			size--;
		}
		return (1);
	}
	if (!sorting_stack_b(a, b, size, print_buf))
		return (0);
	return (1);
}
