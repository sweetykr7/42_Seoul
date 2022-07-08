/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/08 10:56:33 by sooyokim         ###   ########.fr       */
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

void	sort_a_cnt_3(t_head *a, t_head *b, t_buf *print_buf)
{
	int	para1;
	int	para2;
	int	para3;

	para3 = a->head->data;
	para2 = a->head->next->data;
	para1 = a->head->next->next->data;
	if (para1 < para2 && para2 < para3)
		sort_a_case_1(a, b, print_buf);
	else if (para1 < para3 && para3 < para2)
		sort_a_case_2(a, b, print_buf);
	else if (para2 < para1 && para1 < para3)
		sort_a_case_3(a, print_buf);
	else if (para3 < para1 && para1 < para2)
		sort_a_case_4(a, print_buf);
	else if (para2 < para3 && para3 < para1)
		sort_a_case_5(a, print_buf);
	write_sort_complete_a(a, 3);
}

void	sort_a(t_head *a, t_head *b, int size, t_buf *print_buf)
{
	if (check_asc_sort_a(a, size) == 1)
		return ;
	if (size == 3)
	{
		if (a->total_cnt <= 3 && b->total_cnt == 0)
			sort_optimize_3(a, print_buf);
		else
			sort_a_cnt_3(a, b, print_buf);
	}
	else if (size == 2)
	{
		swap(a, print_buf, 'a');
		write_sort_complete_a(a, 2);
	}
	else
		write_sort_complete_a(a, 1);
}