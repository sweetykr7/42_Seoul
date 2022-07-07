/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_divide_stack_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:31:46 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/07 17:31:17 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_stack_b_pivot1(t_head *b, int *pivot_cnt1, t_buf *buf)
{
	b->head->cluster_cnt = 0;
	reverse(b, buf, 'b');
	*pivot_cnt1 = *pivot_cnt1 + 1;
}

void	divide_stack_b_pivot2(t_head *a, t_head *b, int *pivot_cnt2, t_buf *buf)
{
	b->head->cluster_cnt = 0;
	push_from_to(b, a, buf, 'a');
	reverse(a, buf, 'a');
	*pivot_cnt2 = *pivot_cnt2 + 1;
}

void	divide_stack_b_pivot3(t_head *a, t_head *b, int *pivot_cnt3, t_buf *buf)
{
	b->head->cluster_cnt = 0;
	push_from_to(b, a, buf, 'a');
	*pivot_cnt3 = *pivot_cnt3 + 1;
}

void	pivot_cnt_set_b(t_head *a, t_head *b, t_pc *pivot_cnt, t_buf *buf)
{
	int		i;
	t_list	*temp;

		int		check_zero_data;

	check_zero_data = 0;
	check_zero_data = check_data_zero_one(a);
	if (check_zero_data == -1)
		printf("zero data a, before pivot_cnt_set_b!!!!!!!!!!!\n");
	check_zero_data = check_data_zero_one(b);
	if (check_zero_data == -1)
		printf("zero data b, before pivot_cnt_set_b!!!!!!!!!!!\n");

	if (pivot_cnt->pivot3_cnt > 0)
		a->head->cluster_cnt = pivot_cnt->pivot3_cnt;
	if (pivot_cnt->pivot1_cnt > 0)
	{
		i = pivot_cnt->pivot1_cnt + 1;
		while (--i > 0 && pivot_cnt->pivot1_cnt != b->total_cnt)
			re_reverse(b, buf, 'b');
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

	check_zero_data = 0;
	check_zero_data = check_data_zero_one(a);
	if (check_zero_data == -1)
		printf("zero data a, after pivot_cnt_set_b!!!!!!!!!!!\n");
	check_zero_data = check_data_zero_one(b);
	if (check_zero_data == -1)
		printf("zero data b, after pivot_cnt_set_b!!!!!!!!!!!\n");
}

void	divide_stack_b(t_head *a, t_head *b, t_pivot *pivot, t_buf *buf)
{
	int		i;
	t_pc	*pivot_cnt;

	pivot_cnt = 0;
	pivot_cnt = pivot_cnt_pre_set(pivot_cnt);
	i = b->head->cluster_cnt + 1;
	while (--i > 0)
	{
		if (b->head->data <= pivot->pivot1)
			divide_stack_b_pivot1(b, &pivot_cnt->pivot1_cnt, buf);
		else if (b->head->data <= pivot->pivot2)
			divide_stack_b_pivot2(a, b, &pivot_cnt->pivot2_cnt, buf);
		else
			divide_stack_b_pivot3(a, b, &pivot_cnt->pivot3_cnt, buf);
	}
	pivot_cnt_set_b(a, b, pivot_cnt, buf);
}
