/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:29:04 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/29 13:26:25 by sooyokim         ###   ########.fr       */
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

	temp = b->head;
	while (temp->next)
	{
		if (!(temp->next->next))
		{
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
}

void	rb(t_head *b)
{
	int		pull_data;

	pull(b, &pull_data);
	list_add(b, pull_data);
}
