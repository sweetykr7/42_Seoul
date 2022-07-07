/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/07 13:10:11 by sooyokim         ###   ########.fr       */
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

void	sort_b_cnt_3(t_head *a, t_head *b, t_buf *print_buf)
{
	int	para1;
	int	para2;
	int	para3;

	para1 = b->head->data;
	para2 = b->head->next->data;
	para3 = b->head->next->next->data;
	write_sort_complete_b(b, 3);
	if (para1 < para2 && para2 < para3)
		sort_b_case_1(a, b, print_buf);
	else if (para1 < para3 && para3 < para2)
		sort_b_case_2(a, b, print_buf);
	else if (para2 < para1 && para1 < para3)
		sort_b_case_3(a, b, print_buf);
	else if (para3 < para1 && para1 < para2)
		sort_b_case_4(a, b, print_buf);
	else if (para2 < para3 && para3 < para1)
		sort_b_case_5(a, b, print_buf);
	return ;
}

void	sort_b(t_head *a, t_head *b, int size, t_buf *print_buf)
{
	if (check_desc_sort_b(b, size) == 1)
	{
		while (size > 0)
		{			
			push_from_to(b, a, print_buf, 'a');
			size--;
		}
		return ;
	}
	if (size == 3)
		sort_b_cnt_3(a, b, print_buf);
	else if (size == 2)
	{
		write_sort_complete_b(b, 2);
		swap(b, print_buf, 'b');
		push_from_to(b, a, print_buf, 'a');
		push_from_to(b, a, print_buf, 'a');
	}
	else
	{
		write_sort_complete_b(b, 1);
		push_from_to(b, a, print_buf, 'a');
	}
}
