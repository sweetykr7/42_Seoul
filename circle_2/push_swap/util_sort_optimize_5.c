/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_optimize_5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:09:17 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/08 12:37:06 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_optimize_5_cluster_cnt_set(t_head *a, t_head *b, t_buf *print_buf)
{
	a->head->cluster_cnt = 3;
	a->head->next->cluster_cnt = 0;
	a->head->next->next->cluster_cnt = 0;
	b->head->cluster_cnt = 2;
	b->head->next->cluster_cnt = 0;
	if (!check_asc_sort_a(a, 3))
		sort_optimize_3(a, print_buf);
	if (!check_desc_sort_b(b, 2))
		swap(b, print_buf, 'b');
	push_from_to(b, a, print_buf, 'a');
	push_from_to(b, a, print_buf, 'a');
	a->head->cluster_cnt = -1;
	a->head->next->cluster_cnt = -1;
}

void	sort_optimize_5(t_head *a, t_head *b, t_buf *print_buf)
{
	int		mid;
	int		b_cnt;
	t_list	*temp;

	mid = 0;
	mid = get_pivot_mid(a, mid);
	b_cnt = 0;
	temp = a->head;
	while (b_cnt < 2)
	{
		if (a->head->data < mid)
		{
			push_from_to(a, b, print_buf, 'b');
			b_cnt++;
		}
		else
			reverse(a, print_buf, 'a');
	}
	sort_optimize_5_cluster_cnt_set(a, b, print_buf);
}
