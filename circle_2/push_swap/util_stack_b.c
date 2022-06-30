/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:29:04 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/30 20:10:06 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_head *a, t_head *b)
{
	int	pull_data;

	pull_data = 0;
	a = pull(a, &pull_data);
	b = push(b, pull_data);
}

void	sb(t_head *b)
{
	int		pull_data_1;
	int		pull_data_2;

	pull_data_1 = 0;
	pull_data_2 = 0;
	b = pull(b, &pull_data_1);
	b = pull(b, &pull_data_2);
	b = push(b, pull_data_1);
	b = push(b, pull_data_2);
}

void	rrb(t_head *b)
{
	t_list	*temp;
	t_list	*temp2;
	int		pull_data;
	int		sort_check;

	temp = b->head;
	sort_check = 0;
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
	b = push(b, pull_data);
	if (sort_check != 0)
		b->head->cluster_cnt = sort_check;
}

void	rb(t_head *b)
{
	int		pull_data;
	int		sort_check;

	sort_check = 0;
	if (b->head->cluster_cnt == -1)
		sort_check = -1;
	pull(b, &pull_data);
	list_add(b, pull_data, sort_check);
}
