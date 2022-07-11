/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 18:33:39 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_sort_complete_a(t_head *a, int size)
{
	t_list	*temp;

	temp = a->head;
	while (size > 0 && temp)
	{
		temp->cluster_cnt = -1;
		temp = temp->next;
		size--;
	}
}

int	sort_a_cnt_3(t_head *a, t_head *b, t_buf *print_buf)
{
	int	para1;
	int	para2;
	int	para3;
	int	error;

	error = 0;
	para3 = a->head->data;
	para2 = a->head->next->data;
	para1 = a->head->next->next->data;
	if (para1 < para2 && para2 < para3)
		sort_a_case_1(a, b, print_buf, &error);
	else if (para1 < para3 && para3 < para2)
		sort_a_case_2(a, b, print_buf, &error);
	else if (para2 < para1 && para1 < para3)
		sort_a_case_3(a, print_buf, &error);
	else if (para3 < para1 && para1 < para2)
		sort_a_case_4(a, print_buf, &error);
	else if (para2 < para3 && para3 < para1)
		sort_a_case_5(a, print_buf, &error);
	if (error == 1)
		return (0);
	return (1);
}

int	sort_a(t_head *a, t_head *b, int size, t_buf *print_buf)
{
	if (check_asc_sort_a(a, size) == 1)
		return (1);
	if (size == 3)
	{
		if (a->total_cnt <= 3 && b->total_cnt == 0)
		{
			if (!sort_optimize_3(a, print_buf))
				return (0);
		}
		else
		{
			if (!sort_a_cnt_3(a, b, print_buf))
				return (0);
			write_sort_complete_a(a, 3);
		}
	}
	else if (size == 2)
	{
		if (!swap(a, print_buf, 'a'))
			return (0);
		write_sort_complete_a(a, 2);
	}
	else
		write_sort_complete_a(a, 1);
	return (1);
}
