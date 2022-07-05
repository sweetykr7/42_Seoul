/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:29:04 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/05 15:36:43 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_head *a, t_head *b, t_buf *print_buf)
{
	int	pull_data;
	//int	cluster_cnt;

	pull_data = 0;
	//cluster_cnt = a->head->cluster_cnt;
	pull_data = pull(a);
	push(b, pull_data);
	//b->head->cluster_cnt = cluster_cnt;
	insert_print_buf(print_buf, "pb");
}

void	sb(t_head *b, t_buf *print_buf)
{
	int		pull_data_1;
	int		pull_data_2;
	int		cluster_cnt1;
	int		cluster_cnt2;

	pull_data_1 = 0;
	pull_data_2 = 0;
	cluster_cnt1 = 0;
	cluster_cnt2 = 0;
	if (b->head->next)
	{
		cluster_cnt1 = b->head->cluster_cnt;
		cluster_cnt2 = b->head->next->cluster_cnt;
	}
	pull_data_1 = pull(b);
	pull_data_2 = pull(b);
	push(b, pull_data_1);
	b->head->cluster_cnt = cluster_cnt1;
	push(b, pull_data_2);
	b->head->cluster_cnt = cluster_cnt2;
	insert_print_buf(print_buf, "sb");
}

void	rrb(t_head *b, int sort_check, t_buf *print_buf)
{
	t_list	*temp;
	t_list	*temp2;
	int		pull_data;	

	pull_data = 0;
	if (b->total_cnt == 1)
		return ;
	temp = b->head;
	while (temp->next)
	{
		if (!(temp->next))
		{
			if (temp->cluster_cnt != 0)
				sort_check = temp->next->cluster_cnt;
			pull_data = temp->next->data;
			temp2 = temp->next;
			temp->next = 0;
			b->total_cnt = b->total_cnt - 1;
			free(temp2);
			break ;
		}
		temp = temp->next;
	}
	push(b, pull_data);
	if (sort_check != 0)
		b->head->cluster_cnt = sort_check;
	insert_print_buf(print_buf, "rrb");
}

void	rb(t_head *b, t_buf *print_buf)
{
	int		pull_data;
	int		sort_check;

	pull_data = 0;
	if (b->total_cnt == 1)
		return ;
	sort_check = 0;
	if (b->head->cluster_cnt == -1)
		sort_check = -1;
	pull_data = pull(b);
	list_add(b, pull_data, sort_check);
	insert_print_buf(print_buf, "rb");
}
