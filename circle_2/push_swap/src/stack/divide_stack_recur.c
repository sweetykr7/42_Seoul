/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack_recur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:48:52 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 18:48:23 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_stack_a_check(t_head *a, t_head *b, t_buf *buf)
{
	t_pivot	pivot;

	pivot = pivot_initial();
	if (1 <= a->head->cluster_cnt && a->head->cluster_cnt <= 3)
	{
		if (!sort_a(a, b, a->head->cluster_cnt, buf))
			return (0);
	}
	else if (a->total_cnt == 5 && b->total_cnt == 0)
	{
		if (!sort_optimize_5(a, b, buf))
			return (0);
	}
	else
	{
		pivot = get_pivot(a, pivot);
		if (pivot.pivot1 != 0 || pivot.pivot2 != 0)
		{
			if (!divide_stack_a(a, b, pivot, buf))
				return (0);
		}
		else if (pivot.pivot1 == 0 && pivot.pivot2 == 0)
			return (0);
	}
	return (1);
}

int	divide_stack_b_check(t_head *a, t_head *b, t_buf *buf)
{
	t_pivot	pivot;

	pivot = pivot_initial();
	if (b->head->cluster_cnt <= 3)
		sort_b(a, b, b->head->cluster_cnt, buf);
	else
	{
		pivot = get_pivot(b, pivot);
		if (pivot.pivot1 != 0 || pivot.pivot2 != 0)
		{
			if (!divide_stack_b(a, b, pivot, buf))
				return (0);
		}
		else if (pivot.pivot1 == 0 && pivot.pivot2 == 0)
			return (0);
	}
	return (1);
}

int	check_large_data_in_b(t_head *a, t_head *b, t_buf *buf)
{
	if (a->total_cnt > 0 && b->total_cnt > 0)
	{
		if (lst_last_data(a->head) < b->head->data)
		{
			if (!divide_stack_b_check(a, b, buf))
				return (-1);
			else
				return (1);
		}
	}
	return (0);
}

int	divide_stack_choice(t_head *a, t_head *b, int check_sort_a_res, t_buf *buf)
{
	if (check_sort_a_res == 0)
	{
		if (!divide_stack_a_check(a, b, buf))
			return (0);
	}
	else
	{
		if (!divide_stack_b_check(a, b, buf))
			return (0);
	}
	return (1);
}

int	divide_stack_recur(t_head *a, t_head *b, int total_cnt, t_buf *buf)
{
	int		check_sort_a_res;
	int		check_large_data;

	check_sort_a_res = initial_sort_check(a);
	if (a->total_cnt == total_cnt && check_sort_a_res == 1)
		return (1);
	if (check_sort_a_res == 2)
	{
		check_large_data = check_large_data_in_b(a, b, buf);
		if (check_large_data)
			return (divide_stack_recur(a, b, total_cnt, buf));
		else if (check_large_data == -1)
			return (0);
		check_sort_a_res = process_remain_ra_data(a, buf);
		if (check_sort_a_res == -1)
			return (0);
	}
	if (!divide_stack_choice(a, b, check_sort_a_res, buf))
		return (0);
	divide_stack_recur(a, b, total_cnt, buf);
	return (1);
}
