/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:18 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/07 19:54:32 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*int_loc(int size)
{
	int	*p;
	int	i;

	p = (int *)malloc(sizeof(int) * size);
	if (!p)
		return (0);
	i = 0;
	while (i < size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
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

void	all_free(t_head *h)
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

void	list_free(t_list *lst)
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

int	lstsize(t_list *lst)
{
	int		len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
