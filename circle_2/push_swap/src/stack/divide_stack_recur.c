/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack_recur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:48:52 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 16:00:29 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pivot(t_pivot *pivot)
{
	free(pivot);
}

void	divide_stack_a_check(t_head *a, t_head *b, t_pivot *pivot, t_buf *buf)
{
	if (1 <= a->head->cluster_cnt && a->head->cluster_cnt <= 3)
		sort_a(a, b, a->head->cluster_cnt, buf);
	else if (a->total_cnt == 5 && b->total_cnt == 0)
		sort_optimize_5(a, b, buf);
	else
	{
		pivot = get_pivot(a, pivot);
		if (pivot->pivot1 != 0 || pivot->pivot2 != 0)
			divide_stack_a(a, b, pivot, buf);
	}
	free(pivot);
}

void	divide_stack_b_check(t_head *a, t_head *b, t_pivot *pivot, t_buf *buf)
{
	if (b->head->cluster_cnt <= 3)
		sort_b(a, b, b->head->cluster_cnt, buf);
	else
	{
		pivot = get_pivot(b, pivot);
		if (pivot->pivot1 != 0 || pivot->pivot2 != 0)
			divide_stack_b(a, b, pivot, buf);
	}
	free(pivot);
}

t_pivot	*pivot_initial_sort_check(t_head *a, int *check_sort_a_res)
{
	t_pivot	*pivot;

	pivot = malloc(sizeof(t_pivot));
	if (!pivot)
		return (0);
	pivot->pivot1 = 0;
	pivot->pivot2 = 0;
	*check_sort_a_res = 0;
	check_asc_sort_a(a, a->total_cnt);
	*check_sort_a_res = check_sort_a(a);
	return (pivot);
}

void	divide_stack_recur(t_head *a, t_head *b, int total_cnt, t_buf *buf)
{
	t_pivot	*pivot;
	int		check_sort_a_res;

	pivot = pivot_initial_sort_check(a, &check_sort_a_res);
	if (a->total_cnt == total_cnt && check_sort_a_res == 1)
		return (free(pivot));
	if (check_sort_a_res == 2)
	{
		if (a->total_cnt > 0 && b->total_cnt > 0)
		{
			if (lst_last_data(a->head) < b->head->data)
			{
				divide_stack_b_check(a, b, pivot, buf);
				return (divide_stack_recur(a, b, total_cnt, buf));
			}
		}
		while (a->head->cluster_cnt == 0 || a->head->cluster_cnt == -1)
			re_reverse(a, buf, 'a');
		check_sort_a_res = check_sort_a(a);
	}
	if (check_sort_a_res == 0)
		divide_stack_a_check(a, b, pivot, buf);
	else
		divide_stack_b_check(a, b, pivot, buf);
	divide_stack_recur(a, b, total_cnt, buf);
}
