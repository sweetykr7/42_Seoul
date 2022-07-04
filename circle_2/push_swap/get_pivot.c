/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:47:40 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/04 19:10:33 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pivot	get_pivot(t_head *a)
{
	t_pivot	p;
	t_list	*temp;
	int		*sort;
	int		size;
	int		i;

	size = a->head->cluster_cnt;
	sort = int_loc(size, &p);
	if (!sort)
		return (p);
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
