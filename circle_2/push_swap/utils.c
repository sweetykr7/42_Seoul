/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:18 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/30 11:30:44 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*int_loc(int size, t_pivot *pivot)
{
	int	*p;
	int	i;

	p = (int *)malloc(sizeof(int) * size);
	if (!p)
	{	
		pivot->pivot1 = 0;
		pivot->pivot2 = 0;
		return (0);
	}
	i = size;
	while (i > 0)
	{
		p[i] = 0;
		i--;
	}
	return (p);
}

int	*sort_arr(int size, int *sort)
{
	int	i;
	int	j;
	int	sort_temp;

	i = 0;
	j = 0;
	sort_temp = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (sort[i] > sort[j])
			{
				sort_temp = sort[i];
				sort[i] = sort[j];
				sort[j] = sort_temp;
			}	
			j++;
		}
		i++;
		j = i;
	}
	return (sort);
}
