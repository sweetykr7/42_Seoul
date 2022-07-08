/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:38:52 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/08 12:34:36 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_asc_sort_a_back_area(t_list *temp, int size)
{
	int		i;
	int		pre_flag;

	pre_flag = 0;
	i = 0;
	while (i < size && temp)
	{
		if (pre_flag == -1 && temp->cluster_cnt > 0)
			break ;
		temp->cluster_cnt = -1;
		pre_flag = temp->cluster_cnt;
		temp = temp->next;
		i++;
	}
}

int	check_asc_sort_a(t_head *a, int size)
{
	t_list	*temp;
	int		i;

	temp = a->head;
	i = 0;
	if (a->head->cluster_cnt == 1)
	{
		a->head->cluster_cnt = -1;
		return (1);
	}
	while (i < size)
	{
		if (temp->next)
			if (temp->data > temp->next->data)
				return (0);
		temp = temp->next;
		i++;
	}
	temp = a->head;
	check_asc_sort_a_back_area(temp, size);
	return (1);
}

int	check_desc_sort_b(t_head *b, int size)
{
	t_list	*temp;
	int		i;

	temp = b->head;
	i = size;
	while (i > 0 && temp && temp->next)
	{
		if (temp->next)
			if (temp->data < temp->next->data)
				return (0);
		temp = temp->next;
		i--;
	}
	temp = b->head;
	i = size;
	while (i > 0 && temp)
	{
		temp->cluster_cnt = -1;
		temp = temp->next;
		i--;
	}
	return (1);
}

int	check_sort_a(t_head *a)
{
	t_list	*temp;
	int		flag;

	temp = a->head;
	flag = 0;
	if (a->head->cluster_cnt == -1)
		flag = -1;
	while (temp)
	{
		if (temp->cluster_cnt != -1)
		{
			if (flag == -1)
				return (2);
			else
				return (0);
		}
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	return (1);
}
