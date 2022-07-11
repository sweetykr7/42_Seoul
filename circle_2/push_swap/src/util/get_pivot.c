/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:47:40 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 17:40:28 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot_mid(t_head *a, int p)
{
	t_list	*temp;
	int		*sort;
	int		size;
	int		i;

	size = a->head->cluster_cnt;
	sort = int_loc(size);
	if (!sort)
		return (0);
	temp = a->head;
	i = 0;
	while (i < size && temp)
	{
		sort[i] = temp->data;
		temp = temp->next;
		i++;
	}
	sort = sort_arr(size, sort);
	p = sort[2];
	free(sort);
	return (p);
}

t_pivot	put_pivot_zero(t_pivot p)
{
	p.pivot1 = 0;
	p.pivot2 = 0;
	return (p);
}

t_pivot	get_pivot(t_head *a, t_pivot p)
{
	t_list	*temp;
	int		*sort;
	int		size;
	int		i;

	size = a->head->cluster_cnt;
	sort = int_loc(size);
	if (!sort)
		return (put_pivot_zero(p));
	temp = a->head;
	i = 0;
	while (i < size && temp)
	{
		sort[i] = temp->data;
		temp = temp->next;
		i++;
	}
	sort = sort_arr(size, sort);
	p.pivot1 = sort[(size / 3)];
	p.pivot2 = sort[((size * 2) / 3)];
	free(sort);
	return (p);
}
