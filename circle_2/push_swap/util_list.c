/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:39:29 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/02 12:20:41 by sooyokim         ###   ########.fr       */
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

void	push(t_head *head_in, int data)
{
	t_list	*add_list;
	t_list	*temp;

	if (head_in->total_cnt == 0)
	{
		if (!list_add(head_in, data, 0))
			return ;
	}
	else
	{
		add_list = (t_list *)malloc(sizeof(t_list));
		if (!add_list)
			return ;
		temp = head_in->head;
		add_list->data = data;
		head_in->head = add_list;
		add_list->next = temp;
		head_in->total_cnt = head_in->total_cnt + 1;
	}
}

void	pull(t_head *head_in, int *pull_data)
{
	t_list	*temp;
	t_list	*temp2;

	if (head_in->total_cnt == 0)
		return ;
	if (head_in->head->next)
		temp = head_in->head->next;
	else
		temp = 0;
	*pull_data = head_in->head->data;
	temp2 = head_in->head;
	head_in->head = temp;
	free(temp2);
	head_in->total_cnt = head_in->total_cnt - 1;
}
