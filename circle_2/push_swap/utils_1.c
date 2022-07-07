/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:18 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/07 12:49:36 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*int_loc(int size)
{
	int	*p;
	int	i;

	// printf("int_loc pivot1 check : %d\n", pivot->pivot1);
	// printf("int_loc pivot2 check : %d\n", pivot->pivot2);
	// printf("int_loc size check : %d\n", size);
	// printf("int_loc test check============\n");
	p = (int *)malloc(sizeof(int) * size);
	if (!p)
		return (0);
	i = size;
	// printf("int_loc pass test============\n");
	while (i > 0)
	{
		p[i] = 0;
		i--;
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
