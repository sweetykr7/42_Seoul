/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_divide_stack_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:31:46 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 19:26:22 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_stack_b_pivot1(t_head *b, int *pivot_cnt1, t_buf *buf)
{
	b->head->cluster_cnt = 0;
	if (!reverse(b, buf, 'b'))
		return (0);
	*pivot_cnt1 = *pivot_cnt1 + 1;
	return (1);
}

int	divide_stack_b_pivot2(t_head *a, t_head *b, int *pivot_cnt2, t_buf *buf)
{
	b->head->cluster_cnt = 0;
	if (!push_from_to(b, a, buf, 'a'))
		return (0);
	if (!reverse(a, buf, 'a'))
		return (0);
	*pivot_cnt2 = *pivot_cnt2 + 1;
	return (1);
}

int	divide_stack_b_pivot3(t_head *a, t_head *b, int *pivot_cnt3, t_buf *buf)
{
	b->head->cluster_cnt = 0;
	if (!push_from_to(b, a, buf, 'a'))
		return (0);
	*pivot_cnt3 = *pivot_cnt3 + 1;
	return (1);
}

int	pivot_cnt_set_b(t_head *a, t_head *b, t_pc *pivot_cnt, t_buf *buf)
{
	int		i;
	t_list	*temp;

	if (pivot_cnt->pivot3_cnt > 0)
		a->head->cluster_cnt = pivot_cnt->pivot3_cnt;
	if (pivot_cnt->pivot1_cnt > 0)
	{
		i = pivot_cnt->pivot1_cnt + 1;
		while (--i > 0 && pivot_cnt->pivot1_cnt != b->total_cnt)
			if (!re_reverse(b, buf, 'b'))
				return (0);
		b->head->cluster_cnt = pivot_cnt->pivot1_cnt;
	}
	if (pivot_cnt->pivot2_cnt > 0)
	{
		temp = a->head;
		i = a->total_cnt - pivot_cnt->pivot2_cnt + 1;
		while (--i > 0)
			temp = temp->next;
		temp->cluster_cnt = pivot_cnt->pivot2_cnt;
	}
	free(pivot_cnt);
	return (1);
}

int	divide_stack_b(t_head *a, t_head *b, t_pivot pivot, t_buf *buf)
{
	int		i;
	t_pc	*pivot_cnt;
	int		temp;

	pivot_cnt = 0;
	pivot_cnt = pivot_cnt_pre_set(pivot_cnt);
	if (!pivot_cnt)
		return (0);
	i = b->head->cluster_cnt + 1;
	while (--i > 0)
	{
		temp = b->head->data;
		if (temp <= pivot.pivot1)
			if (!divide_stack_b_pivot1(b, &pivot_cnt->pivot1_cnt, buf))
				return (0);
		if (temp > pivot.pivot1 && temp <= pivot.pivot2)
			if (!divide_stack_b_pivot2(a, b, &pivot_cnt->pivot2_cnt, buf))
				return (0);
		if (temp > pivot.pivot2)
			if (!divide_stack_b_pivot3(a, b, &pivot_cnt->pivot3_cnt, buf))
				return (0);
	}
	if (!pivot_cnt_set_b(a, b, pivot_cnt, buf))
		return (0);
	return (1);
}
