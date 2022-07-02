/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_divide_stack_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:31:46 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/02 14:14:16 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_stack_b_pivot1(t_head *a, t_head *b, int *pivot_cnt1, char *buf)
{
	b->head->cluster_cnt = 0;
	rb(b, buf);
	*pivot_cnt1 = *pivot_cnt1 + 1;
}

void	divide_stack_b_pivot2(t_head *a, t_head *b, int *pivot_cnt2, char *buf)
{
	b->head->cluster_cnt = 0;
	pa(a, b, buf);
	ra(a, buf);
	*pivot_cnt2 = *pivot_cnt2 + 1;
}

void	divide_stack_b_pivot3(t_head *a, t_head *b, int *pivot_cnt3, char *buf)
{
	b->head->cluster_cnt = 0;
	pa(a, b, buf);
	*pivot_cnt3 = *pivot_cnt3 + 1;
}

void	pivot_cnt_set_b(t_head *a, t_head *b, t_pc *pivot_cnt, char *buf)
{
	int		i;
	t_list	*temp;

	a->head->cluster_cnt = pivot_cnt->pivot3_cnt;
	i = pivot_cnt->pivot1_cnt + 1;
	while (--i > 0)
		rrb(b, 0, buf);
	b->head->cluster_cnt = pivot_cnt->pivot1_cnt;
	temp = a->head;
	i = a->total_cnt - pivot_cnt->pivot2_cnt + 1;
	while (--i > 0)
		temp = temp->next;
	temp->cluster_cnt = pivot_cnt->pivot2_cnt;
	free(pivot_cnt);
}

void	divide_stack_b(t_head *a, t_head *b, t_pivot pivot, char *buf)
{
	int		i;
	t_pc	*pivot_cnt;

	pivot_cnt = pivot_cnt_pre_set(pivot_cnt);
	i = b->head->cluster_cnt + 1;
	while (--i > 0)
	{
		if (b->head->data <= pivot.pivot1)
			divide_stack_b_pivot1(a, b, &pivot_cnt->pivot1_cnt, buf);
		else if (b->head->data <= pivot.pivot2)
			divide_stack_b_pivot2(a, b, &pivot_cnt->pivot2_cnt, buf);
		else
			divide_stack_b_pivot3(a, b, &pivot_cnt->pivot3_cnt, buf);
	}
	pivot_cnt_set_b(a, b, pivot_cnt, buf);
}
