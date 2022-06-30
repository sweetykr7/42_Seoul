/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:39:29 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/30 10:54:15 by sooyokim         ###   ########.fr       */
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

t_head	*list_add(t_head *head, int data)
{
	t_list	*add_list;
	t_list	*temp;

	add_list = (t_list *)malloc(sizeof(t_list));
	if (!add_list)
		return (0);
	add_list->next = 0;
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

t_head	*push(t_head *head_in, int data)
{
	t_list	*add_list;
	t_list	*temp;

	if (head_in->total_cnt == 0)
	{
		if (!list_add(head_in, data))
			return (0);
	}
	else
	{
		add_list = (t_list *)malloc(sizeof(t_list));
		if (!add_list)
			return (0);
		temp = head_in->head;
		add_list->data = data;
		head_in->head = add_list;
		add_list->next = temp;
		head_in->total_cnt = head_in->total_cnt + 1;
	}
	return (head_in);
}

t_head	*pull(t_head *head_in, int *pull_data)
{
	t_list	*temp;

	if (head_in->total_cnt == 0)
		return (0);
	temp = head_in->head->next;
	*pull_data = head_in->head->data;
	free(head_in->head);
	head_in->head = temp;
	head_in->total_cnt = head_in->total_cnt - 1;
	return (head_in);
}
