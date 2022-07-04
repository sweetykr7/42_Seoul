/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:29:04 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/04 20:53:41 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_head *a, t_head *b, t_buf *print_buf)
{
	int	pull_data;

	pull_data = 0;
	pull(a, &pull_data);
	push(b, pull_data);
	insert_print_buf(print_buf, "pb");
	printf("pb\n");
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
	pull(b, &pull_data_1);
	pull(b, &pull_data_2);
	push(b, pull_data_1);
	b->head->cluster_cnt = cluster_cnt1;
	push(b, pull_data_2);
	b->head->cluster_cnt = cluster_cnt2;
	insert_print_buf(print_buf, "sb");
	printf("sb\n");
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
		if (!(temp->next->next))
		{
			if (temp->next->cluster_cnt != 0)
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
	printf("rrb\n");
}

void	rb(t_head *b, t_buf *print_buf)
{
	int		pull_data;
	int		sort_check;

	if (b->total_cnt == 1)
		return ;
	sort_check = 0;
	if (b->head->cluster_cnt == -1)
		sort_check = -1;
	pull(b, &pull_data);
	list_add(b, pull_data, sort_check);
	insert_print_buf(print_buf, "rb");
	printf("rb\n");	
}
