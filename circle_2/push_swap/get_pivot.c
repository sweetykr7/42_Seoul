/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joey <joey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:47:40 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/07 16:51:58 by joey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pivot	*get_pivot(t_head *a, t_pivot *p)
{
	t_list	*temp;
	int		*sort;
	int		size;
	int		i;



	size = a->head->cluster_cnt;
	//printf("test get_pivot1\n");
	sort = int_loc(size);
	//printf("test get_pivot2\n");
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
	p->pivot1 = sort[(size / 3)];
	p->pivot2 = sort[((size * 2) / 3)];
	free(sort);
	return (p);
}
