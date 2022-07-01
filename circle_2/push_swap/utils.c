/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:18 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/01 16:45:42 by sooyokim         ###   ########.fr       */
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

int	check_asc_sort_a(t_head *a, int size)
{
	t_list	*temp;
	int		i;

	temp = a->head;
	i = size;
	while (i > 0 && temp)
	{
		if (temp->next)
		{
			if (temp->data > temp->next->data)
				return (0);
		}
		else
			break ;
		temp = temp->next;
		i--;
	}
	temp = a->head;
	i = size;
	while (i > 0 && temp)
	{
		temp->cluster_cnt = -1;
		temp = temp->next;
		i--;
	}
	return (1);
}

int	check_asc_sort_b(t_head *b, int size)
{
	t_list	*temp;
	int		i;

	temp = b->head;
	i = size;
	while (i > 0 && temp)
	{
		if (temp->next)
		{
			if (temp->data < temp->next->data)
				return (0);
		}
		else
			break ;
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


int	strsize(char *s)
{
	int	size;

	size = 0;
	while (*s != '\0')
	{
		size++;
		s++;
	}
	return (size);
}

void all_free(t_head *h)
{
	t_list	*temp;

	while (h->head)
	{
		if (h->head->next)
			temp = h->head->next;
		else
			temp = 0;
		free (h->head);
		h->head = temp;
	}
	h = 0;
	free(h);
}

void list_free(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		if (lst->next)
			temp = lst->next;
		else
			temp = 0;
		lst = 0;
		free (lst);
		if (temp)
			lst = temp;
	}
}
