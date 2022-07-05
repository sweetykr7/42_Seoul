/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:29:04 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/05 15:37:16 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_head *a, t_head *b, t_buf *print_buf)
{
	int	pull_data;
	int	check_sort;
	int	cluster_cnt;

	pull_data = 0;
	check_sort = 0;
	cluster_cnt = b->head->cluster_cnt;
	// if (b->head->cluster_cnt == -1)
	// 	check_sort = -1;
	pull_data = pull(b);
	push(a, pull_data);
	// if (check_sort == -1)
	// 	a->head->cluster_cnt = -1;
	a->head->cluster_cnt = cluster_cnt;
	insert_print_buf(print_buf, "pa");
}

void	sa(t_head *a, t_buf *print_buf)
{
	int		pull_data_1;
	int		pull_data_2;
	int		cluster_cnt1;
	int		cluster_cnt2;

	pull_data_1 = 0;
	pull_data_2 = 0;
	cluster_cnt1 = 0;
	cluster_cnt2 = 0;
	if (a->head->next)
	{
		cluster_cnt1 = a->head->cluster_cnt;
		cluster_cnt2 = a->head->next->cluster_cnt;
	}
	pull_data_1 = pull(a);
	pull_data_2 = pull(a);
	push(a, pull_data_1);
	a->head->cluster_cnt = cluster_cnt1;
	push(a, pull_data_2);
	a->head->cluster_cnt = cluster_cnt2;
	insert_print_buf(print_buf, "sa");
}

void	rra(t_head *a, int sort_check, t_buf *print_buf)
{
	t_list	*temp;
	t_list	*temp2;
	int		pull_data;
	int		cluster_cnt;

	sort_check = 0;
	cluster_cnt = 0;
	pull_data = 0;
	temp = a->head;
	if (a->total_cnt == 1)
		return ;
	while (temp->next)
	{
		if (!(temp->next))
		{
			// if (temp->next->cluster_cnt != 0)
			// 	sort_check = temp->next->cluster_cnt;
			cluster_cnt = temp->next->cluster_cnt;
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
	a->head->cluster_cnt = cluster_cnt;
	// if (sort_check != 0)
	// 	a->head->cluster_cnt = sort_check;
	insert_print_buf(print_buf, "rra");
}

void	ra(t_head *a, t_buf *print_buf)
{
	int		pull_data;
	int		sort_check;

	pull_data = 0;
	if (a->total_cnt == 1)
		return ;
	sort_check = 0;
	if (a->head->cluster_cnt == -1)
		sort_check = -1;
	pull_data = pull(a);
	list_add(a, pull_data, sort_check);
	insert_print_buf(print_buf, "ra");
}
