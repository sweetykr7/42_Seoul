/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_divide_stack_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joey <joey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:28:13 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/05 20:52:12 by joey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_stack_a_pivot1(t_head *a, t_head *b, int *pivot_cnt1, t_buf *buf)
{
	a->head->cluster_cnt = 0;
	pb(a, b, buf);
	*pivot_cnt1 = *pivot_cnt1 + 1;
}

void	divide_stack_a_pivot2(t_head *a, t_head *b, int *pivot_cnt2, t_buf *buf)
{
	a->head->cluster_cnt = 0;
	pb(a, b, buf);
	rb(b, buf);
	*pivot_cnt2 = *pivot_cnt2 + 1;
}

void	divide_stack_a_pivot3(t_head *a, int *pivot_cnt3, t_buf *buf)
{
	a->head->cluster_cnt = 0;
	ra(a, buf);
	*pivot_cnt3 = *pivot_cnt3 + 1;
}

void	pivot_cnt_set_a(t_head *a, t_head *b, t_pc *pivot_cnt, t_buf *buf)
{
	int	i;

	if (pivot_cnt->pivot1_cnt > 0)
		b->head->cluster_cnt = pivot_cnt->pivot1_cnt;
	i = pivot_cnt->pivot2_cnt + 1;
	while (--i > 0)
		rrb(b, 0, buf);
	if (pivot_cnt->pivot3_cnt > 0)
	{
		i = pivot_cnt->pivot3_cnt + 1;
		while (--i > 0 && a->total_cnt > 1)
			rra(a, 0, buf);
	}
	if (pivot_cnt->pivot2_cnt > 0)
		b->head->cluster_cnt = pivot_cnt->pivot2_cnt;
	if (pivot_cnt->pivot3_cnt > 0)
		a->head->cluster_cnt = pivot_cnt->pivot3_cnt;
}

void	divide_stack_a(t_head *a, t_head *b, t_pivot pivot, t_buf *buf)
{
	int		i;
	t_pc	*pivot_cnt;

	pivot_cnt = 0;
	pivot_cnt = pivot_cnt_pre_set(pivot_cnt);
	i = a->head->cluster_cnt + 1;
	while (--i > 0)
	{
		if (a->head->data <= pivot.pivot1)
		{
			printf("divide_stack_a check 1_start\n");
			divide_stack_a_pivot1(a, b, &pivot_cnt->pivot1_cnt, buf);
			printf("divide_stack_a check 1_pass\n");
		}
		else if (a->head->data <= pivot.pivot2)
		{
			printf("divide_stack_a check 2_start\n");
			divide_stack_a_pivot2(a, b, &pivot_cnt->pivot2_cnt, buf);
			printf("divide_stack_a check 2_pass\n");
		}
		else
		{
			printf("divide_stack_a check 3_start\n");
			divide_stack_a_pivot3(a, &pivot_cnt->pivot3_cnt, buf);
			printf("divide_stack_a check 3_pass\n");
		}
	}
	pivot_cnt_set_a(a, b, pivot_cnt, buf);
	free(pivot_cnt);
}
