/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:30:54 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/28 14:58:31 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct linked_list
{
	int					data;
	struct linked_list	*next;
}	t_list;

typedef struct list_head
{
	int					cnt;
	struct linked_list	*head;
}	t_head;

t_head	*new_head(void);
t_head	*list_add(t_head *head, int data);
t_head	*push(t_head *head_in, int data);
t_head	*pull(t_head *head_in, int *pull_data);
void	pa(t_head *a, t_head *b);

#endif