/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_divide_stack_recur.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:05:54 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 17:17:29 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_remain_ra_data(t_head *a, t_buf *buf)
{
	int	check_sort_a_res;

	while (a->head->cluster_cnt == 0 || a->head->cluster_cnt == -1)
		if (!re_reverse(a, buf, 'a'))
			return (-1);
	check_sort_a_res = check_sort_a(a);
	return (check_sort_a_res);
}

int	initial_sort_check(t_head *a)
{
	int	check_sort_a_res;

	check_sort_a_res = 0;
	check_asc_sort_a(a, a->total_cnt);
	check_sort_a_res = check_sort_a(a);
	return (check_sort_a_res);
}
