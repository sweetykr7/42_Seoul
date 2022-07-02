/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack_recur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:48:52 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/02 14:34:33 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_stack_a_check(t_head *a, t_head *b, t_pivot pivot, char *buf)
{
	if (1 <= a->head->cluster_cnt && a->head->cluster_cnt <= 3)
		sort_a(a, b, a->head->cluster_cnt, buf);
	else
	{
		pivot = get_pivot(a);
		if (pivot.pivot1 != 0 || pivot.pivot2 != 0)
			divide_stack_a(a, b, pivot, buf);
	}
}

void	divide_stack_b_check(t_head *a, t_head *b, t_pivot pivot, char *buf)
{
	if (b->head->cluster_cnt <= 3)
		sort_b(a, b, b->head->cluster_cnt, buf);
	else
	{
		pivot = get_pivot(b);
		if (pivot.pivot1 != 0 || pivot.pivot2 != 0)
			divide_stack_b(a, b, pivot, buf);
	}
}

void	divide_stack_recur(t_head *a, t_head *b, int total_cnt, char *print_buf)
{
	t_pivot	pivot;
	int		check_sort_a_res;
	int		test_point;

	check_asc_sort_a(a, a->total_cnt);
	check_sort_a_res = check_sort_a(a);
	if (a->total_cnt == total_cnt && check_sort_a_res == 1)
		return ;
	check_sort_a_res = 0;
	check_sort_a_res = check_sort_a(a);
	if (check_sort_a_res == 2)
	{
		while (a->head->cluster_cnt == 0 || a->head->cluster_cnt == -1)
			rra(a, 0, print_buf);
		check_sort_a_res = check_sort_a(a);
	}
	if (check_sort_a_res == 0)
		divide_stack_a_check(a, b, pivot, print_buf);
	else
		divide_stack_b_check(a, b, pivot, print_buf);
	divide_stack_recur(a, b, total_cnt, print_buf);
}
