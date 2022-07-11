/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_optimize_5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:09:17 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 18:45:44 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_optimize_5_cluster_cnt_set(t_head *a, t_head *b, t_buf *print_buf)
{
	a->head->cluster_cnt = 3;
	a->head->next->cluster_cnt = 0;
	a->head->next->next->cluster_cnt = 0;
	b->head->cluster_cnt = 2;
	b->head->next->cluster_cnt = 0;
	if (!check_asc_sort_a(a, 3))
	{
		if (!sort_optimize_3(a, print_buf))
			return (0);
	}
	if (!check_desc_sort_b(b, 2))
	{
		if (!swap(b, print_buf, 'b'))
			return (0);
	}
	if (!push_from_to(b, a, print_buf, 'a'))
		return (0);
	if (!push_from_to(b, a, print_buf, 'a'))
		return (0);
	a->head->cluster_cnt = -1;
	a->head->next->cluster_cnt = -1;
	return (1);
}

int	sort_optimize_5(t_head *a, t_head *b, t_buf *print_buf)
{
	int		mid;
	int		b_cnt;
	t_list	*temp;

	mid = 0;
	mid = get_pivot_mid(a, mid);
	if (!mid)
		return (0);
	b_cnt = 0;
	temp = a->head;
	while (b_cnt < 2)
	{
		if (a->head->data < mid)
		{
			if (!push_from_to(a, b, print_buf, 'b'))
				return (0);
			b_cnt++;
		}
		else
			if (!reverse(a, print_buf, 'a'))
				return (0);
	}
	if (!sort_optimize_5_cluster_cnt_set(a, b, print_buf))
		return (0);
	return (1);
}
