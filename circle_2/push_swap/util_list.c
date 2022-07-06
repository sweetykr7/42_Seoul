/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:39:29 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/06 15:30:58 by sooyokim         ###   ########.fr       */
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

t_head	*list_add(t_head *head, int data, int sort_check)
{
	t_list	*add_list;
	t_list	*temp;

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
	t_list	*temp;

	if (a->head)
		temp = a->head;
	else
		temp = 0;
	a->head = list;
	a->head->next = temp;
	a->total_cnt = a->total_cnt + 1;
}

t_list	*pull_stack(t_head *a)
{
	t_list	*temp;

	if (a->total_cnt == 0)
		return (0);
	temp = a->head;
	if (a->head->next)
		a->head = a->head->next;
	else
		a->head = 0;
	temp->next = 0;
	a->total_cnt = a->total_cnt - 1;
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
