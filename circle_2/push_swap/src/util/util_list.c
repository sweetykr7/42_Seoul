/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:39:29 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/08 15:13:37 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head	*new_head(void)
{
	t_head	*new;

	new = (t_head *)malloc(sizeof(t_head));
	if (!new)
		return (0);
	new->total_cnt = 0;
	new->head = 0;
	return (new);
}

t_head	*list_add(t_head *head, int data, int sort_check, int *error)
{
	t_list	*add_list;
	t_list	*temp;

	if (*error == 1 || !find_word_in_list(head->head, data, error))
		return (0);
	add_list = (t_list *)malloc(sizeof(t_list));
	if (!add_list)
		return (0);
	add_list->next = 0;
	if (sort_check == -1)
		add_list->cluster_cnt = -1;
	else
		add_list->cluster_cnt = 0;
	add_list->data = data;
	if (head->total_cnt == 0)
		head->head = add_list;
	else
	{
		temp = head->head;
		while (temp->next)
			temp = temp->next;
		temp->next = add_list;
	}	
	head->total_cnt = head->total_cnt + 1;
	return (head);
}

void	push_stack(t_head *a, t_list *list)
{
	if (a->head)
	{
		list->next = a->head;
		a->head = list;
	}
	else
		a->head = list;
	a->total_cnt++;
}

t_list	*pull_stack(t_head *a)
{
	t_list	*temp;

	if (a->total_cnt == 0)
		temp = NULL;
	else if (a->total_cnt == 1)
	{
		temp = a->head;
		a->head = NULL;
	}
	else
	{
		temp = a->head;
		a->head = temp->next;
		temp->next = NULL;
	}
	a->total_cnt--;
	return (temp);
}

int	lst_last_data(t_list *lst)
{
	int		last_data;
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		last_data = temp->data;
		if (temp->next)
			temp = temp->next;
		else
			break ;
	}
	return (last_data);
}
