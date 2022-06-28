/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:29:04 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/28 16:19:08 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_head *a, t_head *b)
{
	int	pull_data;

	pull_data = 0;
	b = pull(b, &pull_data);
	a = push(a, pull_data);
}

void	sa(t_head *a)
{
	int		pull_data_1;
	int		pull_data_2;

	pull_data_1 = 0;
	pull_data_2 = 0;
	a = pull(a, &pull_data_1);
	a = pull(a, &pull_data_2);
	a = push(a, pull_data_1);
	a = push(a, pull_data_2);
}

void	rra(t_head *a)
{
	t_list	*temp;
	t_list	*temp2;
	int		pull_data;

	temp = a->head;
	while (temp->next)
	{
		if (!(temp->next->next))
		{
			pull_data = temp->next->data;
			temp2 = temp->next;
			temp->next = 0;
			a->cnt = a->cnt - 1;
			free(temp2);
			break ;
		}
		temp = temp->next;
	}
	a = push(a, pull_data);
}

void	ra(t_head *a)
{
	int		pull_data;

	pull(a, &pull_data);
	list_add(a, pull_data);
}
