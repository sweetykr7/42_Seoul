/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:29:04 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/02 12:17:54 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_head *a, t_head *b, char *print_buf)
{
	int	pull_data;
	int	check_sort;

	pull_data = 0;
	check_sort = 0;
	if (b->head->cluster_cnt == -1)
		check_sort = -1;
	pull(b, &pull_data);
	push(a, pull_data);
	if (check_sort == -1)
		a->head->cluster_cnt = -1;
	//print_buf = insert_print_buf(print_buf, "pa\n");
}

void	sa(t_head *a, char *print_buf)
{
	int		pull_data_1;
	int		pull_data_2;

	pull_data_1 = 0;
	pull_data_2 = 0;
	pull(a, &pull_data_1);
	pull(a, &pull_data_2);
	push(a, pull_data_1);
	push(a, pull_data_2);
	//print_buf = insert_print_buf(print_buf, "sa\n");
}

void	rra(t_head *a, int sort_check, char *print_buf)
{
	t_list	*temp;
	t_list	*temp2;
	int		pull_data;

	temp = a->head;
	while (temp->next)
	{
		if (!(temp->next->next))
		{
			if (temp->next->cluster_cnt != 0)
				sort_check = temp->next->cluster_cnt;
			pull_data = temp->next->data;
			temp2 = temp->next;
			temp->next = 0;
			a->total_cnt = a->total_cnt - 1;
			free(temp2);
			break ;
		}
		temp = temp->next;
	}
	push(a, pull_data);
	if (sort_check != 0)
		a->head->cluster_cnt = sort_check;
	//print_buf = insert_print_buf(print_buf, "rra\n");
}

void	ra(t_head *a, char *print_buf)
{
	int		pull_data;
	int		sort_check;

	sort_check = 0;
	if (a->head->cluster_cnt == -1)
		sort_check = -1;
	pull(a, &pull_data);
	list_add(a, pull_data, sort_check);
	//print_buf = insert_print_buf(print_buf, "ra\n");
}
