/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack_recur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:48:52 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/05 14:30:33 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_stack_a_check(t_head *a, t_head *b, t_pivot pivot, t_buf *buf)
{
	if (1 <= a->head->cluster_cnt && a->head->cluster_cnt <= 3)
	{
		printf("pass test7\n");
		sort_a(a, b, a->head->cluster_cnt, buf);
		printf("pass test8\n");
	}
	else
	{
		printf("cluster check before test9 : %d\n",a->head->cluster_cnt);
		printf("pass test9\n");
		pivot = get_pivot(a);
		printf("pass test10\n");
		if (pivot.pivot1 != 0 || pivot.pivot2 != 0)
			divide_stack_a(a, b, pivot, buf);
		printf("pass test11\n");
	}
}

void	divide_stack_b_check(t_head *a, t_head *b, t_pivot pivot, t_buf *buf)
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

void	divide_stack_recur(t_head *a, t_head *b, int total_cnt, t_buf *buf)
{
	t_pivot	pivot;
	int		check_sort_a_res;

	pivot.pivot1 = 0;
	pivot.pivot2 = 0;
	check_sort_a_res = 0;
	check_asc_sort_a(a, a->total_cnt);
	check_sort_a_res = check_sort_a(a);
	printf("pass test1\n");
	if (a->total_cnt == total_cnt && check_sort_a_res == 1)
		return ;
	if (check_sort_a_res == 2)
	{
		if (a->total_cnt > 0 && b->total_cnt > 0)
		{
			if (lst_last_data(a->head) < b->head->data)
			{
				printf("pass test2\n");
				divide_stack_b_check(a, b, pivot, buf);
				divide_stack_recur(a, b, total_cnt, buf);
				return ;
			}
		}
		printf("pass test3\n");
		while (a->head->cluster_cnt == 0 || a->head->cluster_cnt == -1)
		{
			printf("check this\n");
			rra(a, 0, buf);
		}
		check_sort_a_res = check_sort_a(a);
		printf("pass test4\n");
	}
	if (check_sort_a_res == 0)
	{
		printf("pass test5\n");
		divide_stack_a_check(a, b, pivot, buf);
	}
	else
	{
		printf("pass test6\n");
		divide_stack_b_check(a, b, pivot, buf);
	}
	divide_stack_recur(a, b, total_cnt, buf);
}